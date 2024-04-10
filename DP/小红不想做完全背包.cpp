/*
  对所有  模 ，这样是等价的。以下的每一个数默认是模  后的结果。
  对于  个编号为  的点，进行连边：编号为  的点向编号为  的点连边。每经过一条边，相当于选了一个物品。
  起始点为 ，进行广度优先搜索，搜索到编号为  的点所经过的距离  即为所求。
  (同于最短路)

  也可以dp做
   定义 dp[i] 表示，选择的数字总和对 p 取余等于 i，的最少选择数字个数
   https://ac.nowcoder.com/acm/contest/78904/D
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int n, k;
   cin >> n >> k;
   vector<ll>a(n);
    vector<ll>dp(k,1e18);
    // 定义 dp[i] 表示，选择的数字总和对 p 取余等于 i，的最少选择数字个数
   for (int i = 0; i < n; i++) {
      cin >> a[i];
       a[i]%=k;
       dp[a[i]]=1;
       for(int j=0;j<k;j++){
           dp[(j+a[i])%k]=min(dp[(j+a[i])%k],dp[j]+1);
       }
   }
    cout<<dp[0];
   //dfs(i,0,cnt,s)
   //dfs(i,1,cnt+1,s+a[i])
//     int ans=k;
//    auto dfs=[&](auto self,int i,int cnt,int s){
//         if(i<0){
//             if(s%k==0&&s)ans=min(ans,cnt);
//             return ;
//         }
//       if(s%k==0&&s)ans=min(ans,cnt+1);
//        self(self,i-1,cnt+1,s+a[i]);
//        self(self,i-1,cnt,s);
        
//    };
//     dfs(dfs,n-1,0,0);
//     cout<<ans<<"\n";
   return 0;
}
