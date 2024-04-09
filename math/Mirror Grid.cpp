/*
  矩阵翻转
  https://codeforces.com/contest/1703/problem/E
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
   int n;
   cin >> n;
   vector a(n,vector<int>(n));
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         char ch;
         cin >> ch;
         a[i][j] = ch - '0';
      }
   }
   int ans = 0;
   for (int i = 0; i < n / 2; i++) {
      int t = n - 1 - i;
      for (int j = i; j < n - i - 1; j++) {
         int s = a[i][j] + a[j][t] + a[t][n - 1 - j] + a[n - 1 - j][i];
         ans += min(s, 4 - s);
      }
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
