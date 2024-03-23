#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int n, m;
   cin >> n >> m;
   vector<vector<int>>a(n + 1, vector<int>(m + 1));
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
         cin >> a[i][j];
      }
   }
   vector<vector<int>>dp(n + 1, vector<int>(m + 1));
   int ans = 0;
   //对于一个已经确定的dp[i][j]=x，
   //它表明包括节点i，j在内向上x个节点，
   // 向左x个节点扫过的正方形中所有a值都为1；
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
         if (a[i][j]) {
            dp[i][j] = min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1;
            ans = max(ans, dp[i][j]);
         }
      }

   }
   cout << ans << "\n";
   return 0;
}