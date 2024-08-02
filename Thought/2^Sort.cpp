/*
   双指针维护区间长度；
   之后看区间长度是否满足要求 ，统计有几个满足

   https://codeforces.com/contest/1692/problem/G
*/
    #include<bits/stdc++.h>
    using namespace std;
    using i64 = long long;

    void solve() {

        int n, k;
        cin >> n >> k;

        vector<int>a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        i64 ans = 0;
        int l = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] * 2 > a[i - 1]) {
                continue;
            }
            if (i - l >= k + 1) {
                ans += i - l - k;
            }      
            l = i;
        }
        if (n - l >= k + 1) {
            ans += n - l - k;
        }
        cout << ans << "\n";
    }
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        std::cout.tie(nullptr);

        int t;
        cin >> t;
        while (t--) {
            solve();
        }
        return 0;
    }
