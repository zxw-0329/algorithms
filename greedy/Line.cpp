/*

   思路:对于小于 n/2的位置往右看最优  大于n/2的位置往左看最优 (当n为奇数时处于中间位置的往哪看都一样)
   因为要求和最大 不能先单独处理某一端 要两端一起处理;
   
   https://codeforces.com/contest/1722/problem/D
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
   int n;
   cin >> n;
   string s;
   cin >> s;
   int L;
   ll ans = 0;
   for (int i = 0; i < n; i++) {
      if (s[i] == 'L') {
         ans += i;
      }
      else {
         ans += n - i - 1;
      }
   }
   int k = n;
   for (int i = 0; i < n / 2; i++) {
      if (s[i] == 'L') {
         ans -= i;
         ans += n - 1 - i;
         cout << ans << " ";
         k--;
      }
      if (s[n - 1 - i] == 'R') {
         ans -= i;
         ans += n - 1 - i;
         cout << ans << " ";
         k--;
      }
   }
   while (k--) {
      cout << ans << " ";
   }
   cout << "\n";
  /*
    i64 ans = 0;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            ans += i;
            a[i] += n - 1 - i - i;
        } else {
            ans += n - 1 - i;
            a[i] += i - (n - 1 - i);
        }
    }
    
    std::sort(a.begin(), a.end(), std::greater());
    for (int i = 0; i < n; i++) {
        ans += std::max(0, a[i]);
        std::cout << ans << " \n"[i == n - 1];
    }

    */
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


