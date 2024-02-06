/*
https://codeforces.com/contest/1873/problem/D
给你一张长 s 格的纸条。每个单元格要么是黑色，要么是白色。在一次操作中，你可以取任意 k 个连续的单元格，并将它们全部变为白色。
请计算去除所有黑色单元格所需的最少操作次数。
贪心+双指针;
思路: 维护left指针如果当前为黑色判断right是否满足区间要求r>=l;
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int l=0,ans=0;
    for(int i=0;i<n;i++){
       if(s[i]=='B'&&i>=l){
          ans++;
          l=i+k;
       }
    }
    cout<<ans<<'\n';
} 
int main() {
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
