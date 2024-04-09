/*
  用 1 和 2 其中一个去构造 
  https://codeforces.com/contest/1352/problem/B
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
   int n, k;
   cin >> n >> k;
   if (k > n) {
      cout << "NO\n";
      return;
   }
   if (n == k) {
      cout << "YES\n";
      while (k--)cout << 1 << " ";
      cout << "\n";
      return;
   }
   if (n % 2 && k % 2 == 0) {
      cout << "NO\n";
      return;
   }
   int t = n;
   t -= k;
   if ((t + 1) % 2) {
      cout << "YES\n";
      cout << (t + 1) << " ";
      while (--k) {
         cout << 1 << " ";
      }
      cout << "\n";
   }
   else {
      int b = n / 2;
      if (b < k) {
         cout << "NO\n";
         return;
      }
      cout << "YES\n";
      b -= k;
      cout << (b + 1) * 2 << " ";
      while (--k) {
         cout << 2 << " ";
      }cout << "\n";
   }


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
