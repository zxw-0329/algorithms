/*

https://codeforces.com/contest/1366/problem/B
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n, x, m;
    cin >> n >> x >> m;
    int lo = x, up = x;
    while (m--) {
        int l, r;
        cin >> l >> r;
        if (l <= up && lo <= r) {
            lo = min(lo, l);
            up = max(up, r);
        }
    }
    cout << up - lo + 1 << "\n";
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
