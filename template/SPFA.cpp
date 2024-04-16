/*
  很多时候我们并不需要那么多无用的松弛操作。

  很显然，只有上一次被松弛的结点，所连接的边，才有可能引起下一次的松弛操作。

  那么我们用队列来维护「哪些结点可能会引起松弛操作」，就能只访问必要的边了。

  SPFA 也可以用于判断 s 点是否能抵达一个负环，只需记录最短路经过了多少条边，当经过了至少 n 条边时，说明 s 点可以抵达一个负环。


  https://www.luogu.com.cn/problem/P3385
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
        vector<pair<int, int>>e[n + 1];
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            e[a].push_back({ b,c });
            if (c >= 0) {
                e[b].push_back({ a,c });
            }
        }
        queue<int>q;
        vector<int>vis(n + 1);//记录是否在队内
        vector<int>cnt(n + 1);//记录边数,判负环
        vector<int>d(n + 1, inf);//源点到其余点的最小距离
        auto spfa = [&](int s)->bool {
            q.push(s);
            d[s] = 0;
            vis[s] = 1;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                vis[u] = 0;
                for (auto ed : e[u]) {
                    int v = ed.first, w = ed.second;
                    if (d[v] > d[u] + w) {
                        d[v] = d[u] + w;
                        cnt[v] = cnt[u] + 1;// 记录最短路经过的边数
                        if (cnt[v] >= n) {
                            return false;
                        }
                        // 在不经过负环的情况下，最短路至多经过 n - 1 条边
                        // 因此如果经过了多于 n 条边，一定说明经过了负环alse;
                        if (!vis[v]) {
                            q.push(v);
                            vis[v] = 1;
                        }
                    }
                }
            }
            return true;
            };
        if (!spfa(1)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }


    return 0;
}
