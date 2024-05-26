#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const double eps = 1e-6;
struct P {
    int d, s, t;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<P>a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i].d = i + 1;
        a[i].s += n - x + 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].t;
    }
    sort(a.begin(), a.end(), [](P a, P b) {
        return a.t > b.t;
        });
    for (int i = 0; i < n; i++) {
        a[i].s += n - i;
    }
    sort(a.begin(), a.end(), [](P a, P b) {
        if (a.s == b.s) {
            return a.t > b.t;
        }
        return a.s > b.s;
        });
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ":" << "MU00";
        if (a[i].d < 10) {
            cout << 0;
        }
        cout << a[i].d << "(" << a[i].s << ")" << "\n";
    }
    return 0;
}
/*
  3
  3 1 2
  20 50 10
  
  1:MU0002(6)
  2:MU0001(3)
  3:MU0003(3)
*/
