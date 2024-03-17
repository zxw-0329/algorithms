/*
 字符串 s, t;
 思路: 子序列本质上就是选或不选
 考虑最后一对字母 x,y 有4种组合;

 当前操作 考虑当前s[i] 和 t[j]选或不选
 子问题 s的前 i 个字母 , t的前 j 个字母的lcs长度
  下一个子问题
  s的前i-1个字母,t的前j-1个字母
  s的前i-1个字母,t的前 j 个字母
  s的前 i 个字母,t的前j-1个字母

  都选和都不选 子问题是一样的 只有当 s[i]==t[j] 才能都选(都选比都不选肯定要好);

  可以得到两个式子
  dfs(i,j)=max( dfs(i-1,j) , dfs(i,j-1) , dfs(i-1,j-1)+1 )  s[i]==t[j]
  dfs(i,j)=max( dfs(i-1,j) , dfs(i,j-1) , dfs(i-1,j-1) )  s[i]!=t[j]

 视频: https://www.bilibili.com/video/BV1TM4y1o7ug/?spm_id_from=333.788&vd_source=7e2ae3859dfc2b030d597a1ee3dcc5d4
 题目: https://vjudge.net/problem/HDU-1159#author=GPT_zh
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   string s, t;

   while (cin >> s >> t) {
      int n = s.size();
      int m = t.size();
      vector f(n + 1, vector<int>(m + 1, 0));
      // auto dfs = [&](auto self, int i, int j)->int {
      //    if (i < 0 || j < 0)return 0;
      //    if (f[i][j] != -1) {
      //       return f[i][j];
      //    }
      //    if (s[i] == t[j]) {
      //       return f[i][j] = self(self, i - 1, j - 1) + 1;
      //    }
      //    else {
      //       return f[i][j] = max(self(self, i - 1, j), self(self, i, j - 1));
      //    }
      //    };
      // cout << dfs(dfs, n - 1, m - 1) << "\n";
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
            if (s[i] == t[j]) {
               f[i + 1][j + 1] = f[i][j] + 1;
            }
            else {
               f[i + 1][j + 1] = max(f[i][j + 1], f[i + 1][j]);
            }
         }
      }
      cout << f[n][m] << "\n";
   }
   return 0;
}
