定义： $f(N) = 1^1\cdot 2^2 \cdot 3^3\cdot ...\cdot (N − 1)^{N - 1}\cdot N^N$

求表达式的值: $\frac{f(n)}{f(r)\cdot f(n-r)}$

由于答案是整数，输出它对 m 的取模结果

对于计算 $\frac{f(n)}{f(r)\cdot f(n-r)} \pmod m$，如果 $f(r)$ 和 $f(n-r)$ 与 m 互质，那么这个问题可以通过模逆元（扩展欧几里得算法）来解决。

另一种方法是，从 2 到 n 取每个质因数 P，对于每个质因数，计算 x（使得 $P^x$是 $f(n)$ 的一个因数的最大值x）、y（使得 $P^y$ 是 $f(r)$ 的一个因数的最大值y）以及 z（使得 $P^z$是 $f(n-r)$的一个因数的最大值z）。
结果将是对于从 2 到 n 的每个质数 P, $\prod\limits_{2\leq P\leq n}P^{x-y-z}$。

显然上述两种方法不是最佳方案，第一种方法仅在 $\gcd(f(i),m) = 1$ 时有效，对于另一种在时间上可能不满足题目要求。

对于第一种方法进行改进：先预处理出m的质因数 , 我们定义： $\mathbf{k(i)=i^i}$ , **并从中去除m的所有质因数**,

例 $m=6 , n=4$ ,将m质因数分解 $m = 2\times 3$

$k(1)=1^1$

$k(2)=1^2$ 去除了所有2的因数

$k(3)=1^3$ 去除了所有3的因数

$k(4)=1^4$ 去除了所有2的因数

定义： $g(i)=g(i-1)\cdot k(i)$，现在 $g(i)$ 与 m 互质，可使用逆元来求答案,但结果并不完整 , 现在求的是 $g(n)\cdot inv(g(r))\cdot inv(g(n-r))\pmod m$,这是去掉m的全部质因数的答案，还需乘上m的所有质因数P
即 $\prod\limits_{P\mid m }P^{x-y-z}$， 

$x$是将 $f(n)$ 按m的质因数分解后 P 的个数

$y$是将 $f(r)$ 按m的质因数分解后 P 的个数

$z$是将 $f(n-r)$ 按m的质因数分解后 P 的个数

乘过m的所有质因数之后，就是最终结果，m的因数个数很少（最坏情况下 $2\times 3\times 5\times 7\times 11\times 13\times 17\times 19\times 23\times 27\gt 10^9$）可以预处理 $f(i)$对于m中每个质因数P，计算有多少个P，可以通过前缀和进行处理

对于求逆元，由于m可能不是质数，故无法直接通过费马小定理直接求 ( $power(x,m-2)$ ),可以用exgcd求

C++代码如下
``` cpp []
#include<bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

int power(int a, i64 b, int m) {
    if (b < 0) {
        return 0;
    }
    int ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * 1LL * a % m;
        }
        b >>= 1;
        a = a * 1LL * a % m;
    }
    return ans;
}
int exgcd(int a, int b, int& x, int& y) {//a* x + b * y = 1; 求x
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
int inv(int a,int m) {

    int x, y;
    int g = exgcd(a, m, x, y);

    return (x % m + m) % m;
}
void solve() {

    int n, q, r;
    int m;
    cin >> n >> m >> q;

    vector<int>p;
    int y = m;
    for (int i = 2; i * 1LL * i <= y; i++) {
        if (y % i == 0) {
            p.push_back(i);
            while (y % i == 0) {
                y /= i;
            }
        }
    }
    if (y > 1) {
        p.push_back(y);
    }

    vector<int>g(n + 1);
    vector<vector<i64>>cnt(n + 1, vector<i64>(p.size()));

    vector<int>g_inv(n + 1);
    g[1] = 1; g_inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        int x = i;
        for (int j = 0; j < p.size(); j++) {
            int c = 0;
            while (x % p[j] == 0) {
                x /= p[j];
                c++;
            }
            cnt[i][j] = cnt[i - 1][j] + c * 1LL * i;//计算f(i)有多少个p[j]，p[j]是m的质因数
        }
        assert(gcd(x, m) == 1);
        g[i] = g[i - 1] * 1LL * power(x, i, m) % m;//计算去除m的所有质因数后的i^i的值
        g_inv[i] = inv(g[i], m);
    }

    while (q--) {
        cin >> r;
        int s = 1;
        for (int j = 0; j < p.size(); j++) {
            s = (s * 1LL * power(p[j], cnt[n][j] - cnt[r][j] - cnt[n - r][j], m)) % m;
        }
        cout << (g[n] * 1LL * g_inv[r] % m * g_inv[n - r] % m * s) % m << "\n";
    }
}
int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```
https://www.codechef.com/problems/POWERMUL?tab=statement

https://discuss.codechef.com/t/fombinatorial-editorial/8136
