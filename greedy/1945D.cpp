/*
  
  仔细想想没到达目标点时 只要选择 min(ai, bi)即可

  https://codeforces.com/contest/1945/problem/D

*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
   int n, m;
   cin >> n >> m;
   vector<int>a(n);
   vector<int>b(n);
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }
   for (int i = 0; i < n; i++) {
      cin >> b[i];
   }
   m--;
   ll ans = 1e18;
   ll s = 0;
   for (int i = n - 1; i >= 0; i--) {
      if (i <= m) {
         ans = min(ans, s + a[i]);
      }
      s += min(a[i], b[i]);
   }
   cout << ans << "\n";
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
