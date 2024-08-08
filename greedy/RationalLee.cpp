/*

   将n个整数按升序排序
   有k个朋友 先把排完序后的最后k个元素依次分给k个朋友

   然后将k个朋友的拥有的个数按升序排序
   从第一个依次进行贪心
   如果w[i]==1 ans+=a[n-i-1];
   定义一个指针j指向a的 第n-k个元素。
   之后跟w将j指针进行移动
   
   https://codeforces.com/contest/1369/problem/C
*/
#include<bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {

    int n, k;
    cin >> n >> k;

    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int>w(k);

    for (int i = 0; i < k; i++) {
        cin >> w[i];
    }
    sort(w.begin(), w.end());
    i64 ans = 0;
    for (int i = n - k; i < n; i++) {
        ans += a[i];
    }

    for (int i = 0, j = n - k; i < k; i++) {
        j -= w[i] - 1;
        if (w[i] == 1) {
            ans += a[n - i - 1];
        }
        else {
            ans += a[j];
        }
    }
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}
