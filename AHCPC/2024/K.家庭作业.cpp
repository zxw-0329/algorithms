#include<bits/stdc++.h>

using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

int power(int a, i64 b, int m) {
    if (b < 0) {
        return 0;
    }
    int ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * 1LL * a % m;
        }
        b >>= 1;
        a = a * 1LL * a % m;
    }
    return ans;
}
int exgcd(int a, int b, int& x, int& y) {//a* x + b * y = 1; 求x
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
int inv(int a,int m) {

    int x, y;
    int g = exgcd(a, m, x, y);

    return (x % m + m) % m;
}
void solve() {

    int n, q, r;
    int m;
    cin >> n >> m >> q;

    vector<int>p;
    int y = m;
    for (int i = 2; i * 1LL * i <= y; i++) {
        if (y % i == 0) {
            p.push_back(i);
            while (y % i == 0) {
                y /= i;
            }
        }
    }
    if (y > 1) {
        p.push_back(y);
    }

    vector<int>g(n + 1);
    vector<vector<i64>>cnt(n + 1, vector<i64>(p.size()));

    vector<int>g_inv(n + 1);
    g[1] = 1; g_inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        int x = i;
        for (int j = 0; j < p.size(); j++) {
            int c = 0;
            while (x % p[j] == 0) {
                x /= p[j];
                c++;
            }
            cnt[i][j] = cnt[i - 1][j] + c * 1LL * i;
        }
        assert(gcd(x, m) == 1);
        g[i] = g[i - 1] * 1LL * power(x, i, m) % m;
        g_inv[i] = inv(g[i], m);
    }

    while (q--) {
        cin >> r;
        int s = 1;
        for (int j = 0; j < p.size(); j++) {
            s = (s * 1LL * power(p[j], cnt[n][j] - cnt[r][j] - cnt[n - r][j], m)) % m;
        }
        cout << (g[n] * 1LL * g_inv[r] % m * g_inv[n - r] % m * s) % m << "\n";
    }
}
int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
