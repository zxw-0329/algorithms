/*
  https://www.lanqiao.cn/problems/172/learning/?page=1&first_category_id=1&name=%E9%80%92%E5%A2%9E%E4%B8%89%E5%85%83%E7%BB%84
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int n;
   cin >> n;
   vector<int>a(n), b(n), c(n);
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }
   sort(a.begin(), a.end());
   for (int i = 0; i < n; i++) {
      cin >> b[i];
   }
   sort(b.begin(), b.end());
   for (int i = 0; i < n; i++) {
      cin >> c[i];
   }

   sort(c.begin(), c.end());
   ll ans = 0;
   for (int j = 0; j < n; j++) {
      auto ia = lower_bound(a.begin(), a.end(), b[j]) - a.begin();
      auto ic = upper_bound(c.begin(), c.end(), b[j]) - c.begin();
      ans += (ia) * 1LL * (n - ic);
   }
   cout << ans << "\n";
   return 0;
}
