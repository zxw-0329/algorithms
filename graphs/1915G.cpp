/*
  我们可以用 n⋅1000个节点构建一个图，每个节点负责一对 (i,s)，其中 i是城市的索引， s是我们在这个城市时的速度。然后，我们可以使用 Dijkstra 算法，通过考虑节点 i
 的所有边来计算该图上的最短路径(当我们在一对以 i为城市时)，新的 s将是 si和 sj的最小值，其中 j是我们考虑的邻近城市。计算完节点 (1,s1)
 的所有最短路径后，我们只需找出从 1到 1000的所有 j中 (n,j)的最小值，这就是我们的答案

 
  https://codeforces.com/contest/1915/problem/G
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
     int n,m;
     cin>>n>>m;
    // cout<<n<<" "<<m<<"\n";
     vector<pair<int,int>>e[m+1];
     vector<int>s(n);
     for(int i=0;i<m;i++){
       int a,b,c;
       cin>>a>>b>>c;
       a--;b--;
       e[a].push_back({b,c});
       e[b].push_back({a,c});
     }
     for(int i=0;i<n;i++)cin>>s[i];
     vector<int>d(n*n,-1LL);
     priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>>q;
     q.push({0,0});
     while(!q.empty()){
          auto t=q.top();
          q.pop();
          int u=t.second;
          if(d[u]!=-1)continue;
          d[u]=t.first;
          int c=u/n,b=u%n;
          if(c==n-1){
               cout<<t.first<<"\n";
               return ;
          }
          q.emplace(t.first,c*n+c);
          for(auto e:e[c]){
              q.emplace(t.first+s[b]*e.second,e.first*n+b);
          }
     }
}
int main(){
      ios::sync_with_stdio(false);
      cin.tie(nullptr);
      cout.tie(nullptr);
       int t=1;
      cin>>t;
      while(t--){
        solve();
     }
     return 0;
}
/*
using ll = long long;
const ll inf = 1e18;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, ll>>adj[m+1];
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    vector<pair<int,int>>s(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s[i] = { x,i };
    }
    vector<ll>ans(n, -1);//ans[i]表示i 到n-1的最短时间
    sort(s.begin(), s.end(), [&](auto a, auto b) {return a.first < b.first; });
    auto bfs = [&](int x, int v)->void {
        vector<ll>dis(n,1e18);  //从 x到达 i的最小距离
        queue<int>q;
        q.emplace(x);
        dis[x] = 0;
        while (q.size()){
            int t = q.front();
            q.pop();
            for (auto e : adj[t]) {
                int y = e.first;
                int p = e.second;
                if (p + dis[t] < dis[y]) {
                    dis[y] = p + dis[t];
                    q.emplace(y);
                }
            }
        }
        ans[x] = v * dis[n-1];
        for (int i = 0; i < n - 1; i++) {
            if (i != x && ans[i] != -1)ans[x] = min(ans[x], ans[i] + dis[i] * v);
        }
    };
    for (int i = 0; i <= n - 1; i++) {
        bfs(s[i].second, s[i].first);
    }
    cout << ans[0] << "\n";
}

*/
