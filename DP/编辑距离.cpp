/*

 思路参考 最长公共子序列
 边界条件
 初始化

视频:https://www.bilibili.com/video/BV1TM4y1o7ug/?spm_id_from=333.788&vd_source=7e2ae3859dfc2b030d597a1ee3dcc5d4 
题目:https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P2758
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   string s, t;
   cin >> s >> t;
   int n = s.size();
   int m = t.size();
   // vector f(n + 1, vector<int>(m + 1, -1));
   // auto dfs = [&](auto self, int i, int j)->int {
   //    if (i < 0)return j + 1;
   //    if (j < 0)return i + 1;
   //    if (f[i][j] != -1) {
   //       return f[i][j];
   //    }
   //    if (s[i] == t[j]) {
   //       return f[i][j] = self(self, i - 1, j - 1);
   //    }
   //    return f[i][j] = min({ self(self, i - 1, j), self(self, i, j - 1), self(self, i - 1, j - 1) }) + 1;
   //                          //删除                  插入                  替换
   //    };
   // cout << dfs(dfs, n - 1, m - 1) << "\n";
   vector f(n + 1, vector<int>(m + 1, -1));
   for (int j = 0; j <= m; j++) {
      f[0][j] = j;
   }
   for (int i = 0; i < n; i++) {
      f[i + 1][0] = i + 1;
      for (int j = 0; j < m; j++) {
         if (s[i] == t[j]) {
            f[i + 1][j + 1] = f[i][j];
         }
         else {
            f[i + 1][j + 1] = min({ f[i][j + 1], f[i + 1][j],f[i][j] }) + 1;
         }
      }
   }
   cout << f[n][m] << "\n";

   return 0;
}
