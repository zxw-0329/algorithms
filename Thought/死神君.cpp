/*
   每次合并要选最大的合并 这样才能是的花费最大
    如果当前值 <  其左边的值 应该将其左边的值合并 保证每次合并两个元素在左边最大
    维护一个栈 从底到顶单调递增 如果当前元素小于栈顶 要将栈内元素合并 < 当前值为止 保证没每次合并的值尽可能大

    注意在出栈时要注意当前元素与栈顶元素的大小
    比如数据
    5
    1 3 5 4 1
    当前值为4 时
    去掉5 时  应消耗 4
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    while (cin >> n) {
        vector<int>a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        stack<int>se;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            while (!se.empty() && a[i] < se.top()) {
                se.pop();
                if (!se.empty())ans +=max(a[i],se.top());
                else ans += a[i];
            }
            se.push(a[i]);
        }
        while (se.size() > 1) {
            se.pop();
            ans += se.top();
        }
        cout << ans << "\n";
    }
    return 0;
}
