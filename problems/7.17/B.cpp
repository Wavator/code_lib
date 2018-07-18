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
/*
 * head template
 */
const int N = 22;
ll fact[N];
ll dp[1 << N];
ll in[N];
inline void print(ll x, ll y) {
    ll d = __gcd(x, y);
    printf("%lld/%lld\n", x / d, y / d);
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    fact[0] = 1;
    rep(i, 1, 22) fact[i] = fact[i - 1] * i;
    int T;
    for (scanf("%d", &T); T--; ) {
        int p, n, m;
        scanf("%d%d%d", &p, &n, &m);
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        rep(i, 0, m) scanf("%lld", &in[i]);
        ll ans = 0;
        rep(i, 0, 1 << (m + n)) {
            if (dp[i]) {
                int have = __builtin_popcount(i & ((1 << n) - 1));
                int has = __builtin_popcount(i >> n);
                if (have - has + 1 >= 0) {
                    ll res=0;
                    rep(j, 0, m) if(i&(1<<(j+n))) res += in[j];
                    if(res >= p){
                        ans += dp[i] * fact[n + m - have - has];
                    }
                    else if (have - has + 1) {
                        rep(j, 0, n + m) {
                            if (i & (1 << j)) continue;
                            dp[i ^ (1 << j)] += dp[i];
                        }
                    }
                }
            }
        }
        print(ans, fact[n + m]);
    }
    return 0;
}
