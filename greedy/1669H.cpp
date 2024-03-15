/*
   按题目要求 用一个数组存所有数在 该位 1 出现的次数
   先从最高位开始是否能在k步内变为1 依次往下进行
   
   https://codeforces.com/contest/1669/problem/H
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
   int n, k;
   cin >> n >> k;
   vector<int>b(32);
   for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      for (int j = 0; j < 31; j++) {
         if ((x >> j) & 1) {
            b[j]++;
         }
      }
   }
   ll s = 0;
   for (int i = 30; i >= 0; i--) {
      if (b[i] + k >= n) {
         k -= n - b[i];
         b[i] = n;
         s |= (1LL << i);
      }
   }
   // ll s = 0;
   // for (int i = 0; i <= 30; i++) {
   //    if (b[i] == n) {
   //       s += (1LL << i);
   //    }
   // }
   cout << s << "\n";
}
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int t;
   cin >> t;
   while (t--) {
      solve();
   }
   return 0;
}
