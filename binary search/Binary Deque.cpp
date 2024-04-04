/*
  思路:找到连续最长的子数组和==s 
      答案就为n-ans需要删掉的数字
      滑动窗口

   https://codeforces.com/contest/1692/problem/E
   https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/description/
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
   int n, s;
   cin >> n >> s;
   vector<int>a(n);
   for (auto& i : a) {
      cin >> i;
   }
   if (count(a.begin(), a.end(), 1) < s) {
      cout << -1 << "\n";
      return;
   }
   int ans = 0;
   for (int i = 0, j = 0, sum = 0; i < n; i++) {
      while (j < n && sum + a[j] <= s) {
         sum += a[j];
         j++;
      }
      ans = max(ans, j - i);
      sum -= a[i];
   }
   cout << n - ans << "\n";
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
