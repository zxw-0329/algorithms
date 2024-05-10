/*
  两次dj算法；
  第一次求出发点到各个点最小距离
  第二次求终点到各个点的最小距离
  之后在求 从出发点到最远所用的时间，之后求当出发点到达最远点时，其他点到终点的 距离

  aoj  1497
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int inf = 1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>>e[n];
        for (int i = 0; i < m; i++) {
            int x, y, w;
            cin >> x >> y >> w;
            e[x].push_back({ y,w });
            e[y].push_back({ x,w });
        }
        auto dijkstra = [&](int s,vector<int>&d) {
            vector<int>vis(n);
            d[s] = 0;
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>q;
            q.push({ 0,s });
            while (q.size()) {
                auto u = q.top().second;
                q.pop();
                if (vis[u])continue;
                vis[u] = 1;
                for (auto ed : e[u]) {
                    int v = ed.first, w = ed.second;
                    if (d[v] > d[u] + w) {
                        d[v] = d[u] + w;
                        q.push({ d[v],v });
                    }
                }
            }
            };
        int a, b;
        cin >> a >> b;
        vector<int>d0(n, inf);
        dijkstra(a, d0);
        vector<int>d1(n, inf);
        dijkstra(b, d1);
        int m0 = -1;
        int j = -1;
        for (int i = 0; i < n; i++) {
            if (i != a) {
                if (d0[i] > m0) {
                    m0 = d0[i];
                    j = i;
                }
            }
        }
        int ans = 0;
        ans += m0;
        for (int i = 0; i < n; i++) {
            if (i != b && i != j) {
                d1[i] = max(d1[i] - m0, 0);
            }
        }
        ans += *max_element(d1.begin(), d1.end());
        cout << ans << "\n";
    }
    return 0;
}
