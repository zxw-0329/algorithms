/* 
   思考:对于一个位置的 0 有 两种状态(放或不放) 用1/0表示
   定义状态 dp[i][1]第i个位置放0的方案数
           dp[i][1]第i个位置不放0的方案数 
  状态转移方程:
             dp[0][0] = k - 1;
             dp[0][1] = 0;(初始值)
             dp[i][0] = (dp[i - 1][1] + dp[i - 1][0]) * (k - 1);
             dp[i][1] = dp[i - 1][0];
   https://acm.webturing.com/problem.php?id=1008
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
   int n, k;
   cin >> n >> k;
   vector<vector<int>>dp(n, vector<int>(2));
   dp[0][0] = k - 1;
   dp[0][1] = 0;
   for (int i = 1; i < n; i++) {
      dp[i][0] = (dp[i - 1][1] + dp[i - 1][0]) * (k - 1);
      dp[i][1] = dp[i - 1][0];
   }
   cout << dp[n - 1][0] + dp[n - 1][1] << "\n";
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
