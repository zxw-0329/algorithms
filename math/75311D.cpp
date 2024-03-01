/*

 
    https://ac.nowcoder.com/acm/contest/75311/D
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n;
    cin >> n;
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0)cnt++;
    }
    cout << cnt * cnt << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    //  cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
