#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   string t, s;
   cin >> s >> t;
   //s[i]==t[j]  dp[i][j]=dp[i-1][j-1]+1
   //s[i]!=t[j]  dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
   int n = s.size();
   int m = t.size();

   // vector<vector<int>>f(n, vector<int>(m, -1));
   // auto dfs = [&](auto self, int i, int j)->int{
   //    if (i < 0 || j < 0) {
   //       return 0;
   //    }
   //    if (f[i][j] != -1)return f[i][j];
   //    if (s[i] == t[j]) {
   //       return f[i][j] = self(self, i - 1, j - 1) + 1;
   //    }
   //    else{
   //       return f[i][j] = max(self(self, i, j - 1), self(self, i - 1, j));
   //    }
   // };
   // cout << dfs(dfs, n - 1, m - 1);
   std::vector<vector<int>>dp(n + 1, vector<int>(m + 1));

   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         if (s[i] == t[j]) {
            dp[i + 1][j + 1] = dp[i][j] + 1;
         }
         else {//
            dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);

         }
      }
   }
   //求出最长lcs的距离再倒推回去
   int i = n, j = m;
   string ans;
   while (i >= 1 && j >= 1 && dp[i][j] > 0) {
      if (s[i - 1] == t[j - 1]) {
         ans.push_back(s[i - 1]);
         i--;
         j--;
      }
      else {
         if (dp[i][j] == dp[i - 1][j]) {
            i--;
         }
         else j--;
      }
   }
   reverse(ans.begin(),ans.end());
   cout << ans << "\n";
   return 0;
}