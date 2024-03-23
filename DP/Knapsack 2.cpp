#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int n, W;
   cin >> n >> W;
   // 0 / 1 背包问题
   std::vector<int> w(n + 1), v(n + 1);
   int s = 0;
   for (int i = 0; i < n; i++) {
      cin >> w[i] >> v[i];
      s += v[i];
   }
   //与前一题相比W的范围变大 在套用上个模板会超时
   //观察数据范围 v的范围很小  转换一下思路
   //dp[i][j] 代表前i件物品在总价值为j时装的最少体积
  
   vector<ll>dp(s + 1, 1e18);
   dp[0] = 0;
   for (int i = 0; i < n; i++) {
      for (int j = s; j >= v[i]; j--) {
         dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
      }
   }
   for (int i = s; i >= 0; i--) {
      if (dp[i] <= W) {
         cout << i << "\n";
         break;
      }
   }
   // for (int i = 1; i <= n; i++) {
   //    cin >> w[i] >> v[i];
   //    s += v[i];
   // }
   // vector<vector<ll>>dp(n + 1, vector<ll>(s + 1, 1e10));
   // dp[0][0] = 0;
   // for (int i = 1; i <= n; i++) {

   //    for (int j = 0; j <= s; j++) {
   //       if (j < v[i]) {
   //          dp[i][j] = dp[i - 1][j];
   //       }
   //       else {
   //          dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
   //       }
   //    }
   // }
   // int ans = 0;
   // for (int i = s; i >= 0; i--) {
   //    if (dp[n][i] <= W) {
   //       ans = i;
   //       break;
   //    }
   // }
   // cout << ans << "\n";
   return 0;
}