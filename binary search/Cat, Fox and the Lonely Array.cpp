/*
  任意k个连续元素组成的子数组按位或的值相同

  观察数据最多有20位
  1.如果长度为 k的满足 那么长度为k+1的也满足 （感觉这样，不会证）
  之后就可以二分长度
  2，check的时候检查位就ok了

  https://codeforces.com/problemset/problem/1973/B

*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto check = [&](int k)->bool {
        //  cerr << k << "\n";
        vector<int>b(21);
        vector<bool>pre(21);
        for (int i = 0, l = 0; i < n; i++) {
            for (int j = 0; j < 20; j++) {
                if ((a[i] >> j) & 1) {
                    b[j]++;
                }
            }
            if (i - l + 1 > k) {
                for (int j = 0; j < 20; j++) {
                    if ((a[l] >> j) & 1) {
                        b[j]--;
                    }
                }
                l++;
            }
            // cerr << l << "\n";
            // for (int j = 0; j < 20; j++) {
            //     cerr << b[j] << " \n"[j == 19];
            // }
            if (i == k - 1) {
                for (int j = 0; j < 20; j++) {
                    pre[j] = b[j] > 0 ? 1 : 0;
                }

            }
            else if (i >= k) {
                vector<bool>p(21);
                for (int j = 0; j < 20; j++)p[j] = b[j] > 0 ? 1 : 0;
                if (p != pre) {
                    return false;
                }
            }
        }
        return true;
        };
    int l = 1, r = n;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << l << "\n";
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
