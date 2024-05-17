/*
   ai * aj= d^2 ;
   将ai 和 aj 分解质因数相乘之后 每个幂都是偶数次方
   所以我们可以剔除 每个数分解质因数后的 偶次幂
   剩下的为奇次幂 之后 ans+=m[x]//m[x]：x代表每个数提出偶次幂之后剩下的数  
   https://atcoder.jp/contests/abc342/tasks/abc342_d
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int inf = 1e9;
constexpr int N = 2e5 + 10;
vector<int> minp, primes;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();

    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }

        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    sieve(2E5);
    map<int, int>m;
    int cnt = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            cnt++;
            continue;
        }
        for (auto p : primes) {
            if (p * p > x) {
                break;
            }
            while (x % (p * p) == 0) {
                x /= p * p;
            }
        }
        ans += m[x]++;
    }
    ans += cnt * 1LL * (cnt - 1) / 2;
    ans += cnt * 1LL * (n - cnt);
    cout << ans << "\n";
    return 0;
}
