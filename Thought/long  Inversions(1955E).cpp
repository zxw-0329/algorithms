/*
  差分数组
  对于某一段区间的做相同修改不能直接遍历会TLE
  提示 1
  想一想，如果 nums[0]=0，我们必须要执行什么样的操作，才能让 nums[0]=1？

  提示 2
  对于 nums[0]=0 的情况，必须把 nums[0] 到 nums[k−1]都翻转(0-->1  1-->0)。 
  然后思考 nums[1] 要怎么处理，依此类推。

  提示 3
  子数组同时加上/减去一个数/（进行0/1翻转），非常适合用 差分数组 来维护

  设差分数组为 d。那么把 nums[i] 到 nums[i+k−1]同时翻转，等价于把 d[i]^1，d[i+k]^1。

  注意子数组长度必须恰好等于 k，所以当 i+k≤n 时，才能执行上述操作。

  遍历数组的同时，用变量 sumD累加差分值。遍历到 nums[i] 时，nums[i]^sumD 就是 nums[i]的实际值了。


   算法课堂：https://leetcode.cn/circle/discuss/FfMCgb/
   https://codeforces.com/contest/1955/problem/E
   https://leetcode.cn/problems/apply-operations-to-make-all-array-elements-equal-to-zero/description/
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
   int n;
   cin >> n;
   string s;
   cin >> s;
   for (int k = n; k >= 1; k--) {
      vector<int>d(n + 1);
      int v = 0;
      bool ok = true;
      for (int i = 0; i < n; i++) {
         v ^= d[i];
         // if (v == s[i] - '0') {
         //    if (i + k > n) {
         //       ok = false;
         //       break;
         //    }
         //    v ^= 1;
         //    d[i + k] ^= 1;
         // }
         int x = s[i] - '0';
         x ^= v;//当前i的实际值
         if (x == 1)continue;
         else {
            if (i + k > n) {
               ok = false;
               break;
            }
            v ^= 1;
            d[i + k] ^= 1;
         }
      }
      if (ok) {
         cout << k << "\n";
         return;
      }
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
