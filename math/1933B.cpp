/*

    
  https://codeforces.com/contest/1933/problem/B
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n;
    cin >> n;
    vector<int>a(n);
    ll s = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    if (s % 3 == 0) {
        cout << 0 << "\n";
    }
    else {int t = 1e9;
        int add = (s / 3 + 1) * 3 - s;
        for (int i = 0; i < n; i++) {
            if ((s - a[i]) % 3 == 0) {
                t = 1;
                break;
            }
        }
        cout << min(t, add) << "\n";
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
