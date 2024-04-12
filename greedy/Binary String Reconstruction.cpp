/*
  自己的思路:
  构造:先构造长度为2全为1 的字符串 在构造长度为2全为0的  最后构造长度为2为10的
  如果构造10出现在00前面 
  对于数据 1 2 0 就构造不出来  构造出来的答案为(1010): 因为错误的认为当有 10 串时 是以0结尾(https://codeforces.com/contest/1352/submission/256211341)

  题解
  分别考虑情况 n1=0并打印出相应的 n0+1个 0 或 n2+1 个 1。
  现在，我们的字符串至少有一对 "10 "或 "01"。让我们组成 "101010 ...10"，长度为 n1+1。这样，所有总和为 1的子串都得到了满足。
  现在，让我们在第一个 0 之前插入 n0个 0，这样我们就满足了总和为 0 的子串。
  然后在第一个 1 之前插入 n2个 1，这样就满足了子串的总和 2。
  
  https://codeforces.com/contest/1352/problem/F
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
   int n0, n1, n2;

   cin >> n0 >> n1 >> n2;
   if (n2) {
      int t2 = n2 + 1;
      for (int i = 0; i < t2; i++) {
         cout << 1;
      }
   }
   if (n0) {
      int t0 = n0 + 1;
      if (n2) {
         n1--;
      }
      for (int i = 0; i < t0; i++) {
         cout << 0;
      }
   }
   if (n1) {
      int pre = 1;
      int t1 = n1 + 1;
      if (n0) {
         cout << 1;
         t1 = n1 - 1;
         pre = 0;
      }
      else if (n2) {
         cout << 0;
         t1 = n1 - 1;
      }
      for (int i = 0; i < t1; i++) {
         cout << pre;
         pre ^= 1;
      }
   }


   cout << "\n";
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
