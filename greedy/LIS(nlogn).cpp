/*

  视频:https://www.bilibili.com/video/BV1ub411Q7sB/?spm_id_from=333.1007.top_right_bar_window_history.content.click&vd_source=7e2ae3859dfc2b030d597a1ee3dcc5d4
  https://www.luogu.com.cn/problem/P1020
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   vector<int>a;
   int x;
   while (cin >> x) {
      a.push_back(x);
   }
   //最长递增子序列:g[i]表示长度i+1的IS的末尾元素最小值
   //最长递减子序列:g[i]表示长度i+1的DS的末尾元素最大值
   int n = a.size();
   vector<int>g;

   //   cout << it << "\n";
   for (int i = 0; i < n; i++) {
      auto it = lower_bound(g.rbegin(), g.rend(), a[i]) - g.rbegin();
      if (it == 0) {
         g.push_back(a[i]);
      }
      else {
         if (it == g.size() - 1) {
            if (a[i] > g[0]) {
               g[0] = a[i];
            }
            else {
               g[g.size() - it] = a[i];
            }
         }
         else {
            g[g.size() - it] = a[i];
         }
      }
      // for (auto x : g) {
      //    cerr << x << " ";
      // }cerr << "\n";
   }
   cout << g.size() << "\n";
   vector<int>g0;
   for (int i = 0; i < n; i++) {
      auto it = lower_bound(g0.begin(), g0.end(), a[i]);
      if (it == g0.end()) {
         g0.push_back(a[i]);
      }
      else {
         *it = a[i];
      }
   }cout << g0.size() << "\n";
   return 0;
}
