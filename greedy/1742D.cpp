/*
给定一个由 n个正整数a1,a2,…,an(1≤ai≤1000) 组成的数组.求 i+j的最大值,
使得 ai和 aj同素,如果不存在这样的i,j输出-1
2≤n≤2⋅105
*/
/*  https://codeforces.com/contest/1742/problem/D
思路:虽然n很大,但a的值域很小最大只有1000
     所以相同的数会出现很多次;
     要使i+j最大只需记录每个数最后一次出现的位置
     暴力枚举每个数使gcd(i,j)==1,并更新答案为最大值;
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
     int n;
     cin>>n;
     vector<int>last(1001);
     for(int i=0;i<n;i++){
        int x;
        cin>>x;
        last[x]=i+1;
     }
     int ans=-1;
     for(int i=1;i<=1000;i++){
        for(int j=1;j<=i;j++){
           if(last[i]&&last[j]&&__gcd(i,j)==1){
              ans=max(last[i]+last[j],ans);
           }
        }
     }
     cout<<ans<<"\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
