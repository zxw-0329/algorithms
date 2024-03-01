/*
  观察 1的位置 1 2 4 8 16 。。。;
  其他位置不影响 1;
  算出距离n 最近的 2^k (k=log2(n));
  https://codeforces.com/contest/1937/problem/A
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    int t = log2(n);
    cout << (1<<t) << "\n";
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
