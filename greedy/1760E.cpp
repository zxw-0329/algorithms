#include<bits/stdc++.h>
using namespace std;//格式化shift+alt+f
using ll = long long;//https://codeforces.com/contest/1760/problem/E;贪心加数学

void solve(){
     int n;
     cin>>n;
     int c1=0,c0=0;
     ll ans=0;
     int x0=-1,x1=-1;
     for(int i=0;i<n;i++){
         int x;
         cin>>x;
         if(x==0){
            c0++;
            ans+=c1;
            if(x0==-1){
               x0=i;
            }
         }
         else{
            c1++;
            x1=i;
         }
     }
    ll res=ans;
    if(x0!=-1){//第一个0变1;
      ans=max(ans,res-x0+(c0-1));
    }
    if(x1!=-1){//最后一个1变0;
      ans=max(ans,res-(n-1-x1)+(c1-1));
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
