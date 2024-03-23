#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int n, k;
   cin >> n >> k;
   vector<int>h(n);
   for (int i = 0; i < n; i++) {
      cin >> h[i];
   }
   vector<int>dp(n);
   dp[0] = 0;
   dp[1] = abs(h[1] - h[0]);
   //多增加了一个循环
   for (int i = 2; i < n; i++) {
      dp[i] = dp[i - 1] + abs(h[i] - h[i - 1]);
      for (int j = i - 2; j >= max(0, i - k) ; j--) {
         dp[i] = min(dp[j] + abs(h[i] - h[j]), dp[i]);
      }
   }
   cout << dp[n - 1] << "\n";
   return 0;
}