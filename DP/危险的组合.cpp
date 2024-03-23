#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int  n;
   cin >> n;
   vector<int>dp(n + 1);
   dp[3] = 1;
   //现在已经有3个装有 U 的盒子放在一起，满足条件
   //那么当前第 i 个盒子则有两种选择分别为放 U 和放 L
   //如果当前不满足条件 要想下个位置满足条件 则这三个必须为LUU
   //我们就需要求前面的盒子不合法的方案数(加上当前位置U就合法)
   //就用全部的方案数 减去合法的方案数就是不合法的方案数
   for (int i = 4; i <= n; i++) {
      dp[i] = (2 * dp[i - 1] + (1 << (i - 4)) - dp[i - 4]) % mod;
   }
   cout << dp[n];
   return 0;
}