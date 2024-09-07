/*
  给定一个序列 任意选两个下标不同的数进行 +或 -  那么能够得到的数为 x=k * gcd(a1...an)  k为任意整数 （gcd 更损相减）

  对于 n=1 

  n>1:
  能够得到的数为 0 d 2*d 3*d (n-1)*d
  0--d 之间有 d-1个数
  长度为n的数组总共不能得到的数为 （n-1）*（d-1）
  之后和k进行讨论比较
  
  https://codeforces.com/contest/2008/problem/G
  
*/
#include<bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

void solve() {

    int n, k;
    cin >> n >> k;

    int g = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        g = gcd(g, a);
    }
    i64 t = 1LL * (g - 1) * (n - 1);
    if (n == 1) {
        cout << (k <= g ? k - 1 : k) << "\n";
    }
    else if (t < k) {
        k -= t;
        cout << (n - 1) * 1LL * g + k << "\n";
    }
    else {
        cout << (k / (g - 1) * 1LL * g - 1 + (k % (g - 1) == 0 ? 0 : (k % (g - 1) + 1))) << "\n";
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}
