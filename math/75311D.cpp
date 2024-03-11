/*
   lcm(x,y) = k * max(x,y) , k为整数
   又 x ^ y < 2 * max(x,y) ;
   若两者相等 只有可能 k = 1 ;
   所以 lcm(x,y) = max(x,y) = x^ y;
   即 x, y 中较大者是较小者的倍数;
   令 x > y
   所以 x 是 y 的倍数 且 x= x ^ y  ->  y=0;
    x是y的倍数 -> x=0;
    答案为 count(0)*count(0);
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
