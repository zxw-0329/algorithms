#include<bits/stdc++.h>

using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;

    // while (cin >> n) {
    //     vector<int>a(n);
    //     vector<int>dp(n * (n + 1) / 2 + 1);
    //     auto dfs = [&](auto&& self, int k, int s)->void {
            
    //         if (s == 0) {
    //             //把直线斜率分成k种 a0...a[k-1]
    //             //每种斜率的直线个数为ai个              前(i-1)种直线斜率的总条数
    //             int cnt = 0;//交点数=第i种直线斜率的个数*sum(a[0,i-1])
    //             int pre = 0;
    //             for (int i = 0; i < k; i++) {
    //                 cnt += pre * a[i];
    //                 pre += a[i];
    //             }
    //             //cout << cnt << " ";
    //             dp[cnt] = 1;
    //             return;
    //         }
    //         if (k >= n || s < 0) {
    //             return;
    //         }
    //         for (int i = n; i >= 1; i--) {
    //             if (k >= 1 && i > a[k - 1])continue;
    //             a[k] = i;
    //             self(self, k + 1, s - i);
    //         }
    //         };
    //     dfs(dfs, 0, n);
    //     for (int i = 0; i <= n * (n + 1) / 2; i++) {
    //         if (dp[i]) {
    //             cout << i << " ";
    //         }
    //     }
    // }

    cin >> n;
    vector<array<int, 200>>dp(n + 1);
    //dp[i][j]:i条直线是否能形成j个交点
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {//直线数
        for (int j = 0; j <= i * (i + 1) / 2; j++) {//交代数

            if (dp[i][j] == 1) {//i条直线已经有j交点
                for (int k = 1; i + k <= n; i++) {//枚举剩下的直线条数
                    //k条平行线与i条直线相交 增加 i*k个交点
                    dp[i + k][j + i * k] = 1;
                }
            }
        }
    }
    return 0;
}
