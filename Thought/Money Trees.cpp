/*
  分组循环+双指针
  
  https://codeforces.com/contest/1873/problem/F
  灵茶 6.3
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int>h(n), a(n), s(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s[i + 1] = a[i] + s[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ) {
        int j = i;
        i++;
        while (i < n && h[i - 1] % h[i] == 0) {
            i++;
        }
        int l = j, r = j;
        while (r < i) {
            while (s[r + 1] - s[l] > k) {
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
    }
    cout << ans << "\n";
  /* jls代码
    int n, k;
    std::cin >> n >> k;
    
    std::vector<int> s(n + 1), h(n);
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        s[i + 1] = s[i] + a;
    }
    for (int i = 0; i < n; i++) {
        std::cin >> h[i];
    }
    
    int ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
        if (i && h[i - 1] % h[i] != 0) {
            j = i;
        }
        while (s[i + 1] - s[j] > k) {
            j++;
        }
        ans = std::max(ans, i - j + 1);
    }
    std::cout << ans << "\n";


   */ 
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
