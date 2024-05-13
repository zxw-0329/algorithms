/*
对等式 ai^2= k × aj 两边开根得到 ai =√k × aj，
考虑找到最小的 k 满足 k × aj 为平方数，即将 aj中奇数次幂的质因子变为偶数次幂。
考虑倒序枚举 ai，将所有后缀的√k × aj 在桶 f 中计数，枚举 ai 时需要遍历累加 ai 所有的约数。

*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int inf = 1e9;
constexpr int N = 1e6;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // vector<int>g[N + 2];
    // for (int i = 1; i <= N; i++) {
    //     for (int j = i; j <= N; j += i) {
    //         g[j].push_back(i);
    //     }
    // }
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    map<int, int>ma;
    auto fac = [&](int x) {
        ll p = x;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                int cnt = 0;
                while (x % i == 0) {
                    x /= i;
                    cnt++;
                }
                if (cnt & 1) {
                    p *= i;
                }
            }
        }
        if (x > 1) {
            p *= x;
        }
        return p;
        };
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                if (a[i] / j != j) {
                    ans += ma[a[i] / j];
                }
                ans += ma[j];
            }
        }
        int t = sqrt(fac(a[i]));
        ma[t]++;
    }
    cout << ans << "\n";
    return 0;
}
