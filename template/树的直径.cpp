/*
  树形DP
  树的直径指树上两点最远距离。
  从下往上看 从一个叶子出发向上，到达某个节点拐弯，向下到达另一个叶子
  得到有两条链拼起来的路径（也可能只有一条链）

  在当前节点拐弯的的直径长度 = 左子树的最长链 + 右子树的最长链 + 2；
  返回给父节点的是以 当前节点 为根 的子树的最长链
  = max（左子树的最长链，右子树的最长链）+ 1
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int inf = 1e9;
constexpr int N = 1e6;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int>e[n + 1];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }int ans = 0;
    function<int(int, int)>dfs = [&](int cur, int fa)->int {

        int x_len = 0;
        for (auto v : e[cur]) {
            if (v == fa)continue;
            int y_len = dfs(v, cur) + 1;
            ans = max(ans, x_len + y_len);
            x_len = max(x_len, y_len);
        }
        return x_len;
        };
    dfs(1, 0);
    cout << ans ;
    return 0;
}
