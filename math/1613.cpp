/*
  分情况讨论  <t 乌龟和兔子同时走  否则 判断在s 秒内乌龟走多远
  
  https://acm.webturing.com/problem.php?id=1613
*/
#include<bits/stdc++.h>
#include<fstream>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int v1, v2, t, s, l;
    cin >> v1 >> v2 >> t >> s >> l;
    int T = l / v2;
    if (v1 < v2) {

        cout << "T\n";
        cout << T << "\n";
    }
    else if (v1 == v2) {
        cout << "D\n";
        cout << T << "\n";

    }
    else {
        int S1 = 0;
        int S2 = 0;
        int i = 0;
        while (S1 < l && S2 < l) {
            if (S1 - S2 >= t) {
                for (int j = 0; j < s && S2 < l; j++) {
                    S2 += v2;
                    i++;
                }
                if (S2 >= l)break;
            }
            else {
                S2 += v2;
                S1 += v1;
                i++;
                if (S1 == l || S2 == l)break;
            }
        }
        if (S2 == l && S1 == l) {
            cout << "D\n";
            cout << T << "\n";
        }
        else if (S2 == l) {
            cout << "T" << "\n";
            cout << T << "\n";
        }
        else if (S1 == l) {
            cout << "R\n";
            cout << i << "\n";
        }
    }
    return 0;
}
