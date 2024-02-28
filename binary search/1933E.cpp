//二分+前缀和    https://codeforces.com/contest/1933/problem/E;
//找到第一个 >=u 的位置 最优
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll calc(int u, int x) {
    return 1LL * (u + u - x + 1) * x / 2;
}
void solve() {
    int n;
    cin >> n;
    vector<int>a(n);
    vector<int>s(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s[i + 1] = s[i] + a[i];
    }
    int q;
    cin >> q;
    while (q--) {
        int l, u;
        cin >> l >> u;
        l--;
        int j = l+1;
        int k = n;
      //  int r= lower_bound(s.begin() + l + 1, s.end(), s[l] + u) - s.begin();
        while (j <= k) {
            int mid = (j + k ) >> 1;
            if (s[mid]<u+s[l]) {
               j = mid + 1;
            }
            else {
                k = mid - 1;
            }
        }
        ll ans = -1E18;
        int r = -1;
        if (j <= n) {
            if (calc(u, s[j] - s[l]) > ans) {
                ans = calc(u, s[j] - s[l]);
                r = j;
            }
        }
        if (j - 1 > l) {
            if (calc(u, s[j - 1] - s[l]) >= ans) {
                ans = calc(u, s[j - 1] - s[l]);
                r = j - 1;
            }
        }
        cout << r << " \n"[q == 0];
    }
    //cout << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
