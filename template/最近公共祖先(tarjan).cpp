#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, s;
    cin >> n >> m >> s;
    vector<int>e[n + 1];//存边
    vector<pair<int, int>>query[n + 1];//存查询
    vector<int>ans(m);//存答案

    vector<int>fa(n + 1);//存父节点
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    vector<int>vis(n + 1);//打标记，是否访问过
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        query[a].push_back({ b,i });
        query[b].push_back({ a,i });
    }
    function<int(int)>find = [&](int x)->int {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
        };
    
    function<void(int)>tarjan = [&](int cur) {
        vis[cur] = 1;
        for (auto v : e[cur]) {
            if (!vis[v]) {
                tarjan(v);
                fa[v] = cur;
            }
        }
        for (auto q : query[cur]) {
            int v = q.first, i = q.second;
            if (vis[v])ans[i] = find(v);
        }
        };
    
    tarjan(s);

    for (int i = 0; i < m; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}
