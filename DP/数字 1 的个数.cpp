/*
  套用 lc 2376的模板
  把mask去掉 改成cnt
  这里is_nums可有可无


  将 n 转换成字符串 s，定义 f(i,cnt1,isLimit)表示构造到从左往右第 i 位，已经出现了 cnt1 个 1，
  在这种情况下，继续构造最终会得到的 1 的个数（你可以直接从回溯的角度理解这个过程，只不过是多了个记忆化）。

  其余参数的含义为：
  cnt1表示左边填了多少个 1。
  isLimit表示当前是否受到了 n 的约束（我们要构造的数字不能超过 n）。
  若为真，则第 i 位填入的数字至多为n[i]，否则至多为 9，
  这个数记作 hi。如果在受到约束的情况下填了 n[i]，那么后续填入的数字仍会受到 n 的约束。
  例如 n=123，那么 i=0 填的是 1 的话，i=1 的这一位至多填 2。
  递归边界：当所有数字填完时，返回 cnt1
  递归入口：f(0,0,true)，一开始没有填数字，并且会受到 n 的约束
  
  https://leetcode.cn/problems/number-of-digit-one/

*/
class Solution {
public:
    int countDigitOne(int n) {
        string s = to_string(n);
        // int m = s.size();
        // vector<vector<int>> dp(m, vector<int>(1 << 10, -1));
        int m = s.length(), dp[m][m];
        memset(dp, -1, sizeof(dp)); // -1 表示没有计算过
        function<int(int, int, bool, bool)> f =
            [&](int i, int cnt, bool is_limit, bool is_nums) -> int {
            if (i == m) {
                return is_nums ? cnt : 0;
            }
            if(!is_limit&&dp[i][cnt]!=-1)return dp[i][cnt];
            int res = 0;
            if (!is_nums) {
                res += f(i + 1, cnt, false, false);
            }
            int up = is_limit ? s[i] - '0' : 9;
            for (int d = 1 - is_nums; d <= up; d++) {
                if(d==1){
                    res += f(i + 1, cnt + 1, is_limit && d == up, true);
                }
                else res += f(i + 1, cnt, is_limit && d == up, true);
                
            }
            if(!is_limit)dp[i][cnt]=res;
            
            return res;
        };
        return f(0, 0, true, false);
    }
};
