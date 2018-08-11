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
ll pow_mod(ll a, ll b) {
    assert(b >= 0);ll res=1;
    for (a %= mod; b; b >>= 1, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}
void ext_gcd(ll a, ll b, ll &d, ll &x, ll &y) {
    if (b) {
        ext_gcd(b, a % b, d, y, x);
        y -= x * (a / b);
    } else {
        d = a, x = 1, y = 0;
    }
}
ll get_inv(ll a, ll mod = ::mod) {
    ll d, x, y;
    ext_gcd(a, mod, d, x, y);
    return d == 1? (x < 0? x + mod: x): -1;
}

int main() {
    ll n,ans;
    scanf("%lld",&n);
    ans = n*(n-1)%mod*(n-2)%mod*(n-3)%mod*get_inv(24)%mod+(n-1)*(n-2)%mod*get_inv(2)%mod;
    printf("%lld\n",ans%mod);
    return 0;
}