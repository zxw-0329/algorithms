#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int n;
   cin >> n;
   vector<int>a(n);
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }
   // vector<int>f(n, -1);//另一种初始化为0
   // auto dfs = [&](auto self, int i)->int {
   //    int res = 0;// int &res=f[i]  取引用
   //    if (f[i] != -1) {  //if(res)return res;
   //       return f[i];
   //    }
   //    for (int j = 0; j < i; j++) {
   //       if (a[j] < a[i]) {
   //          res = max(res, f[j] = self(self, j));
   //       }
   //    }
   //    return res+1;//return ++res;
   // };
   // int ans = 0;
   // for (int i = 0; i < n; i++) {
   //    ans = max(ans, dfs(dfs, i));
   // }
   // vector<int>dp(n);//递推
   // for (int i = 0; i < n; i++) {
   //    for (int j = 0; j < i; j++) {
   //       if (a[j] < a[i]) {
   //          dp[i] = max(dp[i], dp[j]);
   //       }
   //    }
   //    dp[i] += 1;
   // }
   //贪心+二分
   vector<int>g;
   //g[i]表示长度为i+1的IS的 末尾元素 的最小值
   for (int x : a) {//要么添加一个数,要么修改
      auto it = lower_bound(g.begin(), g.end(), x);
      if (it == g.end()) {//此时a[i] > g.back();将a[i]添加到g的末尾
         g.push_back(x);
      }
      else {
         *it = x; //更新第一个>=a[i]的元素的值
      }
   }
   cout << g.size() << "\n";
   //如果Lis中允许有相同的元素 g中需要修改的元素为>a[i]的第一个元素
   return 0;
}
