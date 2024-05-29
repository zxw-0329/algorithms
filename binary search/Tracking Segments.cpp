#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
int tr[N];
int n;
void update(int x, int  k) {
    while (x <= n) {
        tr[x] += k;
        x += x & (-x);
    }
}
int query(int x) {
    int s = 0;
    while (x) {
        s += tr[x];
        x -= x & (-x);
    }
    return s;

}
void solve() {
    memset(tr, 0, sizeof(tr));
    int m;
    cin >> n >> m;
    vector<pair<int, int>>a(m);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if (x > y)swap(x, y);
        a[i] = { x,y };
    }
    int q;
    cin >> q;
    vector<int>c(q);
    for (int i = 0; i < q; i++) {
        cin >> c[i];
        c[i]--;
    }
    // for (int i = 0; i < q; i++) {
    //     update(c[i], 1);
    //     for (int j = 0; j < m; j++) {
    //         auto [l, r] = a[j];
    //         int s = query(r) - query(l - 1);
    //         int t = r - l + 1;
    //       //  cerr << s << " " << "\n";
    //         if (s > t - s) {
    //             cout << i + 1 << "\n";
    //             return;
    //         }
    //     }
    // }

    auto check = [&](int k)->bool {
        //   if (k < 0 || k >= m)return false;
        vector<int>s(n + 1);
        for (int i = 0; i < k; i++) {
            int x = c[i];
            //x--;
            s[x + 1] = 1;
        }
        for (int i = 1; i <= n; i++) {
            s[i] += s[i - 1];
        }
        bool ok = false;
        for (int i = 0; i < m; i++) {
            auto [l, r] = a[i];
            int p = s[r] - s[l - 1];
            if (p > r - l + 1 - p) {
                ok = true;
                break;
            }
        }
        return ok;
        };
    int l = 0, r = q;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    int ans = l;
    if (ans > q) {
        ans = -1;
    }
    cout << ans << "\n";
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
