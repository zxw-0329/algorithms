/*
  1.数学公式
  2.数位dp :https://ac.nowcoder.com/acm/contest/view-submission?submissionId=70163915

  https://ac.nowcoder.com/acm/contest/86639/D
  公式推导如下
  https://leetcode.cn/problems/maximum-number-that-sum-of-the-prices-is-less-than-or-equal-to-k/solutions/2603673/er-fen-da-an-shu-wei-dpwei-yun-suan-pyth-tkir/
 */ 
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T>
constexpr T power(T a, ll b) {
    T res{ 1 };
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

constexpr ll mul(ll a, ll b, ll p) {
    ll res = a * b - ll(1.L * a * b / p) * p;
    res %= p;
    if (res < 0) {
        res += p;
    }
    return res;
}

template<ll P>
struct MInt {
    ll x;
    constexpr MInt() : x{ 0 } { }
    constexpr MInt(ll x) : x{ norm(x % getMod()) } { }

    static ll Mod;
    constexpr static ll getMod() {
        if (P > 0) {
            return P;
        }
        else {
            return Mod;
        }
    }
    constexpr static void setMod(ll Mod_) {
        Mod = Mod_;
    }
    constexpr ll norm(ll x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }
    constexpr ll val() const {
        return x;
    }
    constexpr MInt operator-() const {
        MInt res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr MInt inv() const {
        return power(*this, getMod() - 2);
    }
    constexpr MInt& operator*=(MInt rhs)& {
        if (getMod() < (1ULL << 31)) {
            x = x * rhs.x % int(getMod());
        }
        else {
            x = mul(x, rhs.x, getMod());
        }
        return *this;
    }
    constexpr MInt& operator+=(MInt rhs)& {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MInt& operator-=(MInt rhs)& {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MInt& operator/=(MInt rhs)& {
        return *this *= rhs.inv();
    }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MInt operator+(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MInt operator/(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream& operator>>(std::istream& is, MInt& a) {
        ll v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr std::ostream& operator<<(std::ostream& os, const MInt& a) {
        return os << a.val();
    }
    friend constexpr bool operator==(MInt lhs, MInt rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) {
        return lhs.val() != rhs.val();
    }
    friend constexpr bool operator<(MInt lhs, MInt rhs) {
        return lhs.val() < rhs.val();
    }
};

template<>
ll MInt<0>::Mod = 998244353;

constexpr int P = 998244353;
using Z = MInt<P>;

void solve() {
    ll l, r;
    cin >> l >> r;

    auto work = [&](ll x)->Z {
        Z ans = 0;
        for (int i = 0; i <= __lg(x); i++) {
            ll nums = x >> i;
            ans += ((nums / 2) << i);
            if (nums % 2) {
                ll mask = (1LL << i) - 1;
                ans += ((x & mask) + 1);
            }
        }
        return ans;
        };
    Z res = work(r) - work(l - 1);
    cout << res << "\n";
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
