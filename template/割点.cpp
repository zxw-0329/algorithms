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
/*
洛谷 P3388 【模板】割点（割顶）
*/
#include <bits/stdc++.h>
using namespace std;
int n, m;  // n：点数 m：边数
int dfn[100001], low[100001], inde, res;
// dfn：记录每个点的时间戳
// low：能不经过父亲到达最小的编号，inde：时间戳，res：答案数量
bool vis[100001], flag[100001];  // flag: 答案 vis：标记是否重复
vector<int> edge[100001];        // 存图用的

void Tarjan(int u, int father) {  // u 当前点的编号，father 自己爸爸的编号
  vis[u] = true;                  // 标记
  low[u] = dfn[u] = ++inde;  // 打上时间戳
  int child = 0;             // 每一个点儿子数量
  for (auto v : edge[u]) {   // 访问这个点的所有邻居 （C++11）
    if (!vis[v]) {
      child++;                       // 多了一个儿子
      Tarjan(v, u);                  // 继续
      low[u] = min(low[u], low[v]);  // 更新能到的最小节点编号
      if (father != u && low[v] >= dfn[u] && !flag[u]) {  // 主要代码
        // 如果不是自己，且不通过父亲返回的最小点符合割点的要求，并且没有被标记过
        // 要求即为：删了父亲连不上去了，即为最多连到父亲
        flag[u] = true;
        res++;  // 记录答案
      }
    } else if (v != father) {  // 如果这个点不是自己，更新能到的最小节点编号
      low[u] = min(low[u], dfn[v]);
    }
  }
  // 主要代码，自己的话需要 2 个儿子才可以
  if (father == u && child >= 2 && !flag[u]) {
    flag[u] = true;
    res++;  // 记录答案
  }
}

int main() {
  cin >> n >> m;                  // 读入数据
  for (int i = 1; i <= m; i++) {  // 注意点是从 1 开始的
    int x, y;
    cin >> x >> y;
    edge[x].push_back(y);
    edge[y].push_back(x);
  }  // 使用 vector 存图
  for (int i = 1; i <= n; i++)  // 因为 Tarjan 图不一定连通
    if (!vis[i]) {
      inde = 0;      // 时间戳初始为 0
      Tarjan(i, i);  // 从第 i 个点开始，父亲为自己
    }
  cout << res << endl;
  for (int i = 1; i <= n; i++)
    if (flag[i]) cout << i << " ";  // 输出结果
  return 0;
}
