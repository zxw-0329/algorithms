/*
  给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数，结果需要对 109 + 7 取模。
  https://leetcode.cn/problems/distinct-subsequences/solutions/661691/xiang-jie-zi-fu-chuan-pi-pei-wen-ti-de-t-wdtk/
  https://leetcode.cn/problems/distinct-subsequences/solutions/661537/shou-hua-tu-jie-xiang-jie-liang-chong-ji-4r2y/

*/
const int mod=1e9+7;
using ll=long long;
class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        // s=" "+s;
        // t=" "+t;
        // vector<vector<int>>dp(n+1,vector<int>(m+1));
        // for(int i=0;i<n;i++)dp[i][0]=1;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
                
        //         if(s[i]==t[j]){
        //             dp[i+1][j+1]=(dp[i][j+1]+dp[i][j])%mod;
        //         }
        //         else dp[i+1][j+1]=dp[i][j+1];
        //     }
        // }
        // return dp[n][m];
        vector<vector<int>>f(n,vector<int>(m,-1));
        function<int(int,int)>dfs=[&](int i,int j)->int{
              if(j<0){
                return 1;
              }
              if(i<0){
                return 0;
              }
              if(f[i][j]!=-1)return f[i][j];
              ll res=0;
              if(s[i]==t[j]){
                 res=(res+dfs(i-1,j-1))%mod;
              }
              res=(res+dfs(i-1,j))%mod;
              f[i][j]=res;
              return res;
        };
        return dfs(n-1,m-1);
    }
};
