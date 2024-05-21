/*

  对某一位置可以从前面某一区间转移过来
  可以单调队列来优化
  队内满足单调性（具体怎样看题目要求）

   https://ac.nowcoder.com/acm/contest/82774/E
   https://codeforces.com/contest/1941/problem/E
   
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 10000000000;
constexpr int N = 2e5 + 10;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k, t;
    cin >> n >> k >> t;
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll>f;
    vector<ll>g;
    auto calc = [&]() {
        vector<ll>b(n, inf);
        deque<int>q;
        q.clear();
        b[0] = a[0];
        q.push_back(0);
        for (int i = 1; i < n; i++) {
            while (!q.empty() && i - q.front() > k) {
                q.pop_front();
            }
            b[i] = b[q.front()] + a[i];
            while (!q.empty() && b[i] <= b[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        return b;
        };
    f = calc();
    reverse(a.begin(), a.end());
    g = calc();
    reverse(a.begin(), a.end());
    reverse(g.begin(), g.end());
    while (t--) {
        int x;
        cin >> x;
        x--;
        cout << f[x] + g[x] - a[x] << "\n";
    }
    return 0;
}
