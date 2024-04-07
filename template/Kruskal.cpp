/*
  按边进行合并;
  e[i]: 存起点，终点，边权
  fa[x]:存x的父节点
  
  按边权进行从大到小排序
  顺序枚举每一条边 是否在同一集合 在（跳过）否则（合并）
  直到选取n-1条边

  https://www.luogu.com.cn/problem/P3366
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct edge {
   int  u, v, w;
};
vector<int>fa;
int find(int x) {
   if (fa[x] == x)return x;
   return fa[x] = find(fa[x]);
}
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int n, m;
   cin >> n >> m;
   vector<edge>e(m);
   fa.resize(n + 1);
   for (int i = 0; i < m; i++) {
      cin >> e[i].u >> e[i].v >> e[i].w;
   }
   for (int i = 1; i <= n; i++) {
      fa[i] = i;
   }

   sort(e.begin(), e.end(), [](auto a, auto b) {
      return a.w < b.w;
      });
   int ans = 0;
   int cnt = 0;
   for (int i = 0; i < m; i++) {
      int x = find(e[i].u);
      int y = find(e[i].v);
      if (x != y) {
         fa[x] = y;
         ans += e[i].w;
         cnt++;
      }
   }
   if (cnt != n - 1) {
      cout << "orz\n";
   }
   else cout << ans << "\n";
   return 0;
}
