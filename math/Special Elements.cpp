/*
  前缀和 + 标记 +观察数据范围
  对于每个数ai都是<=n
  对于前缀和只需要标记 <=n 的数即可
  之后在统计

  https://codeforces.com/contest/1352/problem/E
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
   int n;
   cin >> n;
   vector<int>a(n);
   map<int, int>m;
   for (int i = 0; i < n; i++) {
      cin >> a[i];
      m[a[i]]++;
   }
   vector<int>s(n + 1);
   for (int i = 0; i < n; i++) {
      s[i + 1] = s[i] + a[i];
   }
   int cnt = 0;
   vector<bool>f(n + 1);
   for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
         if (s[j] - s[i - 1] <= n) {
            f[s[j] - s[i - 1]] = true;
         }
         
      }
   }
   for (auto i : a) {
      cnt += f[i];
   }
   cout << cnt << "\n";
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
