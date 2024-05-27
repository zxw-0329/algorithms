#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr double eps = 1e-6;
constexpr int mod = 998244353;
constexpr int N = 100000 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    bitset<1510>b[n];
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        a[i] = b[i].count();
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && b[i][n - j - 1] == 1) {
                ans += (a[i] - 1) * (a[j] - 1) - (b[i] & b[j]).count();
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
/*
4
0101
1010
0101
1010

8
*/
