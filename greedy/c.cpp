#include<bits/stdc++.h>
using namespace std;//格式化ctrl+c+f
using ll = long long;
void solve() {
    int n;
    cin >> n;
    vector<int>a, b, c;
    for (int i = 0; i < n; i++) {
        int x; string t = "";
        cin >> x >> t;
        if (t == "01") {
            a.push_back(x);
        }
        else if (t == "10") {
            b.push_back(x);
        }
        else if (t == "11") {
            c.push_back(x);
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    if (a.empty() || b.empty()) {
        if (c.empty()) {
            cout << -1 << "\n";
        }
        else cout << c[0] << "\n";
    }
    else {
        if (c.empty()) {
            cout << a[0] + b[0] << "\n";
        }
        else {
            cout << min(a[0] + b[0], c[0]) << "\n";
        }
    }
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