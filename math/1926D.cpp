/*
   inf= (1<<31)-1;
   由题意可知 ：要满足x2(i)≠y2(i)对所有的 1≤i<32成立
               a[i]^a[j]==inf;
               所以同一组中最多包含两个数;
               用 map记录每个数出现的次数
               之后枚举 每个数 判断其 ^inf 的值是否存在;      

  https://codeforces.com/contest/1926/problem/D
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n;
    cin >> n;
    vector<int>a(n);
    ll ans = n;
    int inf = (1LL << 31) - 1;
    map<int, int>m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]]++;
    }

    for (int i = 0; i < n; i++) {
        int t = a[i] ^ inf;
        if (m[t]&&m[a[i]]) {
            ans--;
            m[t]--;
            m[a[i]]--;
        }
    }

    cout << ans << "\n";
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
