/*
  分类讨论
  奇数 As必赢
  偶数
  将n分解质因数后
  2^c2....p^cnt
  if c2==1  cnt>1  As可以除以（cnt-1） 这样无论F怎么操作都赢不了
            cnt<=1 As无论-1 还是除以cnt F必赢
  else c2 > 1
       cnt==0 F必赢
       else  A必赢
 https://codeforces.com/contest/1370/problem/C
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "FastestFinger" << "\n";
        return;
    }
    if (n % 2) {
        cout << "Ashishgup" << "\n";
    }
    else {
        if (n == 2) {
            cout << "Ashishgup" << "\n";
        }
        else {
            int cnt = 0;
            int c2 = 0;
            for (int i = 2; 1LL * i * i <= n; i++) {
                if (n % i == 0) {

                    while (n % i == 0) {
                        n /= i;
                        if (i != 2) {
                            cnt++;
                        }
                        else c2++;
                    }
                }
            }
            if (n > 1)cnt++;
            if (cnt) {
                if (c2 == 1) {
                    if (cnt > 1) {
                        cout << "Ashishgup" << "\n";
                    }
                    else {
                        cout << "FastestFinger" << "\n";
                    }
                }
                else {
                    if (cnt == 0) {
                        cout << "FastestFinger" << "\n";
                    }
                    else {
                        cout << "Ashishgup" << "\n";
                    }
                }
            }
            else {
                cout << "FastestFinger" << "\n";
            }
        }
    }
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
