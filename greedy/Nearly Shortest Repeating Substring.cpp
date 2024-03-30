/*

  https://codeforces.com/contest/1950/problem/E
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
   int n;
   cin >> n;
   string s;
   cin >> s;
   for (int len = 1; len <= n; len++) {
      if (n % len != 0)continue;
      string pre = s.substr(0, len);
      string last = s.substr(n - len, len);
      int p = 0, l = 0;
      for (int j = 0; j < n; j++) {
         if (s[j] != pre[j % len]) {
            p++;
         }
         if (s[j] != last[j % len]) {
            l++;
         }
      }
      if (l <= 1 || p <= 1) {
         cout << len << "\n";
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
