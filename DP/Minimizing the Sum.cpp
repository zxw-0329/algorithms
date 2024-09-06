/*

类似划分型 DP（见我动态规划题单第六章），定义 dfs(i,j) 表示考虑 a[0]~a[i]，至多操作 j 次时的最小和。
不操作：dfs(i,j) = dfs(i-1,j)
操作，枚举操作次数，或者操作的这一段子数组的左端点 L，那么：
操作了 t=i-L 次，子数组所有元素变成子数组最小值 mn = min(a[L],a[L+1],...,a[i])，得
dfs(i,j) = dfs(L-1,j-t) + mn * (t+1)
这些情况取最小值，即 dfs(i,j)

递归边界：dfs(-1,j)。
答案：dfs(n-1,k)。

https://codeforces.com/contest/1969/problem/C
*/
#include<bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr i64 inf = 1E18;
void solve() {

    int n, k;
    cin >> n >> k;

    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // vector dp(n + 1, vector<i64>(k + 1, inf));
    // dp[0][0] = 0;

    // for (int i = 0; i < n; i++) {
    //     int mi = a[i];
    //     for (int j = 0; i + j < n && j <= k; j++) {
    //         mi = min(mi, a[i + j]);
    //         for (int x = 0; x + j <= k; x++) {
    //             dp[i + j + 1][x + j] = min(dp[i + j + 1][x + j], dp[i][x] + 1LL * mi * (j + 1));
    //         }
    //     }
    // }
    // i64 ans = *min_element(dp[n].begin(), dp[n].end());
    // cout << ans << "\n";

    vector dp(n + 1, vector<i64>(k + 1, 0));

    for (int i = 0; i < n; i++) {

        for (int j = 0; j <= k; j++) {//枚举次数
            int mi = a[i];
            i64 res = dp[i][j] + a[i];
            for (int l = i - 1; l >= max(0, i - j); l--) {//枚举区间左端点
                mi = min(mi, a[l]);
                int t = i - l;
                res = min(res, dp[l][j - t] + (t + 1) * 1LL * mi);
            }
            dp[i + 1][j] = res;
        }
    }
    cout << dp[n][k] << "\n";
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
