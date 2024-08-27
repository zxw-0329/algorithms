/*
  题目给的每个数都为合数  4<=ai<=1000

  用每个数最小的素因子取构造
  sqrt（1000） 里的素数刚好有 

  https://codeforces.com/contest/1332/problem/B
*/
#include<bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;


void solve() {

    int n;
    cin >> n;
    vector<int>a[1010];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = 2; j <= x; j++) {
            if (x % j == 0) {
                a[j].push_back(i);
                break;
            }
        }
    }
    int cnt = 0;
    vector<int>ans(n);
    for (int i = 2; i <= 1000; i++) {
        if (a[i].size()) {
            ++cnt;
            for (int j : a[i]) {
                ans[j] = cnt;
            }
        }
    }

    cout << cnt << "\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
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
