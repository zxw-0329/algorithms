
//https://www.luogu.com.cn/problem/P1368

#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int i = 0, j = 1, k = 0;
    while (k < n && j < n && i < n) {
        if (a[(i + k) % n] == a[(j + k) % n]) {
            k++;
        }
        else {
            a[(i + k) % n] > a[(j + k) % n] ? i = i + k + 1 : j = j + k + 1;
            if (i == j)j++;
            k = 0;
        }
    }
    i = min(i, j);
    k = 0;
    while (k < n) {
        cout << a[(i + k++) % n] << " ";
    }
    return 0;
}
