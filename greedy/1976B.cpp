/*
   看b的最后一个元素是否在a变化过程中出现过
   之后模拟即可
   https://codeforces.com/contest/1976/problem/B
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int>a(n);
    vector<int>b(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n + 1; i++) {
        cin >> b[i];
    }
    ll ans = 1;
    bool ok = false;
    int t = b[n];
    int s = 1e9;
    for (int i = 0; i < n; i++) {
        if ((t >= a[i] && t <= b[i]) || (t <= a[i] && t >= b[i])) {
            ok = true;
        }
        s = min(s, abs(t - a[i]));
        s = min(s, abs(t - b[i]));
        ans += abs(b[i] - a[i]);
    }
    if (ok) {
        cout << ans << "\n";
        return;
    }
    cout << ans + s << "\n";
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
