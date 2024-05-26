#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 5000011;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int n, k;
   cin >> n >> k;
   // vector<int>b(n);
   // map<array<ll, 2>, int>m;
   // auto dfs = [&](auto self, int i, int pre)->int {

   //    if (i >= n) {
   //       // for (int i = 0; i < n; i++) {
   //       //    cerr << b[i] << " \n"[i == n - 1];
   //       // }
   //       return 1;
   //    }
   //    if (m.count({ i,pre })) {
   //       return m[{i, pre}];
   //    }
   //    int res = 0;
   //    if (i - pre >= k + 1) {
   //       // b[i] = 1;
   //       res = (res + self(self, i + 1, i)) % mod;
   //       // b[i] = 0;
   //    }
   //    res = (res + self(self, i + 1, pre)) % mod;
   //    m[{i, pre}] = res;
   //    return res;
   //    };
   // cout << dfs(dfs, 0, -(2 * k)) << "\n";
   vector<vector<int>>dp(n, vector<int>(2));
   dp[0][0] = 1;
   dp[0][1] = 1;
   int pre = 0;
   for (int i = 1; i < n; i++) {
      dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
      if (i - k - 1 >= 0) {
         dp[i][1] = (dp[i - k - 1][1] + dp[i - k - 1][0]) % mod;
      }
      else dp[i][1] = 1;
   }
   cout << (dp[n - 1][0] + dp[n - 1][1]) % mod << "\n";
   return 0;
}
