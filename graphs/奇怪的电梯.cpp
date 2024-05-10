/*
  用题目所给定的信息建图
  因为路径长度都为1
  直接用bfs寻找到终点最小次数
  aoj 1466
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, a, b;
    while (cin >> n >> a >> b && n != 0) {
        vector<int>e[n + 1];
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (i + x <= n) {
                e[i].push_back(i + x);
            }
            if (i - x >= 1) {
                e[i].push_back(i - x);
            }
        }
        queue<pair<int, int>>q;
        vector<int>vis(n + 1);
        q.emplace(a, 0);
        vis[a] = 1;
        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();
            if (x == b) {
                cout << y << "\n";
                return 0;
            }
            for (auto v : e[x]) {
                if (vis[v])continue;
                q.emplace(v, y + 1);
                vis[v] = 1;
            }
        }
        cout << -1 << "\n";
    }
 
    return 0;
}
