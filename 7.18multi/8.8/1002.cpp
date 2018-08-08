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
const ll mod = (ll)1e9+7;
ll pow_mod(ll a, ll b, ll mod = ::mod) {
    assert(b >= 0);ll res=1;
    for (a %= mod; b; b >>= 1, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}
const int N = 2e6 + 100;
int fact[N], finv[N];

inline ll add(ll x, ll y)
{
    x += y;
    return x >= mod? x - mod: x;
}

inline ll mul(ll x, ll y)
{
    x *= y;
    return x >= mod? x % mod: x;
}

inline ll sub(ll x, ll y)
{
    x -= y;
    x %= mod;
    return x < 0? x + mod: x;
}

inline ll inv(ll x)
{
    return pow_mod(x, mod - 2);
}


inline ll C(ll n, ll m)
{
    //cerr << n << ' ' << m << endl;
    //swap(n, m);
    return mul(fact[n], mul(finv[m], finv[n - m]));
}

int beau[N];
//const int block = 100000;
//ll power_head[block + 10], init_power[block + 10];
//inline ll power2(ll x) {
//    x %= (mod - 1);
//    return mul(power_head[x / block] , init_power[x % block]);
//}
void pre_work()
{

    fact[0]=fact[1]=1;
    rep(i,1,N)fact[i]=mul(i,fact[i-1]);
    //for(int i=2;i<N;++i)fib[i]=add(fib[i-2], fib[i-1]);
    //rep(i,0,100)cerr<<fib[i]<<' ';cerr<<endl;
    finv[N-1]=inv(fact[N-1]);
    for(int i=N-2;~i;--i)
    {
        finv[i]=mul(finv[i+1],i+1);
        //assert(finv[i]*fact[i]%mod==1);
    }
//    init_power[0] = 1;
//    for (int i = 1; i <= block; ++i)
//        init_power[i] = init_power[i - 1] * 2 % mod;
//    power_head[0] = 1;
//    for (int i = 1; i <= block; ++i)
//        power_head[i] = power_head[i - 1] * init_power[block] % mod;
    beau[0]=1,beau[1]=2;
    for (int i = 2; i < N; ++i)
    {
        beau[i]=mul(beau[i-1],beau[i-2]);
    }
    rep(i,0,N){
        beau[i]--;
    }

    //rep(i,0,10)cerr<<beau[i]<<' ';cerr<<endl;
}

int dp[N];
int factor[N];

int main()
{
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    pre_work();
    int T;
    for (scanf("%d", &T); T--;) {
        int n, k;
        scanf("%d%d", &n, &k);
        fill(dp + 1, dp + n + 1,0);
        int cnt = 0;
        for(ll i = 1;i * i <= n; ++i){
            if(n%i == 0){
                factor[cnt++]=i;
                if(i * i != n)
                    factor[cnt++]=n/i;
            }
        }
        sort(factor,factor+cnt);
        //rep(i,0,cnt)cerr<<factor[i]<<' ';cerr<<endl;
        ll ans=0;
        for (int i = cnt-1; ~i; --i)
        {
            ll x = factor[i];
            dp[x] = C(n / x + k - 1, k - 1);
            for (int j = i + 1; j < cnt; ++j)
            {
                ll y = factor[j];
                if (y % x != 0)
                    continue;
                //cerr << x << ' ' << y << endl;
                dp[x] = sub(dp[x], dp[y]);
            }
            ans = add(ans, mul(beau[x], dp[x]));
        }
        ans = mul(ans, inv(C(n + k - 1, k - 1)));
        printf("%lld\n", ans);
    }
    return 0;
}