#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 5000011;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int n,p;
   cin >> n >> p;
   vector<int>a(n);
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }
   sort(a.begin(), a.end());
   int ans = 0;
   for (int k = a[0]; k <= a[n - 1]; k++) {
      int up = p + k;
      int lo = k - p;
      int l = lower_bound(a.begin(), a.end(), lo)-a.begin();
      int r = upper_bound(a.begin(), a.end(), up) - a.begin();
      ans = max(ans, r - l);
   }
   cout << ans << "\n";
   return 0;
}
