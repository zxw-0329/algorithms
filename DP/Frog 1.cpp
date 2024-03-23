#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int n;
   cin >> n;
   vector<int>h(n);
   for (int i = 0; i < n; i++) {
      cin >> h[i];
   }
   vector<int>dp(n);
   dp[0] = 0;
   dp[1] = abs(h[1] - h[0]);
   //与走楼梯问题很相似
   for (int i = 2; i < n; i++) {
      dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
   }
   cout << dp[n - 1] << "\n";
   return 0;
}