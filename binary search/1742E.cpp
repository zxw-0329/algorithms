#include<bits/stdc++.h>
using namespace std;   //二分+前缀和
using ll = long long;  //https://codeforces.com/contest/1742/problem/E
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll>s(n + 1);
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] + a[i];
        if(i){
          a[i]=max(a[i],a[i-1]);
        }
    }
    while (q--) {
        int k;
        cin>>k;
        ll l = 0, r = n - 1;
          while (l <= r) {
              int mid = (l + r) / 2;
              if (a[mid] > k) {
                  r = mid - 1;
              }
              else l = mid + 1;
            }
            cout << s[l] << " ";
        }
    cout << "\n";
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
