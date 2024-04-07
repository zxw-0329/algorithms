/*

   https://codeforces.com/contest/1940/problem/C
   
  */
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using i64 = long long;

template<class T,
class Cmp = std::less<T>>
    struct RMQ {       
    const Cmp cmp = Cmp();
    static constexpr unsigned B = 64;
    using u64 = unsigned long long;
    int n;
    std::vector<std::vector<T>> a;
    std::vector<T> pre, suf, ini;
    std::vector<u64> stk;
    RMQ() { }
    RMQ(const std::vector<T>& v) {
        init(v);
    }
    void init(const std::vector<T>& v) {
        n = v.size();
        pre = suf = ini = v;
        stk.resize(n);
        if (!n) {
            return;
        }
        const int M = (n - 1) / B + 1;
        const int lg = std::__lg(M);
        a.assign(lg + 1, std::vector<T>(M));
        for (int i = 0; i < M; i++) {
            a[0][i] = v[i * B];
            for (int j = 1; j < B && i * B + j < n; j++) {
                a[0][i] = std::min(a[0][i], v[i * B + j], cmp);
            }
        }
        for (int i = 1; i < n; i++) {
            if (i % B) {
                pre[i] = std::min(pre[i], pre[i - 1], cmp);
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (i % B != B - 1) {
                suf[i] = std::min(suf[i], suf[i + 1], cmp);
            }
        }
        for (int j = 0; j < lg; j++) {
            for (int i = 0; i + (2 << j) <= M; i++) {
                a[j + 1][i] = std::min(a[j][i], a[j][i + (1 << j)], cmp);
            }
        }
        for (int i = 0; i < M; i++) {
            const int l = i * B;
            const int r = std::min(1U * n, l + B);
            u64 s = 0;
            for (int j = l; j < r; j++) {
                while (s && cmp(v[j], v[std::__lg(s) + l])) {
                    s ^= 1ULL << std::__lg(s);
                }
                s |= 1ULL << (j - l);
                stk[j] = s;
            }
        }
    }
    T operator()(int l, int r) {
        if (l / B != (r - 1) / B) {
            T ans = std::min(suf[l], pre[r - 1], cmp);
            l = l / B + 1;
            r = r / B;
            if (l < r) {
                int k = std::__lg(r - l);
                ans = std::min({ ans, a[k][l], a[k][r - (1 << k)] }, cmp);
            }
            return ans;
        }
        else {
            int x = B * (l / B);
            return ini[__builtin_ctzll(stk[r - 1] >> (l - x)) + l];
        }
    }
};

constexpr int B = 700;
constexpr int N = 300000;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, d, g;
    std::cin >> n >> d >> g;
    d = std::min(n, d);

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
    }

    RMQ rmq1(a);

    std::vector<int> b(n - d + 1);
    for (int i = 0; i < n - d + 1; i++) {
        b[i] = rmq1(i, i + d);
    }

    int q;
    std::cin >> q;

    std::vector<int> u(q), v(q), t(q);
    std::vector<int> ans(q);
    for (int i = 0; i < q; i++) {
        std::cin >> t[i] >> u[i] >> v[i];
        u[i]--, v[i]--;
    }

    RMQ<int, std::greater<int>> rmq2(b);
    std::vector<int> r(n);
    for (int i = 0; i < n; i++) {
        int lo = i, hi = n;
        while (lo < hi) {
            int x = (lo + hi + 1) / 2;
            if (x - i <= d || rmq2(i + 1, x - d + 1) < a[i]) {
                lo = x;
            }
            else {
                hi = x - 1;
            }
        }
        r[i] = lo;
    }

    std::vector<int> pq(q);
    std::iota(pq.begin(), pq.end(), 0);
    std::sort(pq.begin(), pq.end(),
        [&](int i, int j) {
            return a[v[i]] < a[v[j]];
        });

    int cur[N], mx[N], ansp[N]{};
    int up[N], vp[N];
    for (int i = 0; i < q; i++) {
        cur[i] = u[pq[i]];
        mx[i] = u[pq[i]];
        up[i] = u[pq[i]];
        vp[i] = v[pq[i]];
    }

    int pre[N], f[N], cost[N];

    for (int t = 0; t * B < n; t++) {
        int L = t * B, R = std::min(n, (t + 1) * B);

        std::vector<int> ab(R - L);
        for (int i = L; i < R; i++) {
            ab[i - L] = a[i];
        }
        std::sort(ab.begin(), ab.end());

        auto build = [&](int j) {
            int res = 0;
            for (int i = L; i < R; i++) {
                if (j > 0 && a[i] <= ab[j - 1]) {
                    res = std::max(res, r[i]);
                }
                pre[i] = res;
            }
            for (int i = R - 1; i >= L; i--) {
                if (pre[i] <= i) {
                    f[i] = -1;
                }
                else if (pre[i] >= R) {
                    f[i] = pre[i];
                    cost[i] = 1;
                }
                else {
                    f[i] = f[pre[i]];
                    cost[i] = 1 + cost[pre[i]];
                }
            }
            };

        int j = 0;
        build(0);
        for (int i = 0; i < q; i++) {
            if (cur[i] > vp[i]) {
                continue;
            }
            if (vp[i] < R || up[i] >= L) {
                for (int j = std::max(up[i], L); j <= std::min(vp[i], R - 1); j++) {
                    if (j > cur[i]) {
                        if (j > mx[i]) {
                            ansp[i] = 0;
                            cur[i] = vp[i] + 1;
                            break;
                        }
                        cur[i] = mx[i];
                        ansp[i]++;
                    }
                    if (a[j] <= a[vp[i]]) {
                        mx[i] = std::max(mx[i], r[j]);
                    }
                }
            }
            else {
                while (j < R - L && a[vp[i]] >= ab[j]) {
                    j++;
                    build(j);
                }
                if (cur[i] >= R - 1) {
                    mx[i] = std::max(mx[i], pre[R - 1]);
                }
                else {
                    if (cur[i] >= L) {
                        mx[i] = std::max(mx[i], pre[cur[i]]);
                    }
                    if (cur[i] + 1 > mx[i]) {
                        ansp[i] = 0;
                        cur[i] = vp[i] + 1;
                        continue;
                    }
                    cur[i] = mx[i];
                    ansp[i]++;
                    if (cur[i] < R) {
                        if (f[cur[i]] == -1) {
                            ansp[i] = 0;
                            cur[i] = vp[i] + 1;
                            continue;
                        }
                        ansp[i] += cost[cur[i]];
                        cur[i] = f[cur[i]];
                    }
                    mx[i] = std::max(mx[i], pre[R - 1]);
                }
            }
        }
    }

    for (int i = 0; i < q; i++) {
        ans[pq[i]] = ansp[i];
    }

    for (int i = 0; i < q; i++) {
        if (t[i] == 1) {
            ans[i] = std::min(ans[i], 1);
        }
        std::cout << ans[i] << "\n";
    }

    return 0;
}
