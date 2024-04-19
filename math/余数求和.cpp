/*
  k % i = k - i * (k/i)
  
  整数分块

  性质1. ：分块的个数 <= 2 * sqrt(n) ;
           1. i < = sqrt(n)  有{n/1，n/2,n/3,...,n/sqrt(n)}  sqrt(n)个数
           2. i > sqrt(n)    n/i <= sqrt(n)  n/i之多有sqrt(n)个数
  性质2. ：i所在块的值 k =floor( n/i )  k <= n/i  floor( n/K ) >= floor(n/(n/i))
                                                floor( n/k ) = i;
           imax=n/k (把k带入)  r=n/(n/i)

  https://www.luogu.com.cn/problem/P2261
 */
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int inf = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    ll ans = n * 1LL * k;
    int r;
    for (int i = 1; i <= n; i = r + 1) {
        if (k / i == 0)break;
        r = min(k / (k / i), n);
        ans -= (k / i) * 1LL * (i + r) * (r - i + 1) / 2;
    }
    cout << ans << "\n";
    return 0;
}
