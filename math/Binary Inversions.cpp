/*
  贪心+数学  （一眼）

  https://codeforces.com/contest/1760/problem/E
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
   int n;
   cin >> n;
   vector<int>a(n);
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }
   int one = 0;
   ll ans = 0;
   int f0 = -1;
   int l1 = -1;
   for (int i = 0; i < n; i++) {
      if (a[i] == 1) {
         one++;
         l1 = i;
      }
      else {
         if (f0 == -1) {
            f0 = i;
         }
         ans += one;
      }
   }
   ll s = ans;
   if (f0 != -1) {
      int t1 = count(a.begin(), a.begin() + f0, 1);
      int t0 = count(a.begin() + f0 + 1, a.end(), 0);
      ans = max(ans, s - t1 + t0);
   }

   if (l1 != -1) {
      int t2 = count(a.begin(), a.begin() + l1, 1);
      int t3 = count(a.begin() + l1 + 1, a.end(), 0);
      ans = max(ans, s + t2 - t3);
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
