/*
  用二进制构造

  用lix最近的 2^i进行构造

  https://codeforces.com/contest/1463/problem/B
*/
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int t = 1;
        for (int j = 30; j >= 0; j--) {
            if (x >> j & 1) {
                cout << (1 << j) << " ";
                break;
            }
        }
    }cout << "\n";
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
}
