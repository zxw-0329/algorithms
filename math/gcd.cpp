/*
 1. https://codeforces.com/problemset/problem/1925/B
  找到n个数使这n个的和等于x
  且这个n个数的gcd最大
  
  GCD(a1,a2,a3,...,an) = GCD(a1,a1+a2,a1+a2+a3,...,a1+a2+a3+...+an)
  所能达到的最大 GCD 总是 x 的除数。
  so: GCD(a1,a2,a3,...,an) = GCD(a1,a1+a2,a1+a2+a3,...,x)
  枚举x的因子：d
  如果n*d<=x -->可以构造 :d d d d ... x-(n-1)*d;
  满足的d取最大值即可
  
  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int inf = 1e9;
void solve() {
    int x, n;
    cin >> x >> n;
    int ans = 0;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            if (n * 1LL * i <= x) {
                ans = max(ans, i);
            }
            if (x / i != i) {
                if (n * 1LL * (x / i) <= x) {
                    ans = max(ans, x / i);
                }
            }
        }
    }
    cout << ans << "\n";
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
