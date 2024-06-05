/*
  有k种不同颜色的球能产生（k）*(k-1)/2 种不同颜色
  
  找到第一个满足（k）*(k-1)/2 <= n <=（k）*(k-1)/2+k

  同色的球就为 n-（k）*(k-1)/2；
  https://codeforces.com/contest/1862/problem/D
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
void solve() {
    ll n;
    cin >> n;
    auto check = [&](ll k)->bool {
        ll s = ((k - 1) * k / 2);
        return s > n;
        };
    ll l = 1, r = 1e10;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(mid)) {
            r = mid - 1;
        }
        else l = mid + 1;
    }
    l--;
    cout << l + (n - l * (l - 1) / 2) << "\n";
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
