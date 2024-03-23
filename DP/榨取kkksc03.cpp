#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int n, M, T;
   cin >> n >> M >> T;
   vector<int>m(n + 1), t(n + 1);
   for (int i = 1; i <= n; i++) {
      cin >> m[i] >> t[i];
   }
   //在0/1背包基础上多增加了一维
   //定义状态dp[i][j][k]表示前i个人在时间为钱数为j,时间为k的情况下,最多可以完成多少同学的愿望
   //状态转移:(j>=m[i]&&k>=t[i])->dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j- m[i]][k-t[i]]+1);
   //答案就为dp[n][M][T];
   vector<vector<vector<int>>>dp(n + 1, vector<vector<int>>((M + 1), vector<int>(T + 1)));
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= M; j++) {
         for (int k = 1; k <= T; k++) {
            if (j < m[i] || k < t[i]) {
               dp[i][j][k] = dp[i - 1][j][k];
            }
            else {
               dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - m[i]][k - t[i]] + 1);
            }
         }
      }
   }
   cout << dp[n][M][T] << "\n";
   return 0;
}