#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 10;
int dp[maxn][2][2][2];
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int n;
   cin >> n;
   std::vector<int> a(n), b(n), c(n);
   for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i] >> c[i];
   }
   //dp[i][j][k][l]表示在第 i 天时,做 j , k , l 其中一件活动可能获得的幸福总分的最大值
   //每件事有两种状态(做 / 不做)用 0 / 1 表示
   //约束条件: 1.只能做 j ,k ,l 其中一件
   //         2.不能连续两天或两天以上做同样的活动
   //dp[i][j][k][l]
   //      a  b  c
   for (int i = 0; i < n; i++) {
      if (i == 0) {
         dp[i][1][0][0] = a[i];
         dp[i][0][1][0] = b[i];
         dp[i][0][0][1] = c[i];
      }
      else {
         dp[i][1][0][0] = max(dp[i - 1][0][1][0], dp[i - 1][0][0][1]) + a[i];
         dp[i][0][1][0] = max(dp[i - 1][1][0][0], dp[i - 1][0][0][1]) + b[i];
         dp[i][0][0][1] = max(dp[i - 1][0][1][0], dp[i - 1][1][0][0]) + c[i];
      }
   }
   cout << max({dp[n - 1][1][0][0], dp[n - 1][0][1][0], dp[n - 1][0][0][1]}) << "\n";
   return 0;
}