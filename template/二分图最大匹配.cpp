#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>>e(n + 1);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            x--;
            e[i].push_back(x);
        }
    }
    vector<int>vis(n, 0), match(n, -1);
    auto dfs = [&](auto self, int u)->bool {

        for (int v : e[u]) {
            if (vis[v])continue;
            vis[v] = 1;
            if (match[v] == -1 || self(self, match[v])) {
                match[v] = u;
                return true;
            }
        }
        return false;
        };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        //vis.clear();
        fill(vis.begin(), vis.end(), 0);
        if (dfs(dfs, i))ans++;
    }
    if (ans == n) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
        cout << n - ans << "\n";
    }
    return 0;
}
