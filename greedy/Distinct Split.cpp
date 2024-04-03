/*

  我的做法:分别扫描前后缀字母的次数的值 ，然后枚举从那个分割的值最大

  让我们检查所有 ( 1≤i≤n−1 ) 的所有拆分点 i。
  我们将拆分点表示为第一个字符串的最后一个索引(所有剩余字符都将进入第二个字符串)。我们需要动态统计 a(第一个字符串)和 b(第二个字符串)
  两个字符串中的不同字符数。(第二个字符串）中的不同字符数。为此，我们可以使用两个频率数组（当字符的频率大于零时，在字符串 a或 b
  的独立计数中添加一个。
  https://codeforces.com/contest/1791/problem/D
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
   int n;
   cin >> n;
   string s;
   cin >> s;
   map<int, int>m1, m2;
   vector<int>pre(n), last(n);
   last[n - 1] = pre[0] = 1;
   m2[s[n - 1]] = 1;
   m1[s[0]] = 1;
   for (int i = n - 2; i >= 0; i--) {
      if (m2[s[i]]) {
         last[i] = last[i + 1];
      }
      else last[i] = last[i + 1] + 1;
      m2[s[i]] = 1;
   }
   for (int i = 1; i < n; i++) {
      if (m1[s[i]]) {
         pre[i] = pre[i - 1];
      }
      else pre[i] = pre[i - 1] + 1;
      m1[s[i]] = 1;
   }
   int ans = 0;
   for (int i = 1; i < n; i++) {
      ans = max(ans, pre[i - 1] + last[i]);
   }
   cout << ans << "\n";
    //  int n;
    // std::cin >> n;
    
    // std::string s;
    // std::cin >> s;
    
    // std::array<int, 26> cntl{}, cntr{};
    // int res = 0;
    // for (auto c : s) {
    //     res += !cntr[c - 'a']++;
    // }
    // int ans = res;
    // for (auto c : s) {
    //     res += !cntl[c - 'a']++;
    //     res -= !--cntr[c - 'a'];
    //     ans = std::max(ans, res);
    // }
    // std::cout << ans << "\n";
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
