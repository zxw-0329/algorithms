/*
   通过预处理 {fa}_{x,i} 数组，游标可以快速移动，大幅减少了游标跳转次数。{fa}_{x,i} 表示点 x 的第 2^i 个祖先。{fa}_{x,i} 数组可以通过 dfs 预处理出来。

   存储可以用链式前向星
   
  https://www.luogu.com.cn/problem/P3379
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 5e5 + 5;
vector<int>e[N];
int dep[N];
int fa[N][22];
int n, m, s;
void dfs(int cur, int f) {
   dep[cur] = dep[f] + 1;
   fa[cur][0] = f;
   for (int i = 1; i <= 20; i++) {
      fa[cur][i] = fa[fa[cur][i - 1]][i - 1];
   }
   for (int x : e[cur]) {
      if (x != f) {
         dfs(x, cur);
      }
   }
}
int lca(int x, int y) {
   if (dep[x] < dep[y]) {
      swap(x, y);
   }
   for (int i = 20; i >= 0; i--) {
      if (dep[fa[x][i]] >= dep[y]) {
         x = fa[x][i];
      }
   }
   if (x == y) {
      return x;
   }
   for (int i = 20; i >= 0; i--) {
      if (fa[x][i] != fa[y][i]) {
         x = fa[x][i];
         y = fa[y][i];
      }
   }
   return fa[x][0];
}
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   cin >> n >> m >> s;
   for (int i = 0; i < n - 1; i++) {
      int x, y;
      cin >> x >> y;
      e[x].push_back(y);
      e[y].push_back(x);
   }
   dfs(s, 0);
   while (m--) {
      int a, b;
      cin >> a >> b;
      cout << lca(a, b) << "\n";
   }
   return 0;
}
