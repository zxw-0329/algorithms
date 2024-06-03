/*
  所有数都相等 那么分解质因数后的幂次一定相等

  https://codeforces.com/contest/1881/problem/D
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
void solve() {
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int>p;
    for (int i = 0; i < n; i++) {
        int t = a[i];
        for (int j = 2; j * j <= t; j++) {
            int cnt = 0;
            while (t % j == 0) {
                cnt++;
                t /= j;
            }
            p[j] += cnt;
        }
        if (t > 1) {
            p[t] += 1;
        }
    }
    for (auto [x, y] : p) {
        if (y % n != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
