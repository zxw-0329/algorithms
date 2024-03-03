/*
   题目大意 每个征兆每隔 ai年出现一次
            出现n个征兆共需等待多少年;
            初始 x = 0;
            对与第i个征兆  需要等待 x= x- x% ai+ ai ;
                                        ai- x% ai  当前的征兆 距离出现 所需要的年数;

            https://codeforces.com/contest/1932/problem/B
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n;
    cin >> n;
    ll x = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (i == 0) {
            x += a;
        }
        else {
            x = x - x % a + a;
        }
    }
    cout << x << "\n";
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
