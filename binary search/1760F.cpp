/*
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
bool check(ll k,vector<int>&a,ll d,ll c){
    ll res = 0;
    int n=a.size();
    for (int i = 0; i < min(n*1LL, k + 1); i++) {
         res += 1LL * a[i] * (d / (k + 1) + (d % (k + 1) > i));
    }
    return res>=c;
}
void solve() {
     int n;
     ll c,d;
     cin>>n>>c>>d;
     vector<int>a(n);
     for(int i=0;i<n;i++){
        cin>>a[i];
     }
     sort(a.begin(),a.end(),[&](auto a,auto b){return a>b;});
    //   if (1LL * a[0] * d < c) {
    //     cout << "Impossible\n";
    //     return;
    // }
     ll l=0,r=d+1;//左闭右开
     while(l<r){
         ll mid=(l+r)/2;
         if(check(mid,a,d,c)){//[l,mid]满足条件,l=mid+1不一定
            l=mid+1;   //l的值不确定是否满足条件
         }
         else{   //[mid+1,r)不满足条件，r=mid不一定
            r=mid;
         }
     }
     //当l+1==r时;mid=l,如果mid满足,l=mid+1==r不满足结束循环 答案为:l-1;
     //                 如果mid不满足,r=mid=l不满足结束循环 答案为:l-1;
     if(l-1<0){
        cout << "Impossible\n";
     }
     else if(l>=d){
        cout<<"Infinity\n";
     }
     else cout<<l-1<<"\n";
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
*/

/*
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
bool check(ll k,vector<int>&a,ll d,ll c){
    ll res = 0;
    int n=a.size();
    for (int i = 0; i < min(n*1LL, k + 1); i++) {
         res += 1LL * a[i] * (d / (k + 1) + (d % (k + 1) > i));
    }
    return res>=c;
}
void solve() {
     int n;
     ll c,d;
     cin>>n>>c>>d;
     vector<int>a(n);
     for(int i=0;i<n;i++){
        cin>>a[i];
     }
     sort(a.begin(),a.end(),[&](auto a,auto b){return a>b;});
    //   if (1LL * a[0] * d < c) {
    //     cout << "Impossible\n";
    //     return;
    // }
     ll l=0,r=d;
     while(l<=r){//左闭右闭
         ll mid=(l+r)/2;
         if(check(mid,a,d,c)){
            l=mid+1;       //[l,mid]满足条件，mid+1不一定
         }
         else{
            r=mid-1;     //k太大,[mid,r]不满足条件
         }
     }
     //当l==r时,mid==l==r满足条件时,l=mid+1不满足条件,l-1和r满足条件 答案为:l-1;
     //         mid==l==r不满足条件, r=mid-1满足条件,l-1和r满足条件  答案为:l-1;
    //结束时r+1=l
     if(l-1<0){
          cout<<"Impossible\n";
     }
     else if(l>d){
        cout<<"Infinity\n";
     }
     else cout<<l-1<<"\n";
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
*/
