/*
   将 nnn 转换成字符串 sss，定义 f(i,mask,isLimit,isNum)表示构造第 i 位及其之后数位的合法方案数，其余参数的含义为：

   mask表示前面选过的数字集合，换句话说，第 i 位要选的数字不能在 mask 中。
   isLimit 表示当前是否受到了 n 的约束（注意要构造的数字不能超过 n）。若为真，则第 i 位填入的数字至多为 s[i]，否则可以是 9。如果在受到约束的情况下填了 s[i]，那么后续填入的数字仍会受到 n 的约束。
   例如 n=123，那么 i=0 填的是 1 的话，i=1 的这一位至多填 2。
   isNum 表示 i 前面的数位是否填了数字。若为假，则当前位可以跳过（不填数字），或者要填入的数字至少为 1；若为真，则要填入的数字可以从 0 开始。
   例如 n=123，在 i=0时跳过的话，相当于后面要构造的是一个 99以内的数字了，如果 i=1 不跳过，那么相当于构造一个 10 到 99 的两位数，如果 i=1 跳过，相当于构造的是一个 9 以内的数字。
   实现细节
   递归入口：f(0, 0, true, false)，表示：

   从 s[0] 开始枚举；
   一开始集合中没有数字；
   一开始要受到 n 的约束（否则就可以随意填了，这肯定不行）；
   一开始没有填数字。
    递归中：

    如果 isNum 为假，说明前面没有填数字，那么当前也可以不填数字。一旦从这里递归下去，isLimit 就可以置为 false 了，这是因为 s[0] 必然是大于 0 的，后面就不受到 n 的约束了。
    或者说，最高位不填数字，后面无论怎么填都比 n 小。
    如果 isNum 为真，那么当前必须填一个数字。枚举填入的数字，根据 isNum 和 isLimit 来决定填入数字的范围。
    递归终点：当 i 等于 s 长度时，如果 isNum 为真，则表示得到了一个合法数字（因为不合法的不会继续递归下去），返回 1，否则返回 0。

    https://leetcode.cn/problems/count-special-integers/description/
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int inf = 1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    string s = to_string(n);
    int m = s.size();
    vector<vector<int>>dp(m, vector<int>(1 << 10, -1));
    function<int(int, int, bool, bool)>f = [&](int i, int mask, bool is_limit, bool is_num)->int {
        if (i == m) {
            return is_num;
        }
        if (!is_limit && is_num && dp[i][mask] != -1) {
            return dp[i][mask];
        }
        int res = 0;
        if (!is_num) {
            res = f(i + 1, mask, false, false);
        }
        int up = is_limit ? s[i] - '0' : 9;
        for (int d = 1 - is_num; d <= up; d++) {
            if ((mask >> d & 1) == 0) {
                res += f(i + 1, mask | 1 << d, is_limit && d == up, true);
            }
        }
        if (!is_limit && is_num) {
            dp[i][mask] = res;
        }
        return res;
        };
    return 0;
}
