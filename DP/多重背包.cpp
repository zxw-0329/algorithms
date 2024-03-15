/*
  思路1：把相同的mi个物品看作独立的mi个物品用0/1背包求解;
  思路2:直接求解 d定义状态dp[i][j]=max{dp[i-1][j],  dp[i-1][j-k*w[i]]+k*v[i]  , dp[i][j]}; 1<=k<=min{m[i],j/w[i]};

  对思路2进行 二进制优化
  假设第i个物品有 25个 那么放进背包的组合有0-25 ; 26种
  但组合26种情况,不需要25个物品
  根据二进制任何一个十进制数X 都可以用 1，2，4，8....表示
  将题目种mi进行二进制拆分
  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int n, C;
   cin >> n >> C;
   vector<int>v(n);
   vector<int>w(n);
   vector<int>m(n);
   for (int i = 0; i < n; i++) {
      cin >> v[i] >> w[i] >> m[i];
   }
   // vector<int>dp(C+1);     O(C*sum(mi))
   // for (int i = 0; i < n; i++) {    。。枚举物品
   //    for (int j = C; j >= w[i]; j--) {   //枚举容量
   //       for (int k = 1; k <= m[i] && k * w[i] <= j; k++) {  //枚举选几个
   //          dp[j] = max(dp[j], dp[j - k * w[i]] + k * v[i]);
   //       }
   //    }
   // }
   // cout << dp[C] << "\n";
   vector<int>nv;
   vector<int>nw;
   for (int i = 0; i < n; i++) {
      for (int j = 1; j <= m[i]; j <<= 1) { //二进制枚举1，2，4，8，...
         m[i] -= j;
         nv.push_back(j * v[i]);    //新物品的价值(j个第i个物品的价值)
         nw.push_back(j * w[i]);    //新物品的体积(j个第i个物品的体积)
      }
      if (m[i]) {                        //余数
         nv.push_back(m[i] * v[i]);
         nw.push_back(m[i] * w[i]);
      }
   }
   int p = nv.size();//拆分过后的总数
   vector<int>dp(C+1);
   for (int i = 0; i < p; i++) {
      for (int j = C; j >= nw[i]; j--) {
         dp[j] = max(dp[j], dp[j - nw[i]] + nv[i]);
      }
   }
   cout << dp[C] << "\n";
   return 0;
}
