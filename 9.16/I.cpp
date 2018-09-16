//while (clock()<=4.9*CLOCKS_PER_SEC)
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#include "local_debug.h"
#else
#define debug(...)
#endif
#define pb push_back
#define rep(i,a,n) for(int i=(a);i<(n);++i)
#define per(i,a,n) for(int i=(n)-1;i>=(a);--i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
constexpr db PI = acos(-1), eps = 1e-8;
constexpr ll mod = (ll)1e9 + 7;
constexpr ll OO = 0x3f3f3f3f3f3f3f3f;
ll pow_mod(ll a, ll b) {
    assert(b >= 0);
    ll res = 1;
    for (a %= mod; b; b >>= 1, a = a * a % mod) {
        if (b & 1) {
            res = res * a % mod;
        }
    }
    return res;
}

double f(double x) {
    return 2.0 / (sqrt(sin(x) * sin(x) + 3) - sin(x));
}

double Simpson(double l, double r) {
    double m = (l + r) / 2;
    return (f(l) + 4 * f(m) + f(r)) * (r - l) / 6;
}

double cal(double l, double r, double res, double eps) {
    double m = (l + r) / 2;
    double L = Simpson(l, m), R = Simpson(m, r);
    if (abs(L + R - res) <= 15 * eps)
        return L + R + (L + R - res) / 15;
    else return cal(l, m, L, eps / 2) + cal(m, r, R, eps / 2);
}


double dfs(double L, double R, int magic, double v, double r, double d) {
    if (magic == 0) {
        return L;
    }
    double mid = (L + R) / 2;
    double sn = sin(mid), cs = cos(mid);
    double dt = cal(0, mid, Simpson(0, mid), eps) * r / v;
    double dx = v * dt + 2 * r - 2 * r * cs, y = 2 * r * sn;
    if (((sqrt(sn * sn + 3) - sin(mid)) * cos(mid)) / ((sqrt(sn * sn + 3) - sin(mid)) * sn + 1) > y / (dx - d)) {
        return dfs(mid, R, magic - 1, v, r, d);
    }
    return dfs(L, mid, magic - 1, v, r, d);
}
int magic = 10;
int main() {
    int T;
    for (scanf("%d", &T); T-- > 0; ) {
        double v, r, d;
        scanf("%lf%lf%lf", &v, &r, &d);
        if (d <= (9.24656589157) * r) {
            printf("%.9f\n", d / v);
        }
        else {
            double dx = dfs(acos(0), acos(0) * 2, magic, v, r, d);
            double de = cal(0, dx, Simpson(0, dx), eps) * r / v;
            double dd = v * de + 2 * r - 2 * r * cos(dx), y = 2 * r * sin(dx);
            printf("%.9f\n", de + sqrt(y * y + (d - dd) * (d - dd)) / 2 / v);
        }
    }
    return 0;
}
