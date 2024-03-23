#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int n, m;
   cin >> n >> m;
   vector<vector<int>> ans;
   vector<int>a;
   // function<void(int, int)>dfs = [&](int k, int s) {//枚举选哪个(从后往前)
   //    int d = m - a.size();//还要选 d 个数
   //    if (s < 0 || s >(k * 2 - d + 1) * d / 2) {
   //       return;  //剪枝 s<0 ||后面d个最大的数相加<s;
   //    }
   //    if (d == 0) {
   //       ans.push_back(a);
   //       return;
   //    }
   //    for (int i = k; i >= d; i--) {//可以枚举到第d个数
   //       a.push_back(i);
   //       dfs(i - 1, s - i);
   //       a.pop_back();
   //    }
   //    };
   // dfs(9, n);
   // function<void(int, int)>dfs = [&](int k, int s) {//枚举选哪个(从前往后)
   //    int d = m - a.size();//还要选 d 个数
   //    if (s < 0 || s >(9 + 9 - d + 1) * d / 2) {
   //       return;  //剪枝 s<0 ||后面d个最大的数相加<s;
   //    }
   //    if (d == 0) {
   //       ans.push_back(a);
   //       return;
   //    }
   //    for (int i = k; i <= 9 - d + 1; i++) {//可以枚举到第d个数
   //       a.push_back(i);
   //       dfs(i + 1, s - i);
   //       a.pop_back();
   //    }
   //    };
   // dfs(1, n);
   function<void(int, int)>dfs = [&](int k, int s) {//选或不选(从前往后)
      int d = m - a.size();//还要选 d 个数
      if (s < 0 || s >(9 + 9 - d + 1) * d / 2) {
         return;  //剪枝 s<0 ||后面d个最大的数相加<s;
      }
      if (d == 0) {
         ans.push_back(a);
         return;
      }
      if (k < n - d + 1) {//枚举到k时 还剩 t=n-k+1个数 如果(t>d) 可以不选第k个数
         dfs(k + 1, s);
      }
      a.push_back(k);
      dfs(k + 1, s - k);
      a.pop_back();
      };
   dfs(1, n);
   return 0;
}
