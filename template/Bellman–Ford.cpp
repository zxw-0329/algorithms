/*

  需要注意的是，以 S 点为源点跑 Bellman–Ford 算法时，如果没有给出存在负环的结果，只能说明从 S 点出发不能抵达一个负环，而不能说明图上不存在负环。
  因此如果需要判断整个图上是否存在负环，最严谨的做法是建立一个超级源点，向图上每个节点连一条权值为 0 的边，然后以超级源点为起点执行 Bellman–Ford 算法。
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int inf = 1e9;
constexpr int N = 100010;
struct Edge {
    int u, v, w;
};
vector<Edge>edge;
vector<pair<int, int>>e[N];
bool bellmanford(int n, int s) {
    vector<int>dis(n, inf);
    dis[s] = 0;
    bool flag = false;  // 判断一轮循环过程中是否发生松弛操作
    for (int i = 1; i <= n; i++) {
        flag = false;
        for (int j = 0; j < edge.size(); j++) {
            int u = edge[j].u, v = edge[j].v, w = edge[j].w;
            if (dis[u] == inf) continue;
            // 无穷大与常数加减仍然为无穷大
            // 因此最短路长度为 INF 的点引出的边不可能发生松弛操作
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                flag = true;
            }
        }
        // 没有可以松弛的边时就停止算法
        if (!flag) {
            break;
        }
    }
    // 第 n 轮循环仍然可以松弛时说明 s 点可以抵达一个负环
    return flag;
}
bool bellmanford1(int n, int s) {
    vector<int>d(n, inf);
    d[s] = 0;
    bool ok = false;
    for (int i = 0; i < n; i++) {//最多执行n-1轮松弛
        ok = false;
        for (int u = 0; u < n; u++) {
            if (d[u] == inf)continue;
            for (auto ed : e[u]) {
                int v = ed.first, w = ed.second;
                if (d[v] > d[u] + w) {
                    d[v] = d[u] + w;
                    ok = true;
                }
            }
        }
        if (!ok) {
            break;
        }
    }
    if (!ok) {// 第 n 轮循环仍然可以松弛时说明 s 点可以抵达一个负环
        cout << "存在环";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, s;
    cin >> n >> m >> s;
    s--;
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        e[a].push_back({ b,c });//邻接表
        edge.push_back({ a,b,c });
    }
    return 0;
}
