/*

  模板题：Dijkstra 算法
  
  在更新前多加一个判断是否能在消失前到达

  https://leetcode.cn/problems/minimum-time-to-visit-disappearing-nodes/description/
*/
class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edge, vector<int>& disappear) {
        vector<pair<int,int>>e[n];
        int t=edge.size();
        for (int i = 0; i < t; i++) {
            int a=edge[i][0];
            int b=edge[i][1];
            int c=edge[i][2];
            e[a].push_back({ b,c });
            e[b].push_back({ a,c });
        }
        vector<int>d(n);
        auto dijkstra=[&](int s) {
             for (int i = 0; i <n; i++) {
                 d[i] = INT_MAX;
             }
             priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>>q;
             vector<int>vis(n);
             d[s] = 0;
             q.push({ 0,s });
             while (q.size()) {
                    auto t = q.top();
                    q.pop();
                    int u = t.second;
                    if (vis[u])continue;
                    vis[u] = 1;
                for (auto ed : e[u]) {
                    int v = ed.first, w = ed.second;
                    if (d[v] > d[u] + w) {
                      if(d[u]+w<disappear[v]){
                          d[v] = d[u] + w;
                         q.push({ d[v],v });
                      }
                }
              }
            }
          };
        dijkstra(0);
        for(int i=0;i<n;i++){
            if(d[i]==INT_MAX||d[i]>disappear[i]){
                d[i]=-1;
            }
        }
        return d;
    }
};
