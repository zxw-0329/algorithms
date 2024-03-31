/*

 枚举以右端点i的子数组
 到以 i+1为右端点的子数组
 增量式计算子数组的OR
 维护子数组OR以及对应子数组左端点的最大值
 数组vector<pair<int, int>>t :key为子数组的or值 value 为左端点的最大值
 
   https://leetcode.cn/problems/shortest-subarray-with-or-at-least-k-ii/description/
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
   int n, k;
   cin >> n >> k;
   vector<int>a(n);
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }
   vector<pair<int, int>>t;
   int ans = INT_MAX;
   for (int i = 0; i < n; i++) {
      t.push_back({ 0,i });
      int j = 0;
      for (auto& [x, left] : t) {
         x |= a[i];
         if (x >= k) {
            ans = min(ans, i - left + 1);
         }
         else {
            if (x == t[j].first) {
               t[j].second = left;
            }
            else {
               t[++j] = { x,left };
            }
         }
      }
      t.resize(j + 1);
   }
   cout << (ans == INT_MAX ? -1 : ans) << "\n";
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
