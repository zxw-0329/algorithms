/*

 在某一位置时 前面拿 1元 的人数要 >=  拿 2元 的人数
 与括号生成那题类似;
 (在dfs时注意每个人数的数量)
 https://acm.webturing.com/problem.php?id=1054
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
   int m, n, k;
   cin >> m >> n >> k;
   //n 1   k2
   vector<int>a;
   ll cnt = 0;
   auto dfs = [&](auto self, int i, int one, int two) {
      if (i == m) {
         for (int i = 0; i < m; i++) {
            cerr << a[i] << " ";
         }
         cerr << "\n";
         cnt++;
         return;
      }
      if (one < n) {
         a.push_back(1);
         self(self, i + 1, one + 1, two);
         a.pop_back();
      }
      if (i - one < one && two < k) {
         a.push_back(2);
         self(self, i + 1, one, two + 1);
         a.pop_back();
      }
      };
   dfs(dfs, 0, 0, 0);
   for (int i = 1; i <= n; i++) {
      cnt *= i * 1LL;
   }
   for (int i = 1; i <= k; i++) {
      cnt *= i * 1LL;
   }
   cout << cnt << "\n";
}
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int t = 1;
   //cin >> t;
   while (t--) {
      solve();
   }
   return 0;
}
