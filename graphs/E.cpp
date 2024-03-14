/*
  在题目中，李渊在台阶上可以向上或向下移动。但是对于能量波动一样的能量阵，他只能穿梭到上方(编号大的台阶)最近的一个能量阵。
  通过以上信息，可以建立一个简单的有向图，而后使用BFS搜索最快到达第n级台阶的情况。

  https://ac.nowcoder.com/acm/contest/77338/E
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
   map<ll, int>m;
   vector<int>a(n);
   vector<int>adj[n];
   for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (i != n - 1) {
         adj[i].push_back(i + 1);
         adj[i + 1].push_back(i);
      }
      if (m.count(a[i])) {
         adj[m[a[i]]].push_back(i);
      }
      m[a[i]] = i;
   }
   vector<bool>vis(n);
   vector<int>dis(n);
   dis[0] = 0;
   queue<pair<int,int>>q;
   auto bfs = [&](int s)->void {
      q.push({s,0});
     // vis[s] = true;
      while (!q.empty()) {
         auto [p, y] = q.front();
         vis[p] = true;
         q.pop();
         for (auto x : adj[p]) {
            if (vis[x]) {
               continue;
            }
            if (x == n - 1) {
               cout << y + 1 << "\n";
               return;
            }
            q.push({ x,y + 1 });
         }
      }
      cout << 0 << "\n";
      };
   bfs(0);
   return 0;
}
