#include<bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
double calc(double x, double y, double z) {

    return x * x + y * y + z * z;
}
constexpr double eps = 1e-9;
const double PI = acos(-1.0);
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    cout << fixed << setprecision(2);
    double xa, ya, za;
    cin >> xa >> ya >> za;
    double xb, yb, zb;
    cin >> xb >> yb >> zb;

    double xc, yc, zc;
    cin >> xc >> yc >> zc;

    double r;
    cin >> r;

    vector<double>BA = { xa - xb,ya - yb,za - zb };
    vector<double>CA = { xa - xc,ya - yc,za - zc };
    vector<double>CB = { xb - xc,yb - yc,zb - zc };
    double ba = sqrt(calc(BA[0], BA[1], BA[2]));
    double ca = sqrt(calc(CA[0], CA[1], CA[2]));
    double cb = sqrt(calc(CB[0], CB[1], CB[2]));
    double t = sqrt(calc(BA[1] * CA[2] - BA[2] * CA[1], BA[2] * CA[0] - BA[0] * CA[2], BA[0] * CA[1] - BA[1] - CA[0]));

    double d = t / ba;
    if (t >= ba * r) {
        //cout << ba << "\n";

        cout << ba;
        return 0;

    }
    double BD = sqrt(cb * cb - r * r);
    double T = BD / ba;
    vector<double>D(3);//C点垂直于AB的D点
    D[0] = xb + T * BA[0];
    D[1] = yb + T * BA[1];
    D[1] = zb + T * BA[2];
    // cerr << ba << "\n";
    double pp = (xb - D[0]) * (xa - D[0]) + (yb - D[1]) * (ya - D[1]) + (zb - D[2]) * (za - D[2]);

    if (pp >= 0) {
        cout << ba;
        return 0;
    }

    double CAB = CB[0] * CA[0] + CB[1] * CA[1] + CB[2] * CA[2];
    double u = acosl(CAB / (ca * cb));
    double u1 = acosl(r / ca);
    double u2 = acosl(r / cb);
    double p = u - u1 - u2;
    double ans = sqrt(ca * ca - r * r) + sqrt(cb * cb - r * r) + p * r;
    cout << ans;
    return 0;
}
