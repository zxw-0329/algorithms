/*

   ai < i < aj < j
   先考虑ai<i的元素  在考虑 i < aj
   https://codeforces.com/contest/1703/problem/F
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
   int n;
   cin >> n;
   vector<int>a(n + 1);
   for (int i = 1; i <= n; i++) {
      cin >> a[i];
      //a[i]--;
   }
   vector<int>b;
   ll ans = 0;
   for (int i = 1; i <= n; i++) {
      if (a[i] >= i)continue;
      b.push_back(i);
      ans += lower_bound(b.begin(), b.end(), a[i]) - b.begin();
   }
   cout << ans << "\n";
   //copy(b.begin(), b.end(), ostream_iterator<int>(cerr, " "));
  // cerr << "\n";
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
