/*

  思路:对于每一个字符串来说长度都 < 8 所以可以暴力枚举每个字符串的子串

  https://codeforces.com/contest/1703/problem/D
  
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
   int n;
   cin >> n;
   vector<string>a(n);
   map<string, int>m;
   for (int i = 0; i < n; i++) {
      cin >> a[i];
      m[a[i]] = 1;
   }
   vector<int>b(n);
   for (int i = 0; i < n; i++) {
      string t = "";
      auto s = a[i];
      int p = s.size();
      for (int j = 0; j < p - 1; j++) {
         t += s[j];
         if (m[t] && m[s.substr(j + 1, p - 1 - j)]) {
            b[i] = 1;
            break;
         }
      }
   }
   for (int i = 0; i < n; i++) {
      cout << b[i];
   }cout << "\n";
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
