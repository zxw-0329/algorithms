#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int n, W;
   cin >> n >> W;
   // 0 / 1 背包问题
   std::vector<int> w(n), v(n);
   for (int i = 0; i < n; i++) {
      cin >> w[i] >> v[i];
   }
   vector<ll>dp(W + 1);
   for (int i = 0; i < n; i++) {
      for (int j = W; j >= w[i]; j--) {
         dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
      }
   }
   cout << dp[W] << "\n";
   return 0;
}