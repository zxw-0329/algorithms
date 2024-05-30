/*
  分为：+-+-+-。。
       -+-+-+-。。两组
   对于每一组从前往后贪心的进行查找
   保证序列长度最大

   灵茶 5.27
   https://codeforces.com/contest/1343/problem/C
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    pair<int, ll>neg, pos;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            neg = max(neg, make_pair(pos.first + 1, pos.second + a[i]));
        }
        else {
            pos = max(pos, make_pair(neg.first + 1, neg.second + a[i]));
        }
    }
    cout << max(neg, pos).second << "\n";
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
