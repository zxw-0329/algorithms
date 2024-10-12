/*

  https://ac.nowcoder.com/acm/contest/91355/D
*/
#include<bits/stdc++.h>

using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr i64 inf = 1e15;
void solve() {

    int n, m, k;
    cin >> n >> m >> k;

    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>>adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<i64>>d(n, vector<i64>(k + 1, inf));
    //用 dp[i][j] 表示走到 i，有 j 天没有休息的最短时间
    vector<vector<int>>vis(n, vector<int>(k + 1));
    priority_queue<array<i64, 3>, vector<array<i64, 3>>, greater<>>q;
    //最短时间 当前点 有j天没休息
    d[0][0] = a[0];
    q.push({ a[0],0,0 });//休息
    if (k != 0) {//不休息
        d[0][1] = 1;
        q.push({ 1, 0, 1 });
    }
    while (q.size()) {

        auto [w, i, j] = q.top();
        q.pop();

        if (vis[i][j] == 1) {
            continue;
        }
        vis[i][j] = 1;

        for (auto x : adj[i]) {

            if (d[x][0] > a[x] + w) {//休息
                d[x][0] = a[x] + w;
                q.push({ d[x][0],x,0 });
            }
            if (j + 1 <= k && d[x][j + 1] > w + 1) {//不休息
                d[x][j + 1] = w + 1;
                q.push({ d[x][j + 1],x,j + 1 });
            }
        }
    }
    i64 ans = inf;
    for (int i = 0; i <= k; i++) {
        ans = min(ans, d[n - 1][i]);
    }
    cout << ans << "\n";
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    cout << fixed << setprecision(12);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
