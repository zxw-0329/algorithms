#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int n;
   cin >> n;
   vector<int>col(n);//记录第i行的位置
   vector<bool>b(n, false);//记录第i列是否被用过;
   vector<vector<string>>ans;
   auto check = [&](int x, int y)->bool {
      for (int i = 0; i < x; i++) {//对于前面x-1行 取出第i行皇后所在的列c
         int c = col[i];           // (i+t,c+t)==(x,y)或(i+t,c-t)==(x,y);
         if (x + y == i + c || x - y == i - c) {//t表示往右下或左下走的次数
            return true;
         }
      }
      return false;
      };
   auto dfs = [&](auto self, int k) {
      if (k == n) {
         vector<string>s(n);
         for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
               if (j != col[i]) {
                  s[i].push_back('.');
               }
               else s[i].push_back('Q');
            }
         }
         ans.push_back(s);
         return;
      }
      for (int i = 0; i < n; i++) {
         if (b[i] || check(k, i)) {
            continue;
         }
         col[k] = i;
         b[i] = true;
         self(self, k + 1);
         b[i] = false;
      }
      };
   dfs(dfs, 0);
   for (auto t : ans) {
      for (auto s : t) {
         cout << s << "\n";
      }
      cout << "\n";
   }
   return 0;
}
