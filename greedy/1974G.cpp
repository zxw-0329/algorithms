/*
 当到第m个月我们考虑是否要购买
 先压入优先级队列中
 买的话。钱数-c 如果发现钱数<0 将最大的元素弹出堆顶
 之后钱数+x
 https://codeforces.com/contest/1974/problem/G

有 n个药水排成一行，最左到右为1-n。每种药水喝下后都会增加 ai体力。ai可以是负数，这意味着该药水会降低你的健康值。
开始时，你的生命值为 0 ，你将从左到右，从第一个药水走到最后一个药水。每喝下一种药水，你都可以选择喝下或忽略它。你必须确保你的生命值始终不为负
https://codeforces.com/contest/1526/problem/C2

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
