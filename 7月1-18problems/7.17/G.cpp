/*
 *      Author name: Wavator
 *      Mail: 11612908@mail.sustc.edu.cn
 * */
#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#define debug(...) fprintf(stderr, __VA_ARGS__), fprintf(stderr, "\n")
#else
#define debug(...) 42
#endif
#define rep(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define per(i, a, b) for (int (i) = (b) - 1; (i) >= (a); --(i))
#define REP(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
#define PER(i, a, b) for (int (i) = (b); i >= (a); --i)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vp;
const ll mod = (ll)1e9 + 7;
const db eps = 1e-9;
ll pow_mod(ll a, ll b = mod - 2) {
    ll res = 1;
    for (a %= mod; b; b >>= 1, a = a * a % mod) if (b & 1) res = res * a % mod;
    return res;
}
/*
 * head template
 */
const int N = 40005;

vi e[N];

int sz[N];

///// dp[i] = fact(size(i) - 1) * omega(dp[j]) / omega(fact(size(j)))

ll fact[N], finv[N];

ll dfs(int u) {
    sz[u] = 1;
    ll d = 1, f = 1;
    for (const int &v: e[u]) {
        d = d * dfs(v) % mod;
        f = f * finv[sz[v]] % mod;
        sz[u] += sz[v];
    }
    return (((fact[sz[u] - 1] * d) % mod) * f) % mod;
}
bool vis[N];
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    fact[0] = 1;
    rep(i, 1, N) fact[i] = fact[i - 1] * i % mod;
    finv[N - 1] = pow_mod(fact[N - 1]);
    for (ll i = N - 2; ~i; --i) {
        finv[i] = finv[i + 1] * (i + 1) % mod;
    }
    int T;
    for (scanf("%d", &T); T--; ) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i <= n; ++i) e[i].clear();
        fill(vis + 1, vis + n + 1, false);
        for (int u, v; m--;) {
            scanf("%d%d", &u, &v);
            e[v].push_back(u);
            vis[u] = true;
        }
        for (int i = 1; i <= n; ++i) if (!vis[i]) e[0].push_back(i);
        printf("%lld\n", dfs(0));
    }
    return 0;
}