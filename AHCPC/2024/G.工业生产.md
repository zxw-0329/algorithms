**1.** 考虑枚举扩大产能的次数，对于有 $i$ 次扩产，对于其中的每一次积累两周，最后总利润能达到 $2^{i+1}$，次数最多枚举到 $\log n$ 就可以了，对于题目的 $n = 10^{12}$ 枚举40次也就可以了

**2.**  对于固定的产能次数 $i$ 次，相当于生产计划分成了 $i+1$ 段，每段投入若干的时间,可以用一个  $vector\< long\ long \>pw(i+1,1)$ 记录，其中pw[i]代表投入的时间，最后利润为： $\prod\limits_{0 <= j <= i }p[j]$，则投入的总时间为： $i*m+\sum\limits_{j=0}^{i}p[j] $，最后答案取最小值即可

**3.** 对于 $vector\< long\ long \>pw(i+1,1)$ 可以暴力调整每段的投入的时间数，当 $\prod\limits_{0 <= j <= i }p[j] >= n$ 结束调整。

**4.** 对于优化暴力，由于求总时间最小即 $i*m+\sum\limits_{j=0}^{i}p[j]$ , 对于每一个 i，i 固定后 i * m 就为常数，显然是求 $\sum\limits_{j=0}^{i}p[j]$最小值满足 $\prod\limits_{0 <= j <= i }p[j] >= n$，所以可以直接二分答案， 二分枚举 $\sum\limits_{j=0}^{i}p[j]$，注意到对于固定的 $\sum\limits_{j=0}^{i}p[j]$ ，要让 $\prod\limits_{0 <= j <= i }p[j]$最大，应该尽量均匀分配时间


时间复杂度为 $\sum\limits_{k=2}^{60}\mathcal{O}(k*log(s) + k)$（C++代码）

### 具体代码如下——

C++做法如下——

``` cpp []
#include<bits/stdc++.h>

using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

void solve() {

    i64 n, m;
    cin >> n >> m;
    i64 ans = n;

    for (int i = 1; i <= 40; i++) {
        vector<i64>pw(i + 1, 1);

        int pos = 0;
        while (true) {
            i64 p = 1;
            for (auto j : pw) {
                p *= j;
                if (p >= n)break;
            }
            if (p < n) {
                pw[pos++] += 1;
                pos %= i + 1;
            }
            else break;
        }
        i64 sum = 0;
        for (auto x : pw) {
            sum += x;
        }
        ans = min(ans, sum + i * m);
    }
    cout << ans << "\n";
}
int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

```

Python代码如下——

``` python []

s, m = list(map(int, input().split()))
N = 40
ans = s


def check(k, x):
    t = k // x
    a = [t] * x
    k -= t * x
    j = 0
    while k > 0:
        a[j] += 1
        k -= 1
        j = (j + 1) % x
    p = 1
    for k in range(x):
        p *= a[k]
    return p >= s


for i in range(1, N):
    l, r = 0, s
    while l <= r:
        mid = (l + r) >> 1
        if check(mid, i + 1):
            r = mid - 1
        else:
            l = mid + 1
    ans = min(ans, i * m + l)

print(ans)


```
