/*
先比较当前位大小，之后比较前缀字符串那个大；

确定是否要交换

https://codeforces.com/contest/1954/problem/C
*/  
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string x, y;
    cin >> x >> y;
    if (x < y)swap(x, y);
    int n = x.size();
    for (int i = 0; i < n; i++) {
        if (x[i] == y[i])continue;
        if (x[i] > y[i]) {
            if (x.substr(0, i) > y.substr(0, i)) {
                swap(x[i], y[i]);
            }
        }
        else {
            if (x.substr(0, i) < y.substr(0, i)) {
                swap(x[i], y[i]);
            }
        }
    }
    cout << x << "\n" << y << "\n";
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
