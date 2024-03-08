/*
   a,b互质 不能组成最大的数为 a*b-a-b ;
   
   证明 :https://www.cnblogs.com/onlyblues/p/16131730.html
   
   https://acm.webturing.com/problem.php?id=1615
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    cout << n * m - n - m << "\n";
    return 0;
}
