#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int v, n;
   cin >> v >> n;
   vector<int>w(n);
   for (int i = 0; i < n; i++) {
      cin >> w[i];
   }
   vector<int>dp(v + 1);
   for (int i = 0; i < n; i++) {
      for (int j = v; j >= w[i]; j--) {
         dp[j] = max(dp[j], dp[j - w[i]] + w[i]);
      }
   }
   cout << v - dp[v] << "\n";
   return 0;
}