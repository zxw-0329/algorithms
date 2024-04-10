/*
  假设答案只是 k(-个正整数)，我们应该将其 "右移 "一些数字。每个n的乘数都会将我们的答案向右移动 1
  这样的乘数为 need=⌊k−1/n−1⌋
  其中 ⌊x/y⌋是 x除以 y的四舍五入。
  因此，最终答案是 k+need( k/-个正整数，所需的跳过整数乘数为 n)。

   对于 n=3,k=7
   找规律
   1 2   长度为(n-1)
   4 5
   7 8
   10 11
   ....
   对于每一组都有( n-1 )个数
   每组开头与上一组的开头 差值为 n  且首项为 1 的 等差数列
   所以可以算出有几组 k%=(n-1) 还剩下几个数单独计算
   
   https://codeforces.com/contest/1352/problem/C
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
   ll n, k;
   cin >> n >> k;
   ll t = k / (n - 1);
   k %= (n - 1);
   //  cerr << (t - 1) * n + 1+ (n - 2) << "\n";
   ll s = (t - 1) * n + 1 + (n - 2) + (k == 0 ? 0 : k - 1 + 2);
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
