/*
  欧拉筛+映射

*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int mod = 1e4;
const int maxn = 5e5 + 10;
vector<int>primes;
vector<bool>is_prime(maxn, true);
void init() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < maxn; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p * i > maxn) {
                break;
            }
            is_prime[i * p] = false;
            if (i % p == 0) {
                break;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init(); //筛出  1-> sqrt(r) 的所有素数
    int  l, r;
    cin >> l >> r;
    if (l < 2) {//小技巧
        l = 2;
    }
    vector<int>a(r - l + 1, 1);
    for (int p : primes) {
        for (int y = (l + p - 1) / p * p; y <= r; y += p) {//找到 l->r 中 p的最小倍数 之后筛除所有p的倍数
            if (y % p == 0 && y != p) {
                a[y - l] = 0;
            }
        }
    }
    int cnt = 0;
    for (int i = l; i <= r; i++) {
        if (a[i - l])cnt++;
    }
    cout << cnt << "\n";
    return 0;
}
