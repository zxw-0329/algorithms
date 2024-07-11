/*
 变为可被k整除，考虑余数
 对于一个数x 使得可被k整除 只需要计算 （k-a[i]%k）%k 即可（想一想，为什么） （在加上（k-a[i]%k）%k 可被k整除）

 对于每个余数 如果第一次出现 则为 （k-[i]%k）%k
 否则要加上一个周期的k（因为每次操作x都会增加1）
 之后对每个余数的操作值取max即可（注意+1）（应为a[i]+x后 x++）；

 https://codeforces.com/contest/1374/problem/D
*/  
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    map<int, ll>p;
    for (int i = 0; i < n; i++) {

        int b = (k - a[i] % k) % k;
        if (b == 0)continue;
        if (p.count(b)) {
            p[b] += k;
        }
        else p[b] = b;
        ans = max(ans, p[b] + 1);
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
