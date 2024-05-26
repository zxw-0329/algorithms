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
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (j == i)continue;
            auto r = a[i];
            auto u = b[j];
            int s = 0;
            for (int k = 0; k <= 300; k++) {
                while (u[k]) {
                    auto it = upper_bound(r.begin(), r.end(), k);
                    if (it != r.end()) {
                        u[k]--;
                        s++;
                        r.erase(it);
                    }
                    else break;
                }
            }
            cnt = max(cnt, s);
        }
        w[i] = cnt;
    }
    for (int i = 0; i < n; i++) {
        int cnt = m;
        for (int j = 0; j < n; j++) {
            if (j == i)continue;
            auto r = b[i];
            auto u = a[j];
            int s = 0;
            for (int k = 0; k <= 300; k++) {
                while (r[k]) {
                    auto it = lower_bound(u.begin(), u.end(), k);
                    if (it != u.end()) {
                        r[k]--;
                        s++;
                        u.erase(it);
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
