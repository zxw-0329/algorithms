#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int n;
   cin >> n;
   std::vector<int> a(n);
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }
   // vector<int> b(n);
   // int ans = 0;
   //暴搜+剪枝
   //对于每个位置有放和不放两种状态  判断两种状态是否合法
   // auto dfs = [&](auto self, int k) {
   //    if (k == n) {
   //       if (b[k-1] + b[k - 2] == a[k - 1]) {
   //          ans++;
   //       }
   //       return ;
   //    }
   //    b[k] = 1;
   //    if (k == 0) {
   //       self(self, k + 1);
   //    }
   //    else if (k == 1 && b[k] + b[k - 1] == a[k - 1]) {
   //       self(self, k + 1);
   //    }
   //    else if (b[k] + b[k - 1] + b[k - 2] == a[k - 1]) {
   //       self(self, k + 1);
   //    }
   //    b[k] = 0;
   //    if (k == 0) {
   //       self(self, k + 1);
   //    }
   //    else if (k == 1 && b[k] + b[k - 1] == a[k - 1]) {
   //       self(self, k + 1);
   //    }
   //    else if (b[k] + b[k - 1] + b[k - 2] == a[k - 1]) {
   //       self(self, k + 1);
   //    }
   // };
   // dfs(dfs,0);
   // cout << ans << "\n";
   vector<vector<vector<int>>>dp(n + 1, vector<vector<int>>((2), vector<int>(2)));
   //dp[i][j][k]表示当前位置为 i ,当前位置是不是雷(用j表示),下一位置需不需要是雷(k)的方案数.

   dp[0][0][0] = dp[0][0][1] = 1;
   for (int i = 0; i < n; i++) {
      if (a[i] == 0) {
         dp[i + 1][0][0] += dp[i][0][0];
      }
      else if (a[i] == 1) {
         dp[i + 1][0][0] += dp[i][1][0];
         dp[i + 1][0][1] += dp[i][0][0];
         dp[i + 1][1][0] += dp[i][0][1];
      }
      else if (a[i] == 2) {
         dp[i + 1][1][1] += dp[i][0][1];
         dp[i + 1][0][1] += dp[i][1][0];
         dp[i + 1][1][0] += dp[i][1][1];
      }
      else {
         dp[i + 1][1][1] += dp[i][1][1];
      }
   }
   cout << dp[n][0][0] + dp[n][1][0] << "\n";
   return 0;
}