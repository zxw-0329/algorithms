/*
  按题目做
  怎么交换 l 跟 x的位置就对了呢
  
  https://codeforces.com/contest/1945/problem/E
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
   int n, x;
   cin >> n >> x;
   vector<int>a(n + 1);
   for (int i = 1; i <= n; i++) {
      cin >> a[i];
   }
   int l = 1, r = n + 1;
   while (l + 1 < r) {
      int mid = (l + r) / 2;
      if (a[mid] <= x) {
         l = mid;
      }
      else r = mid;
   }
   int t = l;
   if (a[l] == x) {
      cout << 0 << "\n";
      return;
   }
   vector<pair<int, int>>ans;
   auto it = find(a.begin(), a.end(), x) - a.begin();
   swap(a[t], a[it]);
   ans.push_back({ it, t });
   l = 1, r = n + 1;
   while (l + 1 < r) {
      int mid = (l + r) / 2;
      if (a[mid] <= x) {
         l = mid;
      }
      else r = mid;
   }
   if (a[l] == x) {
      cout << 1 << "\n";
      cout << ans[0].first << " " << ans[0].second << "\n";
      return;
   }
   ans.push_back({ t,l });
   cout << 2 << "\n";
   for (auto [x, y] : ans) {
      cout << x << " " << y << "\n";
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
