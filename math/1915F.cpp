/* 
    ai<bi &&以及所有人的起点和终点都是不同的;
    容易发现 假设两条线段 只有一条是其中一条子集的时候才会打招呼;
    so: 按起点进行排序 比较终点;
    考虑第 i 个人  前面i-1 人 有多少人的终点比 第i个人大;
    so : 经典问题 : 求逆序对的数量;

     法一 ：merge_sort ;
     法二: 树状数组;
     
    https://codeforces.com/contest/1915/problem/F
    
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll ans = 0;
void  merge(vector<pair<int, int>>& a, vector<int>& t, int l, int r) {
    if (l >= r)return;

    int mid = l + r >> 1;

    merge(a, t, l, mid);
    merge(a, t, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (a[i].second <= a[j].second) {
            t[k++] = a[i++].second;
        }
        else {
            ans += mid - i + 1;
            t[k++] = a[j++].second;
        }
    }
    while (i <= mid)t[k++] = a[i++].second;
    while (j <= r)t[k++] = a[j++].second;

    for (i = l, j = 0; i <= r; i++, j++) {
        a[i].second = t[j];
    }
}
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>>a(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = { x,y };
    }
    sort(a.begin(), a.end());
    // for (auto [x, y] : a) {
    //     cout << x << " " << y << "\n";
    // }
    ans = 0;
    vector<int>t(n);
    merge(a, t, 0, n - 1);
    //copy(t.begin(), t.end(), ostream_iterator<int>(cout, " "));
    cout << ans << "\n";
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
