/*
   先序+中序  或者  中序+后序 能确定唯一一颗二叉树;
   通过递归实现 后序 或 先序 遍历

 */ 
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    auto last = [&](auto self, string pre, string mid)->void {
        if (mid.size() > 0) {
            char op = pre[0];
            auto it = mid.find(op);
            self(self, pre.substr(1, it), mid.substr(0, it));
            self(self, pre.substr(it + 1), mid.substr(it + 1));
            cout << op;
        }
        };
    string a, b;
    while (cin >> a >> b) {
        last(last, a, b);
    }

    return 0;
}
