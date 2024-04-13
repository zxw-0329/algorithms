/*
  子序列 
  相邻无关   0-1 背包
  相邻相关   最长递增子序列  个数
  差值的绝对值最小 -->相邻相关

  子序列： 选或不选
  最长递增子序列个数
    当前位置 上一个位置
   dfs( i , pre )

   不选：dfs( i-1 , pre )
   选：dfs( i-1 , nums[i] )
   相邻 相关要考虑当前位置和上一个位置的关系
   限制长度 要多加一个参数 j
   i是当前下标
   j是还需要选多少个数
   pre是上一个选的数
   min_diff是目前选的数差的绝对值最小值
   dfs( i , j , pre , min_diff)

   不选：dfs(i-1 , j, pre, min_diff)
   选：dfs(i-1 , j-1, nums[i], min( min_diff, pre-nums[i] ))

   递归边界:
   j==0时, 返回min_diff
   j>i+1时，即使剩下的数全部选，也不足j个数，返回 0

   递归入口： dfs(dfs, n - 1, k, inf, inf);

   https://leetcode.cn/problems/find-the-sum-of-subsequence-powers/description/
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int mod = 1e9 + 7;
constexpr ll  inf = 1e10;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int n, k;
   cin >> n >> k;
   vector<int>nums(n);
   for (int i = 0; i < n; i++) {
      cin >> nums[i];
   }
   sort(nums.begin(), nums.end());
   map<array<ll, 4>, ll> m;
   auto dfs = [&](auto self, int i, int j, ll pre, ll min_diff) -> ll {
      if (j == 0)
         return min_diff % mod;
      if (j > i + 1)
         return 0;
      if (m.count(array{ ll(i), ll(j),pre, min_diff })) {
         return m[array{ ll(i), ll(j),pre, min_diff }];
      }
      ll res1 = self(self, i - 1, j, pre, min_diff);
      ll res2 = self(self, i - 1, j - 1, nums[i], min(min_diff, ll(pre - nums[i])));
      m[array{ ll(i), ll(j),pre, min_diff }] = (res1 + res2) % mod;
      return (res1 + res2) % mod;
      };
   dfs(dfs, n - 1, k, inf, inf);
   return 0;
}
