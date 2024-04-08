/*
  经过每个点一次且仅一次的回路（哈密顿图）
  只会暴力的写法：每个点都为起点 计算结果取最小值

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int n;
   cin >> n;
   vector<vector<int>>a(n, vector<int>(n));
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         cin >> a[i][j];
      }
   }
   int ans = 1e9;
   // vector<vector<int>>book(n, vector<int>(n));
   vector<int>book(n);
   auto dfs = [&](auto self, int k, int pre, int s, int ed) {
      if (k == n - 1) {
         s += a[pre][ed];
         ans = min(ans, s);
         return;
      }
      for (int i = 0; i < n; i++) {
         if (i == k || a[k][i] == 0 || i == ed)continue;
         if (book[i])continue;
         book[i] = 1;
         self(self, k + 1, i, s + a[pre][i], ed);
         book[i] = 0;

      }
      };
   for (int i = 0; i < n; i++) {
      fill(book.begin(), book.end(), 0);
      book[i] = 1;
      dfs(dfs, 0, i, 0, i);
   }

   cout << ans << "\n";
   return 0;
}
