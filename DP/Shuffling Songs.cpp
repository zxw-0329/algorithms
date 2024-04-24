/*
  集合可以用二进制表示，二进制从低到高第 i 位为 1 表示 i 在集合中，
                                        为 0 表示 i 不在集合中。
例如集合 {0,2,3} 可以用二进制数 1101表示；
反过来，二进制数 1101 就对应着集合 {0,2,3}。
正式地说，包含非负整数的集合 
S 可以用如下方式「压缩」成一个数字：
f(S)= ∑2^i (i∈S)

上面举例的 {0,2,3} 就可以压缩成2^0+2^2+2^3=13，也就是二进制数 1101。
 本题是状态压缩dp
 由上面集合和二进制可以一一对应
 定义 dp[i]：把i进行二进制拆分 第j个位置 为 1说明 选了第 j 个位置 ，反之则没选第 j 个位置
 
 考虑本题样例：
  electronic themotans   0
  electronic carlasdreams  1
  pop themotans   2 
  pop irinarimes  3
  在不考虑本题限制 ，假如二进制串为 0111 表明选了 第 0 ，1，2 的位置
  考虑限制：相邻位置要么歌手相同，要么类型相同
   所以 谁先谁后是有区别的
   例 ：假如先选 0 在选 1  ，1后面就不能接 2 和 3
        如果 先选1 在选 0 ， 0后面可以接  2 ， 3
   所以在dp数组上要多加一维
   定义dp[i][j]：表示在i的状态下，以j结尾 是否可行
                                0010000
   初始时 ，每首歌单独时为真 所以 dp[1<<i][i]=true 在只选一首且当前首结尾为真
   接下来遍历能接在 i 状态的歌曲 j进行状态转移
 */
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
   int n;
   cin >> n;
   vector<string>g(n), w(n);
   for (int i = 0; i < n; i++) {
      cin >> g[i] >> w[i];
   }
   vector<vector<int>>e(n, vector<int>(n, 0));
   for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
         e[j][i] = e[i][j] = g[i] == g[j] || w[i] == w[j];
      }
   }
   vector<vector<bool>>dp(1 << n, vector<bool>(n, false));
   for (int i = 0; i < n; i++) {
      dp[1 << i][i] = true;
   }
   int ans = 0;
   for (int t = 1; t < (1 << n); t++) {
      for (int i = 0; i < n; i++) {
         if (dp[t][i]) {
            ans = max(ans, __builtin_popcount(t));
            for (int j = 0; j < n; j++) {
               if ((t & (1 << j)) == 0 && (e[i][j] || e[j][i])) {
                  dp[t | (1 << j)][j] = true;
               }
            }
         }
      }
   }
   cout << n - ans << "\n";
}
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int t;
   cin >> t;
   while (t--) {
      solve();
   }
   return 0;
}
