//后缀表达式 从前往后遍历 遇见操作符 取最近的两个数 进行操作;
// aoj 逆波兰式求值
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    vector<string>a;
    while (cin >> s) {
        a.push_back(s);
    }
    stack<char>op;
    stack<double>nums;
    for (int i = 0; i < a.size(); i++) {
        if (isdigit(a[i][0])) {
            string t(a[i].begin(),a[i].end());
            nums.emplace(stoi(t)*1.0);
        }
        else {
            op.push(a[i][0]);
            if (nums.size() > 1) {
                auto x = nums.top(); nums.pop();
                auto y = nums.top(); nums.pop();
                char p = op.top(); op.pop();
                if (p == '+') {
                    nums.emplace(x + y);
                }
                else if (p == '-') {
                    nums.emplace(y - x);
                }
                else if (p == '*') {
                    nums.emplace(x * y);
                }
                else {
                    nums.emplace(y*1.0 / x);
                }
            }
        }
    }
    double y = nums.top();
    printf("%.2f\n", y);
    return 0;
}
