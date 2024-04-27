/*


*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int mod = 1e9 + 7;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int n, t;
   ll a, b;
   cin >> n >> t >> a >> b;
   vector<int>k(n + 1);
   for (int i = 1; i <= n; i++) {
      cin >> k[i];
   }
   vector<ll>s(n + 1);
   for (int i = 1; i <= n; i++) {
      s[i] = s[i - 1] + k[i];
   }
   ll ans = 0;
   for (int i = 0; i < n; i++) {
      int p = t - (i) * 1LL * b;
      int y = p / a;
      int x = min(i + y - 1, n - 1);
      if (x >= i) {
         ans = max(ans, s[x + 1] - s[i]);
      }
      else break;
   }
   cout << ans << "\n";
   return 0;
}
