/*
  1.实际上是两个元素配对
  如果x，y属于对 （x <= y）
  提示1. x与y mod k的 余数应相等  （x加上 t*k 后才能变为y）
  提示2. (y-x)/k=y/k-x/k;

  so：将余数相同的进行分组
  对于每一组排序
  分类讨论 每组个数的奇偶性
  1.元素个数为偶数 则两两配对 无剩余  配对规则 要尽可能减少操作次数那么 （a2-a1 ,a4-a3,a6-a5...）一次类推

  2.元素个数为奇数 两两配对后 则会剩余一个元素 这个剩余是哪个一个不知道 因为不知到去掉某一个 次数会变小
    提示3. 如果元素个数为奇数的个数 大于 1 个 则肯定没法满足题目条件

    现在讨论删哪一个
    a1,a2,a3,a4,a5
    先把a1删掉的次数记为sum
    res=sum;
    之后应该枚举 删a3 .. 删除的下标为 i+=2（想想为什么）
    a0 a1 a2 a3 a4 a5 a6
           2     3  
    每删一个sum+=(a[i+1]-a[i])/k;
           sum-=(a[i+2]-a[i+1])/k

           res=min(res,sum)

*/
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    map<int, vector<int>>p;
    int odd = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        p[a % k].push_back(a);
    }
    i64 ans = 0;
    for (auto& [_, a] : p) {
        sort(a.begin(), a.end());

        if (a.size() % 2 == 0) {
            for (int i = 0; i < a.size(); i += 2) {
                ans += (a[i + 1] - a[i]) / k;
            }
        }
        else {
            odd++;
            i64 sum = 0;
            for (int i = 1; i < a.size(); i += 2) {
                sum += (a[i + 1] - a[i]) / k;
            }
            i64 res = sum;
            for (int i = 0; i + 1 < a.size(); i += 2) {
                sum += (a[i + 1] - a[i]) / k;
                sum -= (a[i + 2] - a[i + 1]) / k;
                res = min(res, sum);
            }
            ans += res;
        }
    }
    if (odd > 1) {
        ans = -1;
    }
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
