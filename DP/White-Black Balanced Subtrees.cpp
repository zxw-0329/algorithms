/*
  让我们运行一个从树叶到树根的动态编程。为每个顶点存储平衡子树的数量以及白顶点和黑顶点的数量。

  然后，我们可以从一个顶点开始计算其子树中白色顶点和黑色顶点的总数，
  如果两者相等，则更新总数。
  记住，在这些计数中要包括顶点本身的颜色。
  答案就是根的答案。(也就是说在当前根节点且包含根节点 如果之和为0 说明平衡) 设W为-1 , B为 1;
  
  https://codeforces.com/contest/1676/problem/G
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
   int n;
   cin >> n;
   // vector<int>p(n);
   // for (int i = 1; i < n; i++) {
   //    cin >> p[i];
   //    p[i]--;
   // }
   // p[0] = -1;
   // vector<int>s(n);
   // for (int i = 0; i < n; i++) {
   //    char c;
   //    cin >> c;
   //    s[i] = c == 'W' ? -1 : 1;   //小小的技巧 两种状态 要平衡 之和为0 就行  设W为-1 , B为 1;
   // }
   // for (int i = n - 1; i > 0; i--) {
   //    s[p[i]] += s[i];
   // }
   // cout << count(s.begin(), s.end(), 0) << "\n";
    vector<int>adj[n];
   //0 -> n-1
   for (int i = 1; i < n; i++) {
      int x;
      cin >> x;
      x--;
      adj[x].push_back(i);
   }
   string s;
   cin >> s;
   int ans = 0;
   function<int(int)>dfs = [&](int k)->int {
      int t = s[k] == 'W' ? -1 : 1;
      if (adj[k].empty()) {
         return t;
      }  
      for (auto i : adj[k]) {
         t += dfs(i);
      }
      if (t == 0)ans++;
      return t;
      };
   dfs(0);
   cout << ans << "\n";
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
