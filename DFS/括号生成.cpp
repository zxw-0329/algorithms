#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int n;
   cin >> n;
   int m = 2 * n;
   vector<vector<char>> ans;
   vector<char>a;
   function<void(int, int)>dfs = [&](int k, int left) {//选或不选
      if (k == m) {
         ans.push_back(a);
         return;
      }
      if (left < n) {//可以选左括号
         a.push_back('(');
         dfs(k + 1, left + 1);
         a.pop_back();
      }
      if (k - left < left) {//left + right = k; 对于一个位置右括号数量要严格小于左括号
         a.push_back(')');
         dfs(k + 1, left);
         a.pop_back();
      }
      };
   dfs(0, 0);
   for (int i = 0; i < ans.size(); i++) {
      for (auto c : ans[i]) {
         cout << c << " ";
      }
      cout << "\n";
   }
   return 0;
}
