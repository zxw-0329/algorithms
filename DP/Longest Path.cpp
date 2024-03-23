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
      in[y]++;  //记录入度
      adj[x].push_back(y);
   }
   queue<int>q;
      for (int i = 0; i < n; i++) {
      if (in[i] == 0 && adj[i].size()) {//把入度为0且出度不为0的点加入队列 (每个点可能不是联通的) 
         q.push(i);
      }
   }
   vector<int>dp(n);
   //定义状态:dp[i]代表所有点出边为i最长有向路径的长度
   int ans = 0;
   while (!q.empty()) {
      int t = q.front();
      q.pop();
      if (adj[t].size() == 0) {
         ans =max(ans,dp[t]); //到达终点
      }
      for (auto i : adj[t]) {
         dp[i] =max(dp[t]+1,dp[i]);
         in[i]--;
         if (!in[i]) {
            q.push(i);
         }
      }
   }
   cout << ans << "\n";
   return 0;
}