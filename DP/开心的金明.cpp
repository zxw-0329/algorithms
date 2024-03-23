#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int n, m;
   cin >> n >> m;
   vector<int>w(m), v(m);
   //物品的钱数代表体积
   //价值为 重要度*钱数
   for (int i = 0; i < m; i++) {
      cin >> v[i] >> w[i];
      w[i] *= v[i];
   }
   vector<int>dp(n + 1);
   for (int i = 0; i < m; i++) {
      for (int j = n; j >= v[i]; j--) { //体积
         dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
      }
   }
   cout << dp[n] << "\n";
   return 0;
}