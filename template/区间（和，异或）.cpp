/*
  对于区间和：和为 k 的子数组
        pre[i]:代表0--i的和
        所以我们考虑以 i 结尾的和为 k的连续子数组个数时只要统计有多少个前缀和为 pre[i]−k 即可。
        我们建立哈希表 mp，以和为键，出现次数为对应的值，记录 pre[i] 出现的次数，
        从左往右边更新 mp边计算答案，那么以 i 结尾的答案 mp[pre[i]−k]即可在 O(1) 时间内得到。
        最后的答案即为所有下标结尾的和为 k 的子数组个数之和。
        需要注意的是，从左往右边更新边计算的时候已经保证了mp[pre[i]−k]里记录的 pre[j]的下标范围是 0≤j≤i 。
        同时，由于pre[i]的计算只与前一项的答案有关，因此我们可以不用建立 pre 数组，直接用 pre变量来记录 pre[i−1] 的答案即可。
  
  对于区间异或：与区间和类似

  https://leetcode.cn/problems/subarray-sum-equals-k/description/
  https://acm.webturing.com/problem.php?id=3990
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
   vector<int>a(n);
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }
   int k;
   cin >> k;
   map<int, int>m;
   m[0] = 1;
   int s = 0;
   int ans = 0;
   for (int i = 0; i < n; i++) {
      s ^= a[i];
      int t = s ^ k;
      ans += m[t];
      m[s]++;
   }
   cout << ans << "\n";
   return 0;
}
