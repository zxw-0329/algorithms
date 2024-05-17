/*
  时间戳 dfn[x]：节点x第一次被访问的顺序
  
  追溯值 low[x]: 从节点x出发，所能访问的最早时间戳

  割点的判定：
  如果x不是根节点，当搜索树上存在x一个子节点y，满足 low[y]>=dfn[x] ，那么 x 是割点
  如果x是x根节点，当搜索树上至少存在两个子节点y1，y2，满足 满足上述条件 ，那么 x 是割点 

  https://www.bilibili.com/video/BV1QL4y1N7bC/?spm_id_from=333.999.0.0&vd_source=7e2ae3859dfc2b030d597a1ee3dcc5d4

  https://www.luogu.com.cn/problem/P3388
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int inf = 1e9;
constexpr int N = 2e5 + 10;
int dfn[N], low[N], tot;
int8_t cut[N];
vector<vector<int>>adj;
//int cnt;
int root;
void tarjan(int x) {
    dfn[x] = low[x] = ++tot;
    int c = 0;
    for (auto y : adj[x]) {
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
            if (low[y] >= dfn[x]) {
                c++;
                if (x != root || c > 1) {
                    cut[x] = 1;
                   // cnt++;
                }
            }
        }
        else {
            low[x] = min(low[x], dfn[y]);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (root = 1; root <= n; root++) {
        if (!dfn[root]) {

            tarjan(root);
        }
    }
    
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += cut[i];
    }
    cout << cnt << "\n";
    for (int i = 1; i <= n; i++) {
        if(cut[i])
        cout << i << " ";
    }
    return 0;
}
