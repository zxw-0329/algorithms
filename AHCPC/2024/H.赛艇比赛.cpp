#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>>a(n, vector<int>(m, 0));
    vector<vector<int>>b(n, vector<int>(310, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            b[i][a[i][j]]++;
        }
        sort(a[i].begin(), a[i].end());
    }
    vector<int>w(n);
    vector<int>l(n);
    for (int i = 0; i < n; i++) {//最多获胜场次
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (j == i)continue;
            auto p = a[i];
            auto q = b[j];//枚举第j个人的速度，看第i个人是否有大于其的速度;
            int s = 0;
            for (int k = 0; k <= 300; k++) {
                while (q[k]) {
                    auto it = upper_bound(p.begin(), p.end(), k);
                    if (it != p.end()) {
                        q[k]--;
                        s++;
                        p.erase(it);
                    }
                    else break;
                }
            }
            cnt = max(cnt, s);
        }
        w[i] = cnt;
    }
    for (int i = 0; i < n; i++) {//最少获胜场次
        int cnt = m;
        for (int j = 0; j < n; j++) {
            if (j == i)continue;
            auto p = b[i];
            auto q = a[j];//枚举第i个人的速度，看第j个人是否有大于其的速度;
            int s = 0;
            for (int k = 0; k <= 300; k++) {
                while (p[k]) {
                    auto it = lower_bound(q.begin(), q.end(), k);
                    if (it != q.end()) {
                        p[k]--;
                        s++;
                        q.erase(it);
                    }
                    else break;
                }
            }
            cnt = min(cnt, m - s);
        }
        l[i] = cnt;
    }
    for (int i = 0; i < n; i++) {
        cout << l[i] << " " << w[i] << "\n";
    }
    return 0;
}
