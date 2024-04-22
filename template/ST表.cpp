/*
  用来解决RMQ问题（区间最大/最小查询）
  思想：倍增
  预处理：O(nlogn)
  查询：O（1）
  
  https://www.luogu.com.cn/problem/P3865
  
  https://www.luogu.com.cn/problem/P2471 模拟
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int n, t;
   cin >> n >> t;
   vector<int>a(n);
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }
   vector st(__lg(n) + 1, vector<int>(n));
   st.front() = a;
   for (int j = 1; j <= __lg(n); j++) {//枚举区间长度
      for (int i = 0; i + (1 << j) - 1 < n; i++) {//枚举区间起点
         st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
      }
   }
   auto query = [&](int l, int r) {
      int k = __lg(r - l + 1);
      return max(st[k][l], st[k][r - (1 << k) + 1]);
      };

   while (t--) {
      int l, r;
      cin >> l >> r;
      l--; r--;
      int x = query(l, r);
      cout << x << "\n";
   }
   return 0;
}
