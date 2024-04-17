/*
  解决问题的关键在于以下观察结果：如果 ai>ai+1，
  那么 i-th 元素总是应该被拆分(因为与 ai+1相比，这是减少元素的唯一方法)。

  根据这个观察结果，我们可以贪婪地解决这个问题：从右到左遍历数组 a
 ，同时跟踪我们处理过的元素列表；
  如果当前元素大于列表中的最后一个元素，我们就必须拆分它(并将它所包含的数字添加到列表中)；
  否则，我们就不必拆分它(因为它可能会禁止接下来的一些元素，并迫使它们也拆分)。

 之后，我们必须确保得到的是一个排序过的数组(例如，如果分割 98这样的数字，就会破坏排序顺序，而我们并没有检查这一点)。
 但由于我们保留了处理过的元素列表，所以这很容易，因为该列表就是结果数组 a的相反顺序。

 https://codeforces.com/problemset/problem/1948/B
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int inf = 1e9;
void solve() {
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int>b({ a[n - 1] });
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > b.back()) {
            int x = a[i];
            if (x >= 10) {
                b.push_back(x % 10);
                b.push_back(x / 10);
            }
            else {
                b.push_back(x);
            }
        }
        else {
            b.push_back(a[i]);
        }
    }
    cout << (is_sorted(b.rbegin(), b.rend()) ? "YES" : "NO") << "\n";
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
