//正确性有待验证 缺少数据
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr double eps = 1e-6;
constexpr int mod = 998244353;
constexpr int N = 100000 + 5;
vector<int> minp, primes;
unordered_map<int, int>d;
int u = 0;
void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();

    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
            d[i] = u++;
        }

        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}
vector<pair<int, int>> get(int n) {
    vector<pair<int, int>>ans;
    for (int i = 2; i <= n; i++) {
        int t = i;
        for (auto p : primes) {
            if (p * p > i)break;
            if (t % p == 0) {
                int cnt = 0;
                while (t % p == 0) {
                    cnt++;
                    t /= p;
                }
                if (d[i] < ans.size()) {
                    ans[d[i]].second += cnt * i;
                }
                else {
                    ans.push_back({ p,cnt * i });
                }
            }
        }
        if (t > 1) {
            if (d[t] < ans.size()) {
                ans[d[i]].second += i;
            }
            else {
                ans.push_back({ t,i });
            }
        }
    }
    return ans;
}
int qpow(int a, int b, int m) {
    int ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * 1ll * a % m;
        }
        b >>= 1;
        a = a * 1ll * a % m;
    }
    return ans % m;
}
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    auto a = get(n);
    while (q--) {
        int r;
        cin >> r;
        auto b = get(r);
        auto c = get(n - r);
        ll ans = 1;
        for (int i = 0; i < a.size(); i++) {
            int t = a[i].second;
            if (i < b.size()) {
                t -= b[i].second;
            }
            if (i < c.size()) {
                t -= c[i].second;
            }
            if (t == 0)continue;
            ans = ans * qpow(a[i].first, t, m) % m;
        }
        cout << ans << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    sieve(1E5);
    //cout << primes.size() << "\n";
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
