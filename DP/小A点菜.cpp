#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int n, m;
   cin >> n >> m;
   vector<int>a(n + 1);
   for (int i = 1; i <= n; i++) {
      cin >> a[i];
   }
   vector<vector<int>>dp(n + 1, vector<int>(m + 2));
   //钱数充足的情况下:每道菜可以选择 吃或 不吃 否则 只能不吃
   //定义状态dp[i][j] 在花光 j元 的情况吃前i道菜的方案数
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
         if (j == a[i]) {
            dp[i][j] = dp[i - 1][j] + 1;
         }
         else if (j > a[i]) {//钱数够
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i]];
                       //不吃第i道菜    吃第i道菜
         }
         else {//钱数不够只能不吃
            dp[i][j] = dp[i - 1][j];
         }
      }
   }

   cout << dp[n][m] << "\n";
   return 0;
}