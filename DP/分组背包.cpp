/*
  题目大意 有n门课 ，学m 天 问最多能拿多少学分 
          每门课 学习 j 天获得的学分为 aij 

    与0/1 背包相似 状态定义  dp[i][j] 表示把前i 门课 天数为 j 天时获得的最多学分
    so : 天数表示体, aij 表示价值, m表示总体积;

    状态转移 dp[i][j] = max(max(dp[i - 1][j], dp[i][j]), dp[i - 1][j - k] + w[i][k]);
    
    https://acm.hdu.edu.cn/showproblem.php?pid=1712
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }
        vector<vector<int>>w(n + 1, vector<int>(m + 1));
        //  vector<vector<int>>c(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> w[i][j];
                //   c[i][j] = j;
            }
        }
        vector<vector<int>>dp(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int k = 1; k <= m; k++) {
                    if (j >= k) {
                        dp[i][j] = max(max(dp[i - 1][j], dp[i][j]), dp[i - 1][j - k] + w[i][k]);
                    }
                    // else {
                    //     dp[i][j] =  max(dp[i][j],dp[i - 1][j]);
                    // }
                }
            }
        }
       // vector<int>dp(m + 1);   自我滚动
       //  for (int i = 1; i <= n; i++) {
       //      for (int j = m; j >=0; j--) {
       //          for (int k = 1; k <= m; k++) {
       //              if (j >= k) {
       //                  dp[j] = max(dp[j], dp[j - k] + w[i][k]);
       //                  // dp[i][j] = max(max(dp[i - 1][j], dp[i][j]), dp[i - 1][j - k] + w[i][k]);
       //              }
       //          }
       //      }
       //  }
       // cout<<dp[m]<<"\n";
        cout << dp[n][m] << "\n";
    }
    return 0;
}
