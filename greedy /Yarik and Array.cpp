/*
  限制条件:相邻位置不同%2相等
  求连续子数组的最大和
  
  https://codeforces.com/contest/1899/problem/C
  
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
   int s = a[0];
   int ans = a[0];
   for (int i = 1; i < n; i++) {
      if (abs(a[i]) % 2 == abs(a[i - 1]) % 2) {
         s = a[i];
      }
      else {
         s = max(s + a[i], a[i]);
      }
      ans = max(ans, s);
   }
   cout << ans << "\n";
  int n;
    // std::cin >> n;
    
    // std::vector<int> a(n);
    // for (int i = 0; i < n; i++) {
    //     std::cin >> a[i];
    // }
    // int ans = -1E9;
    // int suf = -1E9;
    // for (int i = 0; i < n; i++) {
    //     if (i && (a[i] - a[i - 1]) % 2 == 0) {
    //         suf = 0;
    //     }
    //     suf = std::max(suf, 0) + a[i];
    //     ans = std::max(ans, suf);
    // }
    // std::cout << ans << "\n";
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
