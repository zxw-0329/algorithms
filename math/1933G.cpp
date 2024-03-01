/* 注意观察样例;
  打表找规律 (n=5时 发现最多8种)
  摆放为
  0123 0123
  0011 0011。。。。
  1100 1100。。。。
  0011 0011。。。。
  横着4种 同理竖着4种;
  检查8种位置是否合法 输出答案;
  
  https://codeforces.com/contest/1933/problem/G
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool check(int x, int y, int t) {
    if (t >= 4) {    //竖变横
        return check(y, x, t - 4);
    }
    y += t;
    if (x & 1) { // 返回当前位置是否为0        00110011   <- x为偶数
        return y % 4 == 0 || y % 4 == 1;  // 11001100   <- x为奇数
    }                                     //   23
    return y % 4 == 2 || y % 4 == 3;
}
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    int ok[8];
    for (int i = 0; i < 8; i++) {
        ok[i] = 0;//0 表示合法
    }
    cout << 8 << "\n";
    while (q--) {
        int x, y;
        string shape; //假设 0为"circle"  1为"square";
        cin >> x >> y >> shape;
        x--, y--;
        for (int i = 0; i < 8; i++) {     //0
            if (check(x,y,i) != (shape == "circle")) {  //只要不相等 第i个 位置就不合法 标记为1;
                ok[i] = 1;
            }
        }
        cout << count(ok, ok + 8, 0) << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // const int n = 5;
    // int a[n][n];
    // auto dfs = [&](auto self, int x, int y) {
    //     if (x == n) {
    //         for (int i = 0; i < n; i++) {
    //             for (int j = 0; j < n; j++) {
    //                 cerr << a[i][j];
    //             }
    //             cerr << "\n";
    //         }
    //         cerr << "--\n";
    //         return;
    //     }
    //     if (y == n) {
    //         return self(self, x + 1, 0);
    //     }
    //     for (int t = 0; t < 2; t++) {
    //         a[x][y] = t;
    //         if (x >= 2 && a[x][y] == a[x - 1][y] && a[x][y] == a[x - 2][y]) {
    //             continue;
    //         }
    //         if (y >= 2 && a[x][y] == a[x][y - 1] && a[x][y] == a[x][y - 2]) {
    //             continue;
    //         }
    //         if (x >= 2 && y >= 2 && a[x][y] == a[x - 1][y - 1] && a[x][y] == a[x - 2][y - 2]) {
    //             continue;
    //         }
    //         if (x >= 2 && y + 2 < n && a[x][y] == a[x - 1][y + 1] && a[x][y]==a[x - 2][y + 2]) {
    //             continue;
    //         }
    //         self(self, x, y + 1);
    //     } 
    // };
    // dfs(dfs, 0, 0);

    // return 0;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
