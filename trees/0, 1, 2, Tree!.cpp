/*

  https://codeforces.com/contest/1950/problem/F
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
   int a, b, c;
   cin >> a >> b >> c;
   if (c != a + 1) {
      cout << -1 << "\n";
      return;
   }
   int d = -1;
   for (int i = 1;; i <<= 1) {
      d += 1;
      if (i <= a) {
         a -= i;
      }
      else {
         if (a==0) {
            d--;
         }
         if (a) {
            b -= i - a;
         }
         int len = a * 2 + i - a;
         b = max(0, b);
         int u = 0;
         if (b || c) {
            u = 1;
         }
         cout << u + d + (b + len - 1) / len << "\n";
         return;
      }
   }
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
