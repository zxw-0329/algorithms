/*
 当到第m个月我们考虑是否要购买
 先压入优先级队列中
 买的话。钱数-c 如果发现钱数<0 将最大的元素弹出堆顶
 之后钱数+x
 https://codeforces.com/contest/1974/problem/G
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 10000000000;
constexpr int N = 1e5 + 10;
void solve() {
    int m, x;
    cin >> m >> x;
    priority_queue<int>q;
    ll s = 0;
    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;
        q.push(c);
        s -= c;
        if (s < 0) {
            s += q.top();
            q.pop();
        }
        s += x;
    }
    cout << q.size() << "\n";
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
