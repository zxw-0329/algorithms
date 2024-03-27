/*
  (ai + aj)%x=0 --> (ai%x + aj%x) % x = 0 ---> (ai%x + aj%x =x) 或 (ai%x + aj%x =0)
  (ai - aj)%y=0 --> ai%y = aj%y
因此，对于某个固定的 aj来说，所有的 ai都符合下面的条件：
i<j; 
ai % x= (x−aj%x)% x;
ai % y=aj % y
我们将从左到右遍历 j,并使用前缀上的映射来保持对 ⟨aimodx,aimody⟩ 的元素计数。

https://codeforces.com/contest/1931/problem/D
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
   int n, x, y;
   cin >> n >> x >> y;
   map<pair<int, int>, int>ma;
   int ans = 0;
   for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      ans += ma[{(x - a % x) % x, a% y}];
      ma[{a% x, a% y}]++;
   }
   cout << ans << "\n";
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
