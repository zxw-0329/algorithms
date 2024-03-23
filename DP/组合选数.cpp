
//从1-n中选m个数
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int n, m;
   cin >> n >> m;
   vector<int>a;
   vector<vector<int>>ans;
   auto dfs = [&](auto self, int k) { //选或不选(输入视角)
      int d = m - a.size();
      if (d == 0) {
         ans.push_back(a);//记录答案
         return;
      }
      if (k < n - d + 1) { //枚举到k时 还剩 t=n-k+1个数 如果(t>d) 可以不选第k个数
         self(self, k + 1); //不选
      }
      a.push_back(k);
      self(self, k + 1); //选
      a.pop_back();
      };
   auto dfs = [&](auto self, int k) { //枚举选哪个(答案视角)
      int d = m - a.size();
      if (d == 0) {
         ans.push_back(a);//记录答案
         return;
      }
      // if (k > n - d + 1) {剪枝,可以写在循环里 (n-k+1<d)
      //    return;
      // }
      for (int i = k; i <= n - d + 1; i++) {//dfs(i)->dfs(i+1)
         a.push_back(i);                    //      ->dfs(i+1)...
         dfs(i + 1);
         a.pop_back();
      }
      };
   dfs(dfs, 1);
   return 0;
}
