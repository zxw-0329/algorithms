/*
 二分枚举最小化最大的分数
 
 在check时需要保证当前位置>=m且后面位置也要>=m才能分割
 https://atcoder.jp/contests/typical90/tasks/typical90_a
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int mod = 1e9 + 7;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int n, L;
   int k;
   cin >> n >> L;
   cin >> k;
   vector<int>a(n);
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }
   //for (auto i : a)cerr << i << " ";
   auto check = [&](ll m)->bool {
      int cnt = 0;
      ll s = 0;
      int pre = 0;
      for (int i = 0; i < n; i++) {
         s += a[i] - pre;
         if (s >= m && L - a[i] >= m) {
            s = 0;
            cnt++;
         }
         pre = a[i];
      }
      return cnt >= k;
      };
   ll l = 0, r = 1e9;
   while (l <= r) {
      ll mid = (l + r) / 2;
      if (check(mid)) {
         l = mid + 1;
      }
      else r = mid - 1;
     // cerr << r << "\n";
   }
   cout << l-1 << "\n";
   return 0;
}
