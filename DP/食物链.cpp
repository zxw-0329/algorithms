#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int n, m;
   cin >> n >> m;
   vector<int>adj[n];
   vector<int>in(n);
   for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      x--, y--;
      in[y]++;
      adj[x].push_back(y);
   }
   queue<int>q;
   vector<int>dp(n);
   //给出一个有向图，求入度为0的点到出度为0的点一共有多少条路
   //定义状态:dp[i]代表到点i方案数
   //最后答案就是 ∑ 无出边的点
   for (int i = 0; i < n; i++) {
      if (in[i] == 0 && adj[i].size()) {
         q.push(i);
         dp[i] = 1;
      }
   }

   int ans = 0;
   while (!q.empty()) {
      int t = q.front();
      q.pop();
      if (adj[t].size() == 0) {
         ans += dp[t];
      }
      for (auto i : adj[t]) {
         dp[i] += dp[t];
         in[i]--;
         if (!in[i]) {
            q.push(i);
         }
      }
   }
   cout << ans << "\n";
   return 0;
}