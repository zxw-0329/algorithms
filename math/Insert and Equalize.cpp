/*

2024 8.12 lc
把所有数变相等 应该都变为最大值为max  每次加的整数为x=gcd(max−a1,max−a2,…,max−an)

https://codeforces.com/contest/1902/problem/C
*/
#include<bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<int>a(n);
    map<int, int>p;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[a[i]] = 1;
    }
    if (n == 1) {
        cout << 1 << "\n";
        return;
    }
    sort(a.begin(), a.end());
    int g = 0;
    for (int i = 1; i < n; i++) {
        g = gcd(g, a[i] - a[i - 1]);
    }
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (a[n - 1] - a[i]) / g;
    }
    int k = -1;
    while (p.count(a[n - 1] + k * g)) {
        k--;
    }
    ans += -k;
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}Insert and Equalize
