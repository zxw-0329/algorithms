/*

  把长度相同的放在一个集合 字符串的最大长度为 5
  直接枚举相加长度为偶数的情况

  对于每一种为偶数的情况
  可以计算出 mid 的值
  找个 s = 50 (在0 - mid 之间加减不会 < 0 或 >100 )
  枚举前一个长度的字符串 统计 在mid的时候的值
  <mid  s+=x[k]-'0'   else s-=x[k]-'0'
  之后枚举后一个长度的字符串
  根据前一个字符串的长度 i 
  可以得出当 i +  k >=mid  s+=y[k]-'0' else s-=y[k]-'0'
  ans+=cnt[s]
*/
#include<bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    vector<string>a[6];

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        a[s.size()].push_back(s);
    }

    i64 ans = 0;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            if ((i + j) % 2 == 0) {
                int m = (i + j) / 2;
                vector<int>cnt(101);

                for (auto x : a[i]) {
                    int s = 50;
                    for (int k = 0; k < i; k++) {
                        if (k < m) {
                            s += x[k] - '0';
                        }
                        else s -= x[k] - '0';
                    }
                    cnt[s]++;
                }
                for (auto y : a[j]) {
                    int s = 50;
                    for (int k = 0; k < j; k++) {
                        if (i + k >= m) {
                            s += y[k]-'0';
                        }
                        else s -= y[k]-'0';
                    }
                    ans += cnt[s];
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
