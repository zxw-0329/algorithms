/*
  注意 与求解逆波兰式不同的是 遍历方向不同 其他无本质区别;
  其次注意 ( -  / ) 注意顺序;
   
  aoj 波兰式求值
 */ 
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
    for (int i = a.size() - 1; i >= 0;i--) {
        if (isdigit(a[i][0])) {
            string t=a[i];
            nums.emplace(stod(t)*1.0);
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
                    nums.emplace(x - y);
                }
                else if (p == '*') {
                    nums.emplace(x * y);
                }
                else {
                    nums.emplace(x*1.0 / y);
                }
            }
        }
    }
    double y = nums.top();
    printf("%.2f\n", y);
    return 0;
}
