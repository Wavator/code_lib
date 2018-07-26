#pragma optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
template <typename T> using V = vector<T>;
template <typename T> using pqmax = priority_queue<T>;
template <typename T> using pqmin = priority_queue<T, V<T>, greater<T> >;
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define SZ(x) ((int)(x).size())
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
const ll mod = (ll)1e9+7;
ll pow_mod(ll a, ll b = mod - 2) {
    assert(b >= 0); ll res = 1; for (a %= mod; b; b >>= 1, a = a * a % mod) if (b & 1) res = res * a % mod;
    return res;
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    vector <pair<double, double> > tri(3);
    rep(i, 0, 3) cin >> tri[i].first >> tri[i].second;
    int n;
    cin >> n;
    db ans = 3.;
    db tans = 0.3333333333333;
    for (int i = 4; i <= n; ++i) {
        (ans += 1.) -= tans;
        tans = (db)(i - 2) / i;
    }
    printf("%.12f\n", ans);
    return 0;
}