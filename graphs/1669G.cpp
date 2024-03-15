/*
  枚举每一列 从下往上枚举 枚举两石头之间的的下降情况;
 
  https://codeforces.com/contest/1669/problem/G
  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
   int n, m;
   cin >> n >> m;
   vector<string>a(n);
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }

   for (int i = 0; i < m; i++) {
      int last = n - 1;
      while (last >= 0 && a[last][i] != '.')last--;
      // cout << last << "\n";
      for (int j = last - 1; j >= 0; j--) {
         if (a[j][i] == 'o') {
            int cnt = 0;
            for (int k = last; k > j; k--) {
               if (a[k][i] == '*')cnt++;
               a[k][i] = '.';
            }
            while (cnt--) {
               a[last][i] = '*';
               last--;
            }
            last = j - 1;
         }
         if (last < 0)break;
      }
      bool ok = true;
      int p = 0;
      for (int k = last; k >= 0; k--) {
         if (a[k][i] == 'o') {
            ok = false;
            break;
         }
         if (a[k][i] == '*') {
            p++;
         }
      }
      if (ok) {
         for (int k = last; k >= 0; k--) {
            if (p>0) {
               a[k][i] = '*';
               p--;
            }
            else a[k][i] = '.';
         }
      }
   }
   for (int i = 0; i < n; i++) {
      cout << a[i] << "\n";
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
