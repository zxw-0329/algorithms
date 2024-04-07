/*
 按点生成最小树
 e[u]：存u的所有临边的终点和权值
 d[u]：存u点与圈外临点的最小距离
 vis[u]：标记u点是否出圈
 
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e4 + 10;
struct node { int v, w; };
int d[maxn], vis[maxn];
vector<node>e[1001];
int inf = 1e9 + 7;
int n;
bool prime(int s) {
   int cnt = 0;
   int ans = 0;
   for (int i = 0; i <= n; i++)d[i] = inf;
   d[s] = 0;
   for (int i = 1; i <= n; i++) {
      int u = 0;
      for (int j = 1; j <= n; j++) {
         if (!vis[j] && d[j] < d[u])u = j;
      }
      vis[u] = 1;
      ans += d[u];
      if (d[u] != inf)cnt++;//判断图是否联通;
      for (auto ed : e[u]) {
         int v = ed.v, w = ed.w;
         if (d[v] > w)d[v] = w;
      }
   }
   return cnt == n;
}
priority_queue<pair<int, int>>q;
bool prime(int s) { //大根堆优化;
   for (int i = 0; i <= n; i++)d[i] = inf;
   d[s] = 0; int cnt = 0, ans = 0;
   q.push({ 0,s });
   while (q.size()) {
      int u = q.top().second;
      q.pop();
      if (vis[u])continue;
      vis[u] = 1;
      ans += d[u];
      cnt++;
      for (auto ed : e[u]) {
         int v = ed.v, w = ed.w;
         if (d[v] > w) {
            d[v] = w;
            q.push({ -d[v],v });
         }
      }
   }
   return cnt == n;
}
void solve() {
   int m;
   cin >> n >> m;
   for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      e[a].push_back({ b,c });
      e[b].push_back({ a,c });
   }

}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int t = 1;
   cin >> t;

   while (t--) {
      solve();
   }
   return 0;
}
