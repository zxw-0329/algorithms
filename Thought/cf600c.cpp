/*
  变成回文串
  把奇数的挑出来
  根据题目要求 词法最小 小的奇数增多 大的奇数减少
  https://codeforces.com/contest/600/problem/C
*/
#include<bits/stdc++.h>

using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    freopen("input.in", "r", stdin);
    string s;
    cin >> s;
    int cnt[26]{};
    for (int i = 0; i < s.size(); i++) {
        cnt[s[i] - 'a']++;
    }
    vector<int> odd;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] & 1) {
            odd.push_back(i);
        }
    }
    for (int i = 0; i < odd.size() / 2; i++) {
        cnt[odd[i]]++;
        cnt[odd[odd.size() - i - 1]]--;
    }
    string ans = "";
    if ((odd.size() & 1)) {

        ans = string(1, 'a' + odd[odd.size() / 2]);
        cnt[odd[odd.size() / 2]]--;

    }
    for (int i = 25; i >= 0; i--) {
        ans = string(cnt[i] / 2, 'a' + i) + ans + string(cnt[i] / 2, 'a' + i);
    }
    cout << ans << "\n";
    return 0;
}
