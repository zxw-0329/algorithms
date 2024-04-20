#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 5000011;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int n;
   cin >> n;
   string s = to_string(n);
   int m = s.size();
   function<int(int, bool)>f = [&](int i, bool is_limit)->int {
      if (i == m) {
         return 1;
      }
      int lo = 0;//下界
      int up = is_limit ? s[i] - '0' : 9;//上界是否受到limit约束;前i-1位是否都为最上界;
      int res = 0;
      for (int d = lo; d <= up; d++) {
         res += f(i + 1, is_limit && d == up);
      }
      return res;
      };
   return 0;
}
