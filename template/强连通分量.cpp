#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int inf = 1e9;
constexpr int N = 2e5 + 10;
vector<vector<int>>adj;
int dfn[N], low[N], tot;
vector<int>stk;
int inst[N];
int scc[N], siz[N], cnt;
int root;
void tarjan(int x) {
    dfn[x] = low[x] = ++tot;
    stk.push_back(x);
    inst[x] = 1;
    for (auto y : adj[x]) {
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);

        }
        else if (inst[y]) {
            low[x] = min(low[x], dfn[y]);
        }
    }
    if (dfn[x] == low[x]) {//若x为scc的根节点
        int y; ++cnt;
        do {
            y = stk.back();
            stk.pop_back();
            inst[y] = 0;
            scc[y] = cnt;//scc编号
            ++siz[cnt];//scc大小
        } while (y != x);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    stk.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (siz[i] > 1)++ans;
    }
    cout << ans << "\n";
    return 0;
}
