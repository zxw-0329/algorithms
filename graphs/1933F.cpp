/*
思路：化动为静（已石头为参照物）--> 每秒机器往下走一步（终点也会移动）;
      往上走时,在最后一列最优,（如果不在最后一列往上走,相当于原地不动);
      往右走,相当于 当前位置 走到右下;
      往下走,相当于 当前位置 往下走两格;

      用bfs 找最短路  --> 往下走两格和往右下走;
      走到最后一列时，判断 当前前行与终点行的距离 +vis[x][y](到达x,y最短时间) 取min
      
      https://codeforces.com/contest/1933/problem/F
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n, m;
    cin >> n >> m;
    vector a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    queue<pair<int, int>>q;
    q.emplace(0, 0);
    vector vis(n, vector<int>(m, -1));
    vis[0][0] = 0;
    int ans = 1e9;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (y == m - 1) {
            ans = min(ans, vis[x][y]+(x+1-vis[x][y]%n+n)%n);//当前行-终点行(注意正负);
        }
        if (y<m-1&&a[(x + 1) % n][y + 1] == 0 && vis[(x + 1) % n][y + 1] == -1) {
            vis[(x + 1) % n][y + 1] = vis[x][y] + 1;
            q.emplace((x + 1) % n, y + 1);
        }
        if (a[(x + 1) % n][y] == 0 && a[(x + 2) % n][y] == 0 && vis[(x + 2) % n][y] == -1) {
            vis[(x + 2) % n][y] = vis[x][y] + 1;
            q.emplace((x + 2) % n, y);
        }
    }
    if (ans == 1e9) {
        cout << "-1\n";
        return;
    }
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
