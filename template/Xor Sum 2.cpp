#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 5000011;
void solve() {
   int n;
   cin >> n;
   vector<int>a(n);
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }
   ll ans = 0;
   int s1 = 0, s2 = 0;
   // for (int i = 0, j = 0; i < n; i++) {
   //    while (j < n && (s1 + a[j]) == (s2 ^ a[j])) {
   //       s1 += a[j];
   //       s2 ^= a[j];
   //       j++;
   //    }
   //    //cerr << j << " ";
   //    ans += j - i;
   //    s1 -= a[i];
   //    s2 ^= a[i];
   // }
   // cout << ans << "\n";
   for (int i = 0, j = 0; i < n; i++) {
      s1 += a[i];
      s2 ^= a[i];
      while (s1 != s2) {
         s1 -= a[j];
         s2 ^= a[j];
         j++;
      }
      ans += i - j + 1;
   }
   cout << ans << "\n";
}
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int t = 1;
   //cin >> t;
   while (t--) {
      solve();
   }
   return 0;
}
