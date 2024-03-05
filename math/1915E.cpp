/*
   请找出是否存在两个索引 l,r,使得 1≤l≤r≤n;
   如果l和 r具有相同的奇偶性,Al+A(l+2)+A(l+4)+⋯+Ar=A(l+1)+A(l+3)+⋯+A(r−1);
   否则为 Al+A(l+2)+A(l+4)+⋯+a=A(r−1)=A(l+1)+A(l+3)+⋯+ar

   移项可得 Al-A(l+1)+A(l+2)-A(l+3)+A(l+4)+⋯-A(r−1)+Ar=0
   翻转偶数项的值 ai= -ai;
   因此，我们只需检查是否存在和为 0 的子数组。这是一个前缀和的标准问题：如果两个前缀和相等,那么它们之间的子数组的和为 0
    否则，没有子数组的和为 0
 
    https://codeforces.com/contest/1915/problem/E
*/  
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;
void solve() {
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll s = 0;
    map<ll, int>m;
    m[0] = 1;
    for (int i = 0; i < n; i++) {
        
        a[i] *= ((i % 2) ? -1 : 1);
        s += a[i];
        if (m[s]) {
            cout << "YES\n";
            return;
        }
        m[s]++;
    }
    cout << "NO\n";
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
