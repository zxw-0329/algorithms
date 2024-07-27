/*
  https://codeforces.com/contest/1883/problem/D
*/
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {

    int n;
    cin >> n;
    multiset<int>ls, rs;
    while (n--) {
        char op;
        int l, r;
        cin >> op >> l >> r;
        if (op == '+') {
            ls.insert(l);
            rs.insert(r);
        }
        else {
            ls.extract(l);
            rs.extract(r);
        }
        if (!ls.empty() && (*ls.rbegin() > *rs.begin())) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
