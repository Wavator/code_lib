#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#define debug(...) fprintf(stderr, __VA_ARGS__);
#else
#define debug(...) 42;
#define cerr if (false) cout
#endif
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b - 1); i >= a; --i)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
typedef long long ll;
typedef double db;
typedef vector<int> vi;

const ll mod = (ll)1e9 + 7;
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
namespace poly_sum { //rep/per is 0 based
    const int D = 3010;
    ll f[D], g[D], p1[D], p2[D];
    ll calcn(int d, ll* a, ll n) { // d is the term number you have, n is the number of terms you want to calculate. return the ploy's sum.
        if (n <= d)
            return a[n];
        p1[0] = p2[0] = 1;
        rep(i, 0, d + 1) {
            ll t = (n - i + mod) % mod;
            p1[i + 1] = p1[i] * t % mod;
        }
        rep(i, 0, d + 1) {
            ll t = (n - d + i + mod) % mod;
            p2[i + 1] = p2[i] * t % mod;
        }
        ll ans = 0;
        rep(i, 0, d + 1) {
            ll t = g[i] * g[d-i] % mod * p1[i] % mod * p2[d - i] % mod * a[i] % mod;
            if ((d - i) & 1) ans = (ans - t + mod) % mod;
            else ans = (ans + t) % mod;
        }
        return ans;
    }
    void init(int M) {
        f[0] = f[1] = g[0] = g[1]=1;
        rep(i, 2, M + 5) f[i] = f[i - 1] * i % mod;
        g[M + 4] = pow_mod(f[M + 4], mod - 2);
        per(i, 1, M + 4) g[i] = g[i + 1] * (i + 1) % mod;
    }
}
const int N = 3002;

ll dp[N][N]; // i root, exp j -> coe

vi e[N];

ll poly[N];

// poly is a pre_sum, if the leaf has poly of degree d, the sum's degree is d + 1;

int n, d;
void dfs(int u) {
    rep(i, 1, n + 1)
        dp[u][i] = 1;
    for (int &v: e[u]) {
        dfs(v);
        rep(i, 0, n + 1) {
            poly[i] = dp[v][i];
        }
        rep(i, 0, n) {
            poly[i + 1] += poly[i];
            if (poly[i + 1] >= mod)
                poly[i + 1] -= mod;
        }
        rep(i, 0, n + 1) {
            (dp[u][i] *= poly[i]) %= mod;
        }
    }
}

int main() {
    scanf("%d%d",&n, &d);
    poly_sum::init(n);
    rep(i, 2, n + 1) {
        int s;
        scanf("%d", &s);
        e[s].pb(i);
    }
    dfs(1);
    rep(i, 0, n + 1) poly[i] = dp[1][i];
    rep(i, 0, n) {
        poly[i + 1] += poly[i];
        if (poly[i + 1] >= mod)
            poly[i + 1] -= mod;
    }
    printf("%lld\n", poly_sum::calcn(n, poly, d));
    return 0;
}