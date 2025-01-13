
$f(x)=k^2+1 \quad for\ x=2^k$

$f(x)=f(y)+f(z) \quad for\ (x=y+z)\ and\ (y \\& z=0)$

计算 $\sum\limits_{i=1}^{n}f(x)$，题目给出的n用了16进制表示

观察可知，对于 $x!=2^k$ 时, $f(x)=\sum\limits_{i=0}^{\log(x)}{(x>>i \\& 1) * (i * i + 1)}$

举例说明, $1$ 到 $n=6_{(10)}$ 的二进制表示如下：

$001\quad 010\quad 011\quad 100\quad 101\quad 110$，

考虑计算 1 到 n 的每个比特位上有多少个 1。

**最低位**：相当于计算 1 到 n 中有多少个奇数，这有 $\Big\lfloor \frac{n+1}{2} \Big\rfloor$

**次低位**：我们可以把每个数都除以 2（右移 1 位）,忽略 00，得到: $01\quad 01\quad 10\quad 10\quad 11$

​同样地，考虑其中的奇数, 发现 $1$ 到 $\Big\lfloor \frac{n}{2} \Big\rfloor - 1$ 中的每个奇数都出现了 2 次，但是 $\Big\lfloor \frac{n}{2} \Big\rfloor$ 只出现了 1 次。所以次低位中有 3 个 1。

**从右往左第三位**：我们可以把每个数都除以 $2^2=4$ (右移 2 位)。同样地，考虑其中的奇数,发现 1 到 $\Big\lfloor \frac{n}{4} \Big\rfloor - 1$ 中的每个奇数都出现了 4 次 , 但是 $\Big\lfloor \frac{n}{4} \Big\rfloor = 1$ 出现了 3 次
。这个 3 怎么算？我们可以把 $n = 6$ 和 $2^2-1=3$ 取 AND，得到 2 , 说明把 $\Big\lfloor \frac{n}{4} \Big\rfloor $作为前缀的二进制数，最低位和次低位是 $00,01,10$ 这有 $2+1=3$ 个。

一般地，从低到高第 i 位（i 从 0 开始）的 1 的个数，我们分两部分计算：

1. 设 $n=\Big\lfloor \frac{n}{2^i} \Big\rfloor$ , 从 1 到 n−1 有 $\Big\lfloor \frac{n}{2} \Big\rfloor$ 个奇数，每个奇数作为 1 到 num 的二进制数的前缀,出现了 $2^i$ 次,
所以一共有 $\Big\lfloor \frac{n}{2} \Big\rfloor \times 2^i$ 个 $1$

2. n 单独作为 1 到 n 的二进制数的前缀,出现了 $(n \\& (2^i−1)) + 1$ 次,如果 n 是奇数,那么它为第 i 位贡献了 $(n\\& (2^i−1))+1$ 个 1，否则为第 i 位贡献了 0 个 1

C++ 做法如下——
``` cpp []
#include<bits/stdc++.h>

using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

unordered_map<char, string>mp = {
        {'0',"0000"},{'1',"0001"},{'2',"0010"},{'3',"0011"},
        {'4',"0100"},{'5',"0101"},{'6',"0110"},{'7',"0111"},
        {'8',"1000"},{'9',"1001"},{'a',"1010"},{'b',"1011"},
        {'c',"1100"},{'d',"1101"},{'e',"1110"},{'f',"1111"}
};
int pw[100001];
constexpr int mod = 998244353;
int power(int a, int b) {

    int ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * 1LL * a % mod;
        }

        b >>= 1;
        a = a * 1LL * a % mod;
    }
    return ans;
}
/*
void solve() {

    int m;
    cin >> m;
    string s;
    cin >> s;
    int n = s.size();
    string t;
    for (int i = 0; i < n; i++) {
        t += mp[s[i]];
    }
    int res = 0;
    n = t.size();
    for (int i = 0; i < m; i++) {
        int x = 0;
        for (int j = n - i - 2, k = 0; j >= 0; j--, k++) {
            x = (x + (t[j] - '0') * power(2, k)) % mod;
        }
        res = (res + x * 1LL * power(2, i) % mod * (i * i + 1)) % mod;

        if (t[n - i - 1] == '1') {
            int p = 0;
            for (int j = 0; j < i; j++) {
                p = (p + (t[n - 1 - j] - '0') * power(2, j) % mod) % mod;
            }
            res = (res + (p + 1) * 1LL * (i * i + 1) % mod) % mod;
        }
    }
    cout << res << "\n";
}
*/
void test() {
    int m;
    cin >> m;
    string s;
    cin >> s;
    int n = s.size();
    string t;
    for (int i = 0; i < n; i++) {
        t = t + mp[s[i]];
    }
    reverse(t.begin(), t.end());
    while (t.back() == '0' && t.size() > 1)t.pop_back();
    n = t.size();
    vector<int>p(n + 1);

    for (int i = 0; i < n; i++) {//计算 s 的前缀和
        p[i + 1] = p[i] + (t[i] - '0') * pw[i];
    }
    //cerr << p[n] << "\n";
    int res = 0;
    for (int i = 0; i < m; i++) {
        //考虑 二进制 0- t 在第i位有多少个 1
        int x = ((p[n] - p[i + 1] + mod) % mod * 1LL * power(power(2, i + 1), mod - 2)) % mod;// y = n>>i --> 则第i位有 (y>>1)<<i  合并之后 x = (n>>(i+1));
        res = (res + x * 1LL * pw[i] % mod * (i * i + 1)) % mod;// (x << i)

        if (t[i] == '1') {//如果第i位是1，贡献 (n&((1<<i) - 1)) + 1 个 1 ,相当于算n在二进制表示下后i个位的值,可以看solve函数里面的计算
            res = (res + (p[i] + 1) * 1LL * (i * i + 1) % mod) % mod;
        }
    }
    cout << res << "\n";
}

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    pw[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        pw[i] = pw[i - 1] * 1LL * 2 % mod;
    }
    int t;
    cin >> t;
    while (t--) {
        //  solve();
        test();
    }
    return 0;
}
```
python 做法如下——
``` python []
def f(x, k): # 0 -> x   x在第 x + 1 个位置
    y = 1 << (k + 1)  # 循环节长度（2^k个0 和 2^k个1）

    y1 = y // 2  # 计算每部分有多少个1  还可以写成 y1 = 1 << k
    x += 1
    ans = 0
    ans += (x // y) * y1  # 计算有多少循环节包含完整的y1
    r = x % y  # 剩下多长
    r -= y1  # 把连续2^k个0减掉
    if r > 0:
        ans += r
    # print(f"k = {k} ,ans = {ans}")
    return ans


def f1(y):
    if '0' <= y <= '9':
        return ord(y) - ord('0')
    return ord(y) - ord('a') + 10


MOD = 998244353
t = int(input())
for _ in range(t):
    m = int(input())
    n = input()
    l = len(n)
    s = 0
    for i in range(l):
        s += f1(n[l - i - 1]) * (16 ** i)

    ans = 0
    for i in range(m):
        ans += f(s, i) * (i * i + 1)
    ans %= MOD
    print(ans)

```
