/*
  每一个只能为 0 / 1
  最小能满足的数应该为 k2  k2+1
  每次应检查 k2^m / ( k2^i + k2^j....+1)(i>j>..)
  所以每次添加 为当前 x*k2  或 x*k2 +1
  
  https://ac.nowcoder.com/acm/contest/88888/E
*/
#include<bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    i64 k1, k2;
    cin >> k1 >> k2;
    queue<i64>q;
    q.push(k2);
    q.push(k2 + 1);
    auto check = [&](i64 x)->bool {
        while (x) {
            if (x % k1 > 1) {
                return false;
            }
            x /= k1;
        }
        return true;
        };
    constexpr i64 INF = 1e18;
    while (!q.empty()) {
        i64 x = q.front();
        q.pop();
        if (check(x)) {
            cout << "YES" << "\n";
            cout << x << "\n";
            return 0;
        }
        if (x <= INF / k2) {
            q.push(x * k2);
        }
        if (x <= INF / (k2 + 1)) {
            q.push(x * (k2 + 1));
        }
    }
    cout << "NO" << "\n";
    return 0;
}
