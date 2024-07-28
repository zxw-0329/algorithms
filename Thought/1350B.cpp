/*
   定义 dp[i]:表示以i结尾的最长优美子序列的长度
   
   跟最长递增子序列有点相似
   https://codeforces.com/contest/1350/problem/B#
*/
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {

    int n;
    cin >> n;

    vector<int>s(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> s[i + 1];
    }
    vector<int>dp(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 2 * i; j <= n; j += i) {
            if (s[i] < s[j]) {
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
