/*
 用 1 - 2n 配对 （每次数仅用一次两两配对）
 
 观察得到 1 - 2n 的相加总和不变 为: (1+2*n)*2*n/2
 假设配对的序列 首项为 k 则序列为 k , k+1 ,k+2 ,...,k+n-1
 所以 n*(1+2*n)=(k+k+n-1)*n/2
 
 https://codeforces.com/contest/1788/problem/C
*/
#include<bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {

    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << "No" << "\n";
        return;
    }
    cout << "Yes" << "\n";
    if (n == 1) {
        cout << 1 << " " << 2 << "\n";
        return;
    }
    int x = 3 * (n + 1) / 2;
    vector<int>a(2 * n + 1);
    for (int i = 1; i <= n; i += 2, x++) {
        cout << i << " " << x - i << "\n";
        a[i] = a[x - i] = 1;
    }
    for (int i = 1; i <= 2 * n; i++) {
        if (!a[i]) {

            cout << i << " " << x - i << "\n";
            a[i] = a[x - i] = 1;
            x++;
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);


    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
