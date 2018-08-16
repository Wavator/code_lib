#pragma optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#include "local_debug.h"
#else
#define debug(...)
#endif
#define int long long
#define pb push_back
#define rep(i,a,n) for(int i=(a);i<(n);++i)
#define per(i,a,n) for(int i=(n)-1;i>=(a);--i)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int mod = (int)1e9 + 7;
inline int add(int a, int b) {
    a += b;
    return a < mod? a: a - mod;
}
inline int sub(int a, int b) {
    a -= b;
    return a < 0? a + mod: a;
}
inline int mul(ll a, int b) {
    a *= b;
    return (int)(a < mod? a: a - a / mod * mod);
}
inline int pow_mod(int a, ll b) {
    int res = 1;
    for(; b; b>>=1,a=mul(a,a))if(b&1)res=mul(res,a);
    return res;
}
inline int cal_inv(int a) {
    a %= mod;
    if (a < 0) a += mod;
    int b = mod, u = 0, v = 1;
    for(;a ;) {
        int t = b / a;
        b -= t * a;swap(a, b);
        u -= t * v;swap(u, v);
    }
    if (b != 1) return -1;
    return u < 0? u + mod: u;
}
int inv100;

int n, m, p[1005];
ll dp[1005][1005];
signed main() {
    inv100 = pow_mod(100,mod-2);
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", p + i);
        p[i] = p[i]*inv100%mod;
    }
    dp[0][0] = 1;
    ll ans = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= i;j++){
            dp[i][j] = dp[i-1][j-1]*p[i]%mod;
            dp[i][0] += dp[i-1][j]*(1-p[i])%mod;
            dp[i][j] = (dp[i][j]%mod+mod)%mod;
            ans += dp[i-1][j]*(1-p[i])%mod*pow_mod(j,m)%mod;
        }
        dp[i][0] += dp[i-1][0]*(1-p[i])%mod;
        dp[i][0] = (dp[i][0]%mod+mod)%mod;
    }
    for(int i = 1;i <= n;i++)
    {
        ans += dp[n][i]*pow_mod(i,m)%mod;
        //ans %= mod;
    }
    ans=(ans%mod+mod)%mod;
    cout<<ans<<endl;
    return 0;
}
