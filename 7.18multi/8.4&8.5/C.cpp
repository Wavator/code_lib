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
const ll mod = 998244353;
ll pow_mod(ll a, ll b) {
    assert(b >= 0);ll res=1;
    for (a %= mod; b; b >>= 1, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}

inline ll add(ll a, ll b)
{
    a += b;
    return a >= mod? a - mod: a;
}

inline ll mul(ll a, ll b)
{
    a *= b;
    return a >= mod? a % mod: a;
}

const int N = 1000005;
ll inv[N];
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    inv[0]=inv[1]=1;
    for(ll i=2;i<N;++i)
        inv[i]=(mod-(mod/i)*(inv[mod%i])%mod)%mod;
    int T;
    scanf("%d", &T);
    rep(t, 0, T)
    {
        ll n, m;
        scanf("%lld%lld", &n, &m);
        ll c = 1, f = 1, ans = 1;
        int r = (int)min(n, m);
        n %= mod; m %= mod;
        rep(i, 1, r)
        {
            f = mul(f, m - i);
            c = mul(mul(inv[i], n - i), c);
            ans = add(ans, mul(f, c));
        }
        ans = mul(ans, m);
        printf("Case #%d: %lld\n", t + 1, ans);
    }
    return 0;
}