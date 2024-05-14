/*
 •考虑倒序遍历，相当于每次添加一条边。每次添加一条边，森林的直径答案有以下情况：
 1没加这条边时森林的直径。
 2 A所在的树的直径。
 3 B所在的树的直。
 4 A和 B所相连后形成的树的直径。
 •定义 f (i)为第 i次查询的答案，开两个数组来标记每个树集合的直径所对应的端点 l和 r
 •对于情况 1，答案为 f (i + 1)
 •对于情况 2，答案为 A 所在树集合对应端点的距离，就是 A树的直径。
 •对于情况 3，答案为 B所在树集合对应端点的距离，就是 B树的直径。
 •对于情况 4，如果第一棵树直径两端点为 (u,v)，第二棵树直径两端点为 (x,y)，用一条边将两棵树连接，那么新树的直径一定是 u,v,x,y中的两个点所以只需要两两取点求距离取最大值就是直径。

 并查集 + LCA + 正向删边（逆向加边）
 https://ac.nowcoder.com/acm/contest/81509/F
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int inf = 1e9;
constexpr int N = 1e5 + 10;
int fa[N][22];
int dep[N];
vector<vector<int>>adj;
vector<int>f;
void dfs(int cur, int father) {
    dep[cur] = dep[father] + 1;
    fa[cur][0] = father;
    for (int i = 1; i <= 20; i++) {
        fa[cur][i] = fa[fa[cur][i - 1]][i - 1];
    }
    for (auto v : adj[cur]) {
        if (v == father)continue;
        dfs(v, cur);
    }
}
int LCA(int u, int v) {
    if (dep[u] < dep[v])swap(u, v);
    for (int i = 20; i >= 0; i--) {
        if (dep[fa[u][i]] >= dep[v]) {
            u = fa[u][i];
        }
    }
    if (u == v) {
        return u;
    }
    for (int i = 20; i >= 0; i--) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}
int getDis(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[LCA(u, v)];
}
int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    adj.resize(n + 1);
    f.resize(n + 1);
    vector<int>l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++) {
        f[i] = i; l[i] = i, r[i] = i;
    }
    vector<pair<int, int>>a(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = { x,y };
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);
    vector<int>ans(n);
    ans[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        int u = find(a[i].first), v = find(a[i].second);
        //cerr << u << " " << v << "\n";
        int L = 0, R = 0;
        f[u] = v;//u的根节点指向v
        int dis = 0;
        int mx = -1;                 //直径端点分类讨论
        dis = getDis(l[u], r[u]);//只在集合u里面
        if (dis > mx) {
            mx = dis;L = l[u], R = r[u];
        }
        dis = getDis(l[u], l[v]);//u集合的左端点，v集合的左端点
        if (dis > mx) {
            mx = dis;L = l[u], R = l[v];
        }
        dis = getDis(l[u], r[v]);//u集合的左端点，v集合的右端点
        if (dis > mx) {
            mx = dis;L = l[u], R = r[v];
        }
        dis = getDis(r[u], l[v]);//u集合的右端点，v集合的左端点
        if (dis > mx) {
            mx = dis;
            L = r[u], R = l[v];
        }
        dis = getDis(r[u], r[v]);//u集合的右端点，v集合的右端点
        if (dis > mx) {
            mx = dis;L = r[u], R = r[v];
        }
        dis = getDis(l[v], r[v]);//v集合的左端点，v集合的右端点
        if (dis > mx) {
            mx = dis;
            L = l[v], R = r[v];
        }
        //cerr << L << " " << R << "\n";
        l[v] = L, r[v] = R;//以v为集合的树最大直径的左右端点
        ans[i] = max(ans[i + 1], mx);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}
