/*
  题目大意：从根节点到叶子节点的一条路径上 不能超过m个连续的1
  
  https://codeforces.com/problemset/problem/580/C


*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>>adj(n);
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int ans = 0;
    auto dfs = [&](auto & self, int c, int p, int v)->void {

        if (v > m) {
            return;
        }
        bool ok = false;
        for (int i : adj[c]) {
            if (i == p)continue;
            if (v + a[i] == v) {
                ok = true;
                self(self, i, c, 0);
            }
            else {
                ok = true;
                self(self, i, c, v + 1);
            }

        }
        if (!ok) {
            ans++;
            return;
        }
    };
    dfs(dfs, 0, -1, (a[0] == 1));
    cout << ans << "\n";
    return 0;
}
