/*
   思路: 以数字 3结尾 只与个位有关 所以可以舍弃其他位 保留个位数
    
 利用这些观察结果，我们可以发现只有 10个数字，而每个数字最多可以出现 3次。
 因此，我们总是可以将数组缩减为长度为 30 的数组。由于 30非常小
 我们可以蛮力求出所有三位数 ai+aj+ak，这样就足够快了。
   https://codeforces.com/contest/1692/problem/F
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
   int n;
   cin >> n;
   vector<int>a(10);
   for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a[x % 10]++;
   }
   for (int i = 0; i < 10; i++) {
      if (a[i] == 0)continue;
      for (int j = 0; j < 10; j++) {
         if (a[j] == 0)continue;
         if (i == j && a[i] == 1)continue;
         for (int k = 0; k < 10; k++) {
            if (a[k] == 0)continue;
            if (k == j && k == i && a[i] <= 2)continue;
            if (k == j && a[j] == 1)continue;
            if (k == i && a[i] == 1)continue;
            if ((i + j + k) % 10 == 3) {
               cout << "YES\n";
               return;
            }
         }
      }
   }
   cout << "NO\n";
  
    // int n;
    // std::cin >> n;
    
    // int cnt[10] = {};
    // std::vector<int> a;
    // for (int i = 0; i < n; i++) {
    //     int x;
    //     std::cin >> x;
    //     x %= 10;
    //     if (cnt[x] < 3) {
    //         cnt[x]++;
    //         a.push_back(x);
    //     }
    // }
    
    // n = a.size();
    // for (int i = 0; i < n; i++) {
    //     for (int j = i + 1; j < n; j++) {
    //         for (int k = j + 1; k < n; k++) {
    //             if ((a[i] + a[j] + a[k]) % 10 == 3) {
    //                 std::cout << "YES\n";
    //                 return;
    //             }
    //         }
    //     }
    // }
    
    // std::cout << "NO\n";
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
