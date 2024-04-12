/*
 周期的长度有哪些可能性？显然，它一定是 n的除数。因此，解决的办法是检查 n的所有除数，找出最小的一个。
 要检查长度 l是否有效，可以将长度为 l的前缀与 s相乘，直到长度相同，然后检查相差多少。但是，不同的字母也可能出现在后缀中(例如， hshaha和 l=2)，
 因此我们也要对长度为 l的后缀进行同样的检查。如果其中之一为真，则输出 l
 
  https://codeforces.com/contest/1950/problem/E
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
   int n;
   cin >> n;
   string s;
   cin >> s;
   for (int len = 1; len <= n; len++) {
      if (n % len != 0)continue;
      string pre = s.substr(0, len);
      string last = s.substr(n - len, len);
      int p = 0, l = 0;
      for (int j = 0; j < n; j++) {
         if (s[j] != pre[j % len]) {
            p++;
         }
         if (s[j] != last[j % len]) {
            l++;
         }
      }
      if (l <= 1 || p <= 1) {
         cout << len << "\n";
         return;
      }
   }
}
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int t = 1;
   cin >> t;
   while (t--) {
      solve();
   }
   return 0;
}
