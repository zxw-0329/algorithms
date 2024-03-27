/*

  从当前位置往后找,找到第一个与当前位置不相等的元素的位置

  
 https://codeforces.com/contest/1927/problem/D
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
   int n, q;
   cin >> n;
   vector<int>a(n);
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }
   vector<int>nxt(n+2);//记录当前下标元素下一个与之不相等元素的位置;
   nxt[n - 1] = n;
   for (int i = n - 2; i >= 0; i--) {
      nxt[i] = a[i] == a[i + 1] ? nxt[i + 1] : i + 1;
   }
   cin >> q;
   while (q--) {
      int l1, r;
      cin >> l1 >> r;
      l1--, r--;
      if (nxt[l1] > r) {
         cout << -1 << " " << -1 << "\n";
      }
      else cout << l1 + 1 << " " << nxt[l1] + 1 << "\n";
   }
   cout << "\n";
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
