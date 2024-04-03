/*
  根据题意: 显然二分答案 (还有更快的做法)

对于给定的 h值，如果是 h≥ai，在 i-th列中我们需要 h−ai单位的水，反之则需要 0单位的水。(这等于 max(h−ai,0)，为什么呢？）
因此，我们可以计算所有 n列的水量，只需遍历并求和每列所需的总水量，看看它是否不大于 x。
然后对 h的最优值进行二进制搜索。由于最佳高度可能是 ai+x，因此模型解法使用的起始边界为 l=0、r=2ai+ε
 。因此每个测试案例的复杂度为 O(nlogai)
 
  https://codeforces.com/contest/1873/problem/E

  https://codeforces.com/edu/courses
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
   int n, x;
   cin >> n >> x;
   vector<int>a(n);
 
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }
   auto check = [&](ll h)->bool {
      ll t = 0;
      for (int i = 0; i < n; i++) {
         if (a[i] >= h)continue;
         t += h - a[i];
      }
      return t <= x;
      };
   ll l = 1, r = 2e9;
 
   while (l <= r) {
      ll mid = (l + r) >> 1;
      if (check(mid)) {
         l = mid + 1;
      }
      else {
         r = mid - 1;
      }
   }
    if (!check(l))l--;
   cout << l << "\n";
   // ll l = 0, r = 2e9;
   // int ans = 0;
   // while (l < r) {
   //    ll mid = (l + r + 1) /2;  往上取整
   //    if (check(mid)) {
   //       l = mid;
   //    }
   //    else {
   //       r = mid - 1;
   //    }
   // }
   // cout << l << "\n";

    // int n, x;
    // std::cin >> n >> x;
    
    // std::vector<int> a(n);
    // for (int i = 0; i < n; i++) {
    //     std::cin >> a[i];
    // }
    // std::sort(a.begin(), a.end());
    // i64 sum = 0;
    // i64 ans = 0;
    // for (int i = 0; i < n; i++) {
    //     if (i && sum + 1LL * i * (a[i] - a[i - 1]) > x) {
    //         ans = a[i - 1] + (x - sum) / i;
    //         break;
    //     }
    //     if (i) {
    //         sum += 1LL * i * (a[i] - a[i - 1]);
    //     }
    //     if (i == n - 1) {
    //         ans = a[i] + (x - sum) / n;
    //     }
    // }
    // std::cout << ans << "\n";
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
