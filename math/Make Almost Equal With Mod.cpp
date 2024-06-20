/*
   一组数 % k 恰好有只有两种数
   先分类讨论：
   1. 如果既有奇数也有偶数 那么 k=2 即可满足条件
   2. 如果只有奇数或只有偶数怎么办
   利用 $k$ 设 $f(k)$ 为运算后不同值的个数。

让我们试试 k = 2。除了所有数字都是偶数或所有数字都是奇数的情况外，在所有情况下都能正常运算。

让我们来归纳一下。如果 ai mod k = x 成立，那么下列条件之一成立：

- ai mod 2k = x ;
- ai mod 2k = x+ k;

这意味着，如果 f(k) = 1 （即运算后的所有值都是 x ），要么是 f(2k) = 1 （如果所有值都变成 x，要么都变成 x+k ），要么是 f(2k) = 2 。

因此，只需尝试 k = 2^1, 。。, 2^{57} 即可。事实上， f(1) = 1 和 f(2^{57}) = n，所以一定存在 m < 57 ，即 f(2^m) = 1 和 f(2^{m+1})= 2 。

另一种（更直观的？

- ai mod 2^j 对应于 ai 二进制表示中的最后 j 位。一定存在 j，使得最后的 j 位数正好构成 2 个不同的数块。

在下图中，a = [1005, 2005, 7005, 11005, 16005] 和 k = 16：

1101
0101
1101
1101
0101

复杂度: O(n log(max ai))

  https://codeforces.com/contest/1909/problem/B
*/  
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int mx = *max_element(a.begin(), a.end());
    ll k = 1;
    while (true) {

        for (int i = 0; i < n; i++) {
            if (a[i] % k != a[0] % k) {
                cout << k << "\n";
                return;
            }
        }

        k *= 2;
    }
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
