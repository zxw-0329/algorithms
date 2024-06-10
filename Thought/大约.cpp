/*
  维护区间最大最小

 https://www.matiji.net/exam/dohomework/6505/4
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    int mx = 0, mi = 1e9;
    for (int l = 0, i = 0; i < n; i++) {
        mx = max(a[i], mx);
        mi = min(mi, a[i]);
        if (mx - mi > 1) {
            while (a[l] != mx && a[l] != mi) {
                l++;
            }
            l++;
            mx = 0, mi = 1e9;
            for (int j = l; j <= i; j++) {
                mx = max(mx, a[j]);
                mi = min(mi, a[j]);
            }
        }
        ans = max(ans, i - l + 1);
    }
    cout << ans << "\n";
    return 0;
}
