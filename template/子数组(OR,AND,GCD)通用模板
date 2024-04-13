/*
  1.枚举以i为右端点的子数组
  2.OR的性质
  以i为右端点的子数组的OR，至多有O(log((max(nums)))个不同的值  31

  以i为右端点的子数组
  以i+1为右端点的子数组
  增量式计算子数组的OR
  维护子数组的OR以及对应子数组左端的最大值

  vector<pair<int, int>> t  // 保存 (右端点为 i 的子数组 OR, 该子数组左端点的最大值)
  越OR只会不变或变大


  https://leetcode.cn/problems/shortest-subarray-with-or-at-least-k-ii/description/

  https://leetcode.cn/problems/smallest-subarrays-with-maximum-bitwise-or/solutions/1830911/by-endlesscheng-zai1/
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int minimumSubarrayLength(vector<int>& a, int k) {
        int n = a.size();
        int ans = INT_MAX;
        vector<pair<int, int>> t;
        for (int i = 0; i < n; i++) {
            t.push_back({a[i], i});
            int j = 0;
            for (auto& [x, left] : t) {
                x |= a[i];
                if (x >= k) {
                    ans = min(ans, i - left + 1);
                } else {
                    if (x == t[j].first) {
                        t[j].second = left;
                    } else {
                        t[++j] = {x, left};// 原地去重：合并相同值，左端点取靠右的
                    }
                }
            }
            t.resize(j + 1);// 去重：移除多余元素
        }
        return ans == INT_MAX ? -1 : ans;
}
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int n;
   cin>>n;
   vector<int>a(n);
   for(auto &i:a)cin>>i;
   return 0;
}
