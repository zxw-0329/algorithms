#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int t, m;
   cin >> t >> m;
   vector<int>w(m), v(m);
   for (int i = 0; i < m; i++) {
      cin >> w[i] >> v[i];
   }
   vector<ll>dp(t + 1);
   //每个草药可以无限采
   //完全背包问题;// 不采      采:注意与0/1背包的不同
   //dp[i][j]=max(dp[i-1][j],dp[i][j-w[i]]);
   for (int i = 0; i < m; i++) {
      for (int j = w[i]; j <= t; j++) {
         dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
      }
   }
   cout << dp[t] << "\n";
   return 0;
}