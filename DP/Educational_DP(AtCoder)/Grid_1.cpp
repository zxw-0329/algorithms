#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int mod = 1e9 + 7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int H, W;
    cin >> H >> W;
    vector<string>a(H);
    for (int i = 0; i < H; i++) {
        cin >> a[i];
    }
    vector<vector<int>>dp(H, vector<int>(W));
    for (int j = 0; j < W; j++) {
        if (a[0][j] == '#')break;
        dp[0][j] = 1;
    }
    for (int i = 0; i < H; i++) {
        if (a[i][0] == '#')break;
        dp[i][0] = 1;
    }
    for (int i = 1; i < H; i++) {
        for (int j = 1; j < W; j++) {
            if (a[i][j] == '#')continue;
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
        }
    }
    cout << dp[H - 1][W - 1] << "\n";
    return 0;
}
