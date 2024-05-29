/*
   考虑贡献 对于字符串t t[0],t[1],....,t[t.size()-1]会和字符串s中那些位进行运算

   字符串s最远移到的位置为 t.size()-s.size()+1 (开头最多到3)
   例如：
   s:0 1
   t:0 0 1 1 1
     0 1 2 3 4
   依次类推s的第二位置能与那些匹配
   发现匹配的长度为定值k=t.size()-s.size()+1；
   算出t的前缀和
   之后枚举起点（i=k-1）刚好是第一个窗口的最大距离
   之后计算t:0-i的值-有k个s0和它匹配
   依次类推
   
   https://codeforces.com/problemset/problem/608/B
   灵茶 2024.5.28
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s, t;
    cin >> s >> t;
    vector<int>a(t.size() + 1);
    for (int i = 0; i < t.size(); i++) {
        a[i + 1] = a[i] + t[i] - '0';
    }
    ll ans = 0;
    int k = t.size() - s.size() + 1;
 //   cerr << k << "\n";
    for (int i = k - 1, l = 0; i < t.size(); i++, l++) {
        ll p = a[i + 1] - a[l];
        ans += abs(p - k * (s[l] - '0'));
    }
    cout << ans << "\n";
    return 0;
}
