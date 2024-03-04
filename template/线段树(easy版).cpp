/*
   基于分治思想 ,用来维护区间信息(区间和 , 区间最值 , 区间GCD 等);
   可以在log(n)的时间内进行区查 ,区修
   
   https://www.luogu.com.cn/problem/P3374
   
*/  
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
struct tree {
    int l, sum, r;
}tr[4 * N];
int n;
vector<int>a;
void build(int p, int l, int r) {
    tr[p] = { l,a[l],r };
    if (l == r)return;
    int m = l + r >> 1;
    build(2 * p, l, m);
    build(2 * p + 1, m + 1, r);
    tr[p].sum = tr[2 * p].sum + tr[2 * p + 1].sum;
}
void update(int p, int x, int k) {
    if (tr[p].l == x && tr[p].r == x) {
        tr[p].sum += k;
        return;
    }
    int m = tr[p].l + tr[p].r >> 1;
    if (x <= m) {
        update(2 * p, x, k);
    }
    else update(2 * p + 1, x, k);
    tr[p].sum = tr[2 * p].sum + tr[2 * p + 1].sum;
}
int qurry(int p, int x, int y) {

    if (x <= tr[p].l && tr[p].r <= y) {
        return tr[p].sum;
    }
    int sum = 0;
    int m = tr[p].l + tr[p].r >> 1;
    if (x <= m) {
        sum += qurry(2 * p, x, y);
    }
    if (y > m) {
        sum += qurry(2 * p + 1, x, y);
    }
    return sum;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int m;
    cin >> n >> m;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    while (m--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            update(1, x, y);
        }
        else {
            cout << qurry(1, x, y) << "\n";
        }
    }
    return 0;
}
