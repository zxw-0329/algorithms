操作1，直接用线段树维护区间和

操作2，预处理每个质因子的位置，只需更新包含当v的质因子的位置，更新当前的值

操作3，不改变质因子的种类，直接更新值

### 具体代码如下——

``` cpp []
//对于 1<=a[i]<=2e5 ， 1<=v<=2e5
#include<bits/stdc++.h>

using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

const int N = 2e5 + 10;
constexpr int mod = 998244353;
i64 sg[4 * N + 1];

void apply(int p, int l, int r, int x, int v) {

    if (l == r) {
        sg[p] = v;
        return;
    }
    int mid = l + r >> 1;
    if (x <= mid) {
        apply(2 * p, l, mid, x, v);
    } else {
        apply(2 * p + 1, mid + 1, r, x, v);
    }
    sg[p] = (sg[2 * p] + sg[2 * p + 1]) % mod;
}

i64 query(int p, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        return sg[p];
    }
    int mid = l + r >> 1;
    i64 sum = 0;
    if (x <= mid) {
        sum = (sum + query(2 * p, l, mid, x, y)) % mod;
    }
    if (y > mid) {
        sum = (sum + query(2 * p + 1, mid + 1, r, x, y)) % mod;
    }
    return sum;
}

vector<vector<i64>> fac(N);
int vis[N];

void init() {

    for (int i = 2; i < N; i++) {
        if (!vis[i]) {
            for (int j = i; j < N; j += i) {
                fac[j].push_back(i);
                vis[j] = 1;
            }
        }

    }
}

int a[N];
set<int> st[N];

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    init();
    // freopen("input.in", "r", stdin);
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int x: fac[a[i]]) {
            st[x].insert(i);
        }
        apply(1, 1, n, i, a[i]);
    }
    while (q--) {
        int op, l, r;
        int v;
        cin >> op;
        if (op == 1) {
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << "\n";
        } else if (op == 2) {

            cin >> l >> r >> v;
            int g = v;

            for (int x: fac[v]) {
                while (g % x == 0) {
                    g /= x;

                    int index = l;
                    while (true) {

                        auto it = st[x].lower_bound(index);
                        if (it == st[x].end())break;
                        int d = *it;
                        if (d > r)break;
                        a[d] /= x;
                        apply(1, 1, n, d, a[d]);
                        if (a[d] % x != 0) {
                            st[x].erase(d);
                        }
                        index = d + 1;
                    }
                }
            }
        } else {
            cin >> l >> v;

            for (int x: fac[v]) {
                if (a[l] % x == 0) {
                    st[x].insert(l);
                }
            }
            a[l] = a[l] * gcd(a[l], v);
            apply(1, 1, n, l, a[l]);
        }
    }
    return 0;
}

```

``` cpp []
#include<bits/stdc++.h>

using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

const int N = 2e5 + 10;
constexpr int mod = 998244353;
vector<i64>sg;

void apply(int p, int l, int r, int x, int v) {

    if (l == r) {
        sg[p] = v;
        return;
    }
    int mid = l + r >> 1;
    if (x <= mid) {
        apply(2 * p, l, mid, x, v);
    }
    else {
        apply(2 * p + 1, mid + 1, r, x, v);
    }
    sg[p] = (sg[2 * p] + sg[2 * p + 1]);
}

i64 query(int p, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        return sg[p];
    }
    int mid = l + r >> 1;
    i64 sum = 0;
    if (x <= mid) {
        sum = (sum + query(2 * p, l, mid, x, y));
    }
    if (y > mid) {
        sum = (sum + query(2 * p + 1, mid + 1, r, x, y));
    }
    return sum;
}

vector<int> minp, primes;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();

    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
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
vector<pair<int, int>>fac(int x) {

    vector<pair<int, int>>res;
    while (x > 1) {
        int d = minp[x], cnt = 0;
        while (x % d == 0) {
            cnt++;
            x /= d;
        }
        res.push_back({ d,cnt });
    }
    return res;
}
map<int,set<int>>st;
int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve(1E7);

    int n, q;
    cin >> n >> q;

    vector<i64>a(n + 1);
    sg.resize(4 * n + 10);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (auto [x, y] : fac(a[i])) {

            st[x].insert(i);
        }
        apply(1, 1, n, i, a[i]);
    }
    while (q--) {
        int op, l, r, v;
        cin >> op;
        if (op == 1) {
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << "\n";
        }
        else if (op == 2) {
            cin >> l >> r >> v;
            int g = v;
            auto p = fac(v);
            for (auto [x, y] : p) {

                int d = l;
                while (true) {
                    auto it = st[x].lower_bound(d);
                    if (it == st[x].end() || *it > r)break;
                    d = *it;
                    int yy = y;
                    while (yy > 0 && a[d] % x == 0) {
                        a[d] /= x;
                        yy--;
                    }
                    apply(1, 1, n, d, a[d]);
                    if (a[d] % x != 0) {
                        st[x].erase(d);
                    }
                    d = d + 1;
                }
            }
        }
        else {
            cin >> l >> v;
            a[l] = a[l] * gcd(a[l], v);
            apply(1, 1, n, l, a[l]);
        }
    }
    return 0;
}

```
