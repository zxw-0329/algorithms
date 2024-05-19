/*


*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int inf = 1e9;
constexpr int N = 1e5 + 10;
vector<vector<int>>adj(N);
int dfn[N], low[N];
int cnt, root;
vector<pair<int, int>>ans;
int cnt_bridge;
void tarjan(int x, int f) {
    dfn[x] = low[x] = ++cnt;
    int child = 0;
    for (auto y : adj[x]) {
        if (!dfn[y]) {
            child++;
            tarjan(y, x);
            low[x] = min(low[y], low[x]);
            if (low[y] > dfn[x]) {
                ans.push_back({ x,y });
                ++cnt_bridge;
            }
        }
        else if (dfn[y] < dfn[x] && y != f) {
            low[x] = min(low[x], dfn[y]);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    // for (int i = 0; i < m; i++) {
    //     int x, y;
    //     cin >> x >> y;
    //     adj[x].push_back(y);
    //     adj[y].push_back(x);

    // }
    // for (int i = 1; i <= n; i++) {
    //     if (!dfn[i]) {
    //         tarjan(i, 0);
    //     }
    // }
    // sort(ans.begin(), ans.end());
    // for (auto [x, y] : ans) {
    //     cout << x << " " << y << "\n";
    // }

    return 0;
}
