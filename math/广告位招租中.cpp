/*
  首先统计每个 出现的次数
  枚举最大公约（枚举倍数）
  https://ac.nowcoder.com/acm/contest/82774/A
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int inf = 1e9;
constexpr int N = 2e5 + 10;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int>a(n);
    vector<int>f(N);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f[a[i]]++;
    }
    int k = 0, ans = 0;
    for (int i = m; i < f.size(); i++) {
        int cnt = 0;
        int g = 0;
        for (int j = i; j < N; j += i) {
            cnt += f[j];
            if (f[j])g = __gcd(g, j);
        }
        if (g == i) {
            if (cnt > k) {
                k = cnt;
                ans = g;
            }
        }
    }
    cout << k << " " << ans << "\n";
    return 0;
}
