/*
  用0 或n-1进行中转
  假设每次 “操作” 可以使得一个元素到其对应位置去，那么只要 “操作” 的交换次数不超过 5n，我们就完成了这一题。

  https://codeforces.com/problemset/problem/1148/C
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int>a(n);
    vector<int>pos(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        pos[a[i]] = i;
    }
    vector<pair<int, int>>ans;
    auto p = [&](int u, int v) {
        pos[a[v]] = u;
        pos[a[u]] = v;
        swap(a[u], a[v]);
        ans.push_back({ u + 1,v + 1 });
        };

    for (int i = 0; i < n / 2; i++) {
        if (pos[i] != i) {
            if (pos[i] >= n / 2) {
                p(0, pos[i]);
                p(0, n - 1);
                p(i, n - 1);
            }
            else {
                p(pos[i], n - 1);
                p(i, n - 1);
            }
        }
    }
    for (int i = n / 2; i < n; i++) {
        if (pos[i] != i) {
            if (pos[i] >= n / 2) {
                p(0, pos[i]);
                p(0, i);
            }
            else {
                p(pos[i], n - 1);
                p(0, n - 1);
                p(0, i);
            }
        }
    }
    if (a[0] != 0) {
        p(0, n - 1);
    }
    for (int i = 0; i < n; i++) {
        cerr << a[i] << " " << pos[i] << "\n";
    }
    cout << ans.size() << "\n";
    for (auto [x, y] : ans) {
        cout << x << " " << y << "\n";
    }
    return 0;
}
