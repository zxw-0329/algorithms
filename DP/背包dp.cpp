/*
  背包问题：
  
  dp[j]：在幸福值为j的情况最大钱数
  
  https://codeforces.com/contest/1974/problem/E
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 10000000000;
constexpr int N = 1e5 + 10;
void solve() {
    int m, x;
    cin >> m >> x;
    vector<int>a(m), b(m);
    int s = 0;
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        s += b[i];
    }
    vector<ll>dp(s + 1, -1);//dp[j]：在幸福值为j的情况最大钱数
    dp[0] = 0;
    int s1 = 0;
    for (int i = 0; i < m; i++) {
       // s1 += b[i];
       //可以从s1开始
        for (int j = s; j >= b[i]; j--) {
            if (dp[j - b[i]] >= a[i]) {
                dp[j] = max(dp[j], dp[j - b[i]] - a[i]);
            }
        }
       //可以从s1开始
        for (int j = 0; j <= s; j++) {
            if (dp[j] >= 0) {
                dp[j] += x;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= s; i++) {
        if (dp[i] >= 0) {
            ans = i;
        }
    }
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
