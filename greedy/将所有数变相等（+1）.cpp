//https://ac.nowcoder.com/acm/contest/91443/M

#include<bits/stdc++.h>

using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

void sovle() {

    int n;
    cin >> n;

    vector<int>a(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    i64 ans = 0;
    vector<int>b(n);
    
    b[0] = mx - a[0];
    ans = b[0];
    for (int i = 1; i < n; i++) {
        b[i] = mx - a[i];
        ans += max(0, b[i] - b[i - 1]);
    }
    cout << ans << "\n";
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        sovle();
    }
    return 0;
}
