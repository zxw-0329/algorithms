#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const double eps = 1e-6;
void solve() {
    int m, k, s, l;
    cin >> m >> k >> s >> l;
    int mx = m * k;
    int t = s;
    for (int i = 0; i < l; i++) {
        int a;
        double p;
        cin >> a >> p;
        int y = ceil(a * 1.0 * p);//bug eps
        //cerr << t << " " << y << "\n";
        if (t + y > mx || t == mx) {
            cout << 0;
            continue;
        }
        t += y;
        cout << 1;
    }
    cout << "\n";
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
/*
input:
2
200 6 0 5
500 1.00
600 0.80
400 0.50
200 0.40
100 0.50
100 4 50 3
389 0.90
387 0.90
1 1.00

output:
11100
011
*/
