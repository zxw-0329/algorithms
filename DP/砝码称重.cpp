/*
  思路 把m[i] 个 w[i] 看为体积 ，价值为砝码总重量;
  用多重背包求解(附带二进制优化)
  
  定义:状态dp[i]表示重量i能被表示的方案数
       dp[i]=dp[i]+dp[i-nw[i]];
      dp[i]>0 说明能被表示
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int n;
   vector<int>m(6);
   vector<int>w = { 1,2,3,5,10,20 };
   //vector<int>nw;
   int C = 0;
   for (int i = 0; i < 6; i++) {
      cin >> m[i];
      C += w[i] * m[i];
      // for (int j = 1; j <= m[i]; j <<= 1) {  //二进制优化
      //    m[i] -= j;
      //    nw.push_back(j * w[i]);
      // }
      // if (m[i]) {
      //    nw.push_back(m[i] * w[i]);
      // }
   }
   // int p = nw.size();
    // vector<int>ans(1100);
    // ans[0] = 1;
    // for (int i = 0; i < p; i++) {
    //    for (int j = C; j >= 0; j--) {
    //       if (ans[j]) {
    //          ans[j + nw[i]] = 1;
    //       }
    //    }
    // }
   int cnt = 0;
   // for (int i = 1; i <= C; i++) {
   //    if (ans[i]) {
   //       cnt++;
   //    }
   // }
  // vector<int>dp(1002);
   // dp[0] = 1;
   // for (int i = 0; i < p; i++) {
   //    for (int j = C; j >= nw[i]; j--) {
   //       dp[j] = dp[j] + dp[j - nw[i]];
   //    }
   // }
   // int cnt = 0;
   // for (int i = 1; i <= C; i++) {
   //    if (dp[i]) {
   //       cnt++;
   //    }
   // }  
   vector<int>dp(10001);
   dp[0] = 1;
   for (int i = 0; i < 6; i++) {
      if (m[i] == 0)continue;
      for (int j = C; j >= 0; j--) {
         for (int k = 1; k <= m[i]; k++) {
            if (j >= k * w[i]) {
               dp[j] = dp[j] + dp[j - k * w[i]];
            }

         }
      }
   }
   for (int i = 1; i <= C; i++) {
      if (dp[i]) {
         cnt++;
      }
   }
   cout << "Total=" << cnt << "\n";
   return 0;
}
