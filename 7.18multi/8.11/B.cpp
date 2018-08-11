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
const int N = 266666;
ll fact[N], finv[N],inv[N];
void init() {
    inv[0]=inv[1]=1;
    for(ll i=2;i<N;++i){
        inv[i]=(mod-(mod/i)*(inv[mod%i])%mod)%mod;
#ifdef Wavator
        assert(inv[i]*i%mod==1);
#endif
    }
    fact[0]=1;
    rep(i,1,N)fact[i]=fact[i-1]*i%mod;
    finv[N-1]=pow_mod(fact[N-1],mod-2);
    per(i,0,N-1){
        finv[i]=finv[i+1]*(i+1)%mod;
#ifdef Wavator
        assert(fact[i]*finv[i]%mod==1);
#endif
    }
}
inline ll C(int n, int m) {
    return (fact[n] * finv[m] % mod) * finv[n - m] % mod;
}

ll dp[N];

inline ll add(ll a, ll b) {
    a += b;
    return a >= mod? a - mod: a;
}

ll mul(ll a, ll b) {
    a *= b;
    return a >= mod? a % mod: a;
}

ll sub(ll a, ll b) {
    a -= b;
    return a < 0? a + mod: a;
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    init();
    dp[0]=dp[1]=1;
    dp[2]=3;
    rep(i,3,N){
        dp[i]=mul(sub(mul(6*i-3,dp[i-1]), mul(i-2,dp[i-2])),inv[i+1]);
    }
    int n;
    while (cin >> n) cout << (n==1?1:mul(dp[n-1],2)) << endl;
    return 0;
}