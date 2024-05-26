/*
  3 5 7 || 8 9 11 || 12 13 15 ||16 17 19 20
  分组找规律
  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int inf = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        if (x <= 3) {
            cout << 2 * x + 1 << "\n";
        }
        else {
            x -= 3;
            int p = (x + 2) / 3;
            int y = x % 3;
            if (y == 1) {
                cout << 8 + (p - 1) * 1LL * 4 << "\n";
            }
            else if (y == 2) {
                cout << 9 + (p - 1) * 1LL * 4 << "\n";
            }
            else {
                cout << 11 + (p - 1) * 1LL * 4 << "\n";
            }
        }
    }
    return 0;
}
