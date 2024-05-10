/*
  https://acm.webturing.com/problem.php?cid=1816&pid=5&langmask=262133&puzzle_mask=0
  先用最短路处理每个点到终点最小花费时间
  之后在用dfs寻找所有路径
  
  https://acm.webturing.com/problem.php?cid=1816&pid=5&langmask=262133&puzzle_mask=0

*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int inf = 1e9;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    while (cin >> n >> m) {
        vector<vector<int>>a(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        // queue<array<int, 3>>q;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>>q0;
        q0.push({ 0, {n - 1, m - 1} });
        vector<vector<int>>d(n, vector<int>(m, inf));
        vector<vector<int>>vis0(n, vector<int>(m));
        d[n - 1][m - 1] = 0;
        vis0[n - 1][m - 1] = 0;
        while (q0.size()) {
            auto t = q0.top();
            int s = t.first;
            auto [x, y] = t.second;
            q0.pop();
            if (vis0[x][y])continue;
            vis0[x][y] = 1;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis0[nx][ny])continue;
                if (d[nx][ny] > a[nx][ny] + d[x][y]) {
                    d[nx][ny] = a[nx][ny] + d[x][y];
                    q0.push({ d[nx][ny],{nx, ny} });
                }
            }
        }
        vector<vector<int>>vis(n, vector<int>(m));
        q.emplace(0, 0);
        vis[0][0] = 1;
        int cnt = 0;
        auto dfs = [&](auto self, int x, int y) {

            if (x == n - 1 && y == m - 1) {
                cnt++;
                return;
            }
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny])continue;
                if (d[nx][ny] >= d[x][y])continue;
                vis[nx][ny] = 1;
                self(self, nx, ny);
                vis[nx][ny] = 0;
            }
            };
        dfs(dfs, 0, 0);
        cout << cnt << "\n";
    }

    return 0;
}
