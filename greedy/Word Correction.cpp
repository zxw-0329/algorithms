/*
 如何当前字符与前一个字符都为元音则删除当前字符

 这题n只有100(暴力即可) ，n可以开到1e6（贪心）
 遍历字符串，只输出前面没有元音的辅音和元音。
https://codeforces.com/contest/938/problem/A
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int>a(26);
    a['a' - 'a'] = a['e' - 'a'] = a['i' - 'a'] = a['o' - 'a'] = a['u' - 'a'] = a['y' - 'a'] = 1;
    cout << s[0];
    for (int i = 1; i < s.size(); i++) {
        if (!a[s[i - 1] - 'a'] || !a[s[i] - 'a']) {
            cout << s[i];
        }
    }
   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
