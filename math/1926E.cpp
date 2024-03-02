/*
  1. 1 3 5 7 9 11 。。。
  2. 2 6 10 14 18 22 。。。。(拿掉奇数*2);
  3.发现奇数*3 要么在1中,要么在2中
  4. 4 12 20 28 36 44 。。。。。
  5.同理根据3可知

  总结被拿出来的满足 i*(2*x-1)  (i>=1&& i*=2);
  统计每一个倍数有多少数 <=n 即 i*(2*x-1)<=n --> x = (n / i + 1) / 2; 
  if(x<k)k-=x;
  else 计算 -> i*(2*k-i);  即为答案

  https://codeforces.com/contest/1926/problem/E
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    ll n, k;
    cin >> n >> k;
    ll cnt = 1;
    ll m = (n / cnt + 1) / 2;
    while (m < k) {
        cnt *= 2;
        ll y = (n / cnt + 1) / 2;
         m += y;
    }
     
    ll t = (n / cnt + 1) / 2;
    if (m == k) {
        cout << cnt * (2 * t - 1) << "\n";
    }
    else {
        m -= t;
        k -= m;
        cout << cnt * (2 * k - 1) << "\n";
    }
    // ll s = 0;
    // for (ll i = 1;; i *= 2) {
    //     // (2*x-1)*i<=n
    //     //  x=(n/i+1)/2;
    //     ll x = (n / i + 1) / 2;
    //     s += x;
    //     if (x < k) {
    //         k -= x;
    //     }
    //     else {
    //        // cout << i * (2 * k - 1) << "\n";
    //         break;
    //     }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
     cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
