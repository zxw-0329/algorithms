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

//jly板子
/*


bel：记录每个节点所属的强连通分量编号的数组。 
cur和cnt：用于计数的变量，cur用于递增标记访问顺序，cnt用于强连通分量的计数

*/   
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int inf = 1e9;
constexpr int N = 2e5 + 10;
struct SCC {
    int n;
    std::vector<std::vector<int>> adj;
    std::vector<int> stk;
    std::vector<int> dfn, low, bel;
    int cur, cnt;

    SCC() { }
    SCC(int n) {
        init(n);
    }

    void init(int n) {
        this->n = n;
        adj.assign(n, {});
        dfn.assign(n, -1);
        low.resize(n);
        bel.assign(n, -1);
        stk.clear();
        cur = cnt = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void dfs(int x) {
        dfn[x] = low[x] = cur++;
        stk.push_back(x);

        for (auto y : adj[x]) {
            if (dfn[y] == -1) {
                dfs(y);
                low[x] = std::min(low[x], low[y]);
            }
            else if (bel[y] == -1) {
                low[x] = std::min(low[x], dfn[y]);
            }
        }

        if (dfn[x] == low[x]) {
            int y;
            do {
                y = stk.back();
                bel[y] = cnt;
                stk.pop_back();
            } while (y != x);
            cnt++;
        }
    }

    std::vector<int> work() {
        for (int i = 0; i < n; i++) {
            if (dfn[i] == -1) {
                dfs(i);
            }
        }
        return bel;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    SCC a(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        a.addEdge(x, y);
    }
    a.work();

    int ans = 0;
    map<int, int>ma;
    for (int i = 0; i < a.bel.size(); i++) {
        ma[a.bel[i]]++;
    }
    for (auto [x, y] : ma) {
        ans += y > 1;
    }
    cout << ans << "\n";
    return 0;
}
