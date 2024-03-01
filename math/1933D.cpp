//https://codeforces.com/contest/1933/problem/D
//最小的数唯一 YES
//       不唯一 在剩下的数与最小数的取模找 %min!=0 (YES) else (NO)
//       %min!=0 ->说明可以找到比min还小的数 用最小的数去 % 剩下的数一定 不为0
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n;
    cin >> n;
    vector<int>a(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt += a[i] == 1;
    }
    int mn = *min_element(a.begin(), a.end());
    if (count(a.begin(), a.end(), mn) == 1) {
        cout << "YES\n";
        return;
    }
    else {
        for (int i = 0; i < n;i++) {
            if (a[i] % mn>0 ) {
                cout << "YES\n";
                return;
            }
        }
        
        cout << "NO\n";
    }
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
