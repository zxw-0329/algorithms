/*
  二维前缀和 观察数据c最多为10 之后统计每个坐标点各有多少亮度的星即可
  
  https://codeforces.com/contest/835/problem/C
*/
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 100;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, q, c;
    cin >> n >> q >> c;

    vector<vector<vector<int>>>s(N + 5, vector<vector<int>>(N + 5, vector<int>(c + 1, 0)));
    for (int i = 0; i < n; i++) {
        int x, y, s1;
        cin >> x >> y >> s1;
        s[x][y][s1]++;
    }

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k <= c; k++) {
                s[i + 1][j + 1][k] += s[i + 1][j][k] + s[i][j + 1][k] - s[i][j][k];
            }
        }
    }

    while (q--) {

        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        x1--, y1--;
        int ans = 0;
        for (int k = 0; k <= c; k++) {
            int u = s[x2][y2][k] - s[x2][y1][k] - s[x1][y2][k] + s[x1][y1][k];
            ans += ((k + t) % (c + 1)) * u;
        }//cerr << "\n";
        cout << ans << "\n";
    }
    return 0;
}
