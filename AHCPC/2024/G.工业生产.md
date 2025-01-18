


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

    for (int i = 2; i <= 60; i++) {
        vector<i64>pw(i, 1);

        int pos = 0;
        while (true) {
            i64 p = 1;
            for (auto i : pw) {
                p *= i;
            }
            if (p < n) {
                pw[pos++] += 1;
                pos %= i;
            }
            else break;
        }
        i64 sum = 0;
        for (auto x : pw) {
            sum += x;
        }
        ans = min(ans, sum + (i - 1) * m);
    }
    cout << ans << "\n";
}
int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

```
