#pragma optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i,a,n) for(int i=(a);i<(n);++i)
#define per(i,a,n) for(int i=(n)-1;i>=(a);--i)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
#ifdef Wavator
#define debug(fmt, ...) fprintf(stderr, "func[%s] line %d: %s = " fmt "\n", \
                __func__, __LINE__, #__VA_ARGS__, __VA_ARGS__), fflush(stderr)
#define err(x) cerr << "func[" << __func__ << "] line " << __LINE__ << ": " \
                    << #x << " = " << x << endl << flush
#else
#define debug(...) 99
    #define err(x) 99
#endif
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
const ll mod = (ll)1e9 + 7;
static ll pow_mod(ll a, ll b) {
    assert(b >= 0);ll res=1;
    for (a %= mod; b; b >>= 1, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}
const int N = 100005;
ll fact[N], finv[N];
static const ll two = pow_mod(2, mod - 2);
struct query {
    int l, r, id;
};
query q[N];
int pos[N];
const int blk = (int)sqrt(N);

inline ll sub(ll x, ll y) {
    x -= y;
    if (x < 0) x += mod;
    return x;
}

inline ll add(ll x, ll y) {
    x += y;
    if (x >= mod) x -= mod;
    return x;
}

inline ll mul(ll x, ll y) {
    x *= y;
    if (x >= mod) x %= mod;
    return x;
}

inline ll c(ll n, ll m) {
    return (fact[n] * finv[m] % mod) * finv[n - m] % mod;
}
ll ans[N];
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    fact[0] = 1;
    for (ll i = 1; i < N; ++i) fact[i] = fact[i - 1] * i % mod;
    finv[N - 1] = pow_mod(fact[N - 1], mod - 2);
    for (ll i = N - 2; ~i; --i) {
        finv[i] = finv[i + 1] * (i + 1) % mod;
        //assert(finv[i] * fact[i] % mod == 1);
    }
    for (int i = 1; i < N; ++i) {
        pos[i] = (i-1) / blk + 1;
    }
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &q[i].l, &q[i].r);
        q[i].id = i;
    }
    sort(q+1,q+m+1,[&](const query &a, const query&b){
        return pos[a.l]==pos[b.l]?a.r<b.r:pos[a.l]<pos[b.l];
    });
    ll t = 1;
    for (int i = 1, l = 0, r = 0; i <= m ; ++i) {
        while (r > q[i].r) {
            t = sub(t, c(l, r--));
        }
        while (l < q[i].l) {
            t = sub(mul(t, 2), c(l++, r));
        }
        while (r < q[i].r) {
            t = add(t, c(l, ++r));
        }
        while (l > q[i].l) {
            t = mul(add(t, c(--l, r)), two);
        }
        ans[q[i].id] = t;
    }
    for (int i = 1; i <= m; ++i) printf("%lld\n", ans[i]);
    return 0;
}