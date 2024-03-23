#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int n;
   cin >> n;
   vector<vector<int>>dp(n + 1, vector<int>(2));
   dp[1][0] = dp[1][1] = 1;
   //定义状态: dp[i][1]当前位置以1结尾的合法的方案数
   //         dp[i][0]当前位置以0结尾的合法的方案数
   //思考:对于当前位置 填0 还是填 1
   //填0 dp[i-1]的所有方案数对于dp[i][0]都是合法的;
   //填1 只有dp[i-1][0]对于dp[i][1]是合法的
   for (int i = 2; i <= n; i++) {
      dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
      dp[i][1] = dp[i - 1][0] % mod;
   }
   cout << (dp[n][0] + dp[n][1]) % mod << "\n";
   return 0;
}