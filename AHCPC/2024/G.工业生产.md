**1.** 考虑枚举扩大产能的次数，对于有 $i$ 次扩产，对于其中的每一次积累两周，最后总利润能达到 $2^{i+1}$，次数最多枚举到 $\log n$ 就可以了，对于题目的 $n = 10^{12}$ 枚举40次也就可以了

**2.**  对于固定的产能次数 $i$ 次，相当于生产计划分成了 $i+1$ 段，每段投入若干的时间,可以用一个  $vector\< long\ long \>pw(i+1,1)$ 记录，其中pw[i]代表投入的时间，最后利润为： $\prod\limits_{0 <= j <= i }p[j]$，则投入的总时间为： $i*m+\sum\limits_{j=0}^{i}p[j] $，最后答案取最小值即可

**3.** 对于 $vector\< long\ long \>pw(i+1,1)$ 可以暴力调整每段的投入的时间数，当 $\prod\limits_{0 <= j <= i }p[j] >= n$ 结束调整。

时间复杂度为 $\sum\limits_{k=0}^{60}\mathcal{O}(k*log(s) + k)$

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
