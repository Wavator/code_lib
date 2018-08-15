#pragma optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#include "local_debug.h"
#else
#define debug(...)
#endif
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
typedef long long ll;
const int mod = (int)998244353;
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
    return a < mod? a: a - a / mod * mod;
}
inline int pow_mod(int a, ll b) {
    int res = 1;
    for(; b; b>>=1,a=mul(a,a))if(b&1)res=mul(res,a);
    return res;
}
inline int inv(int a) {
    a %= mod;
    if (a < 0) a += mod;
    int b = mod, u = 0, v = 1;
    for(;a ;) {
        int t = b / a;
        b -= t * a;swap(a, b);
        u -= t * v;swap(u, v);
    }
    if (b != 1)
        return -1;
    if (u < 0) u += mod;
    return u;
}
const int N = 200005;
int fact[N], finv[N];
inline int C(int n, int m) {
    if (n < m) return 0;
    return mul(fact[n], mul(finv[m], finv[n - m]));
}

int main() {
    fact[0]=1;
    rep(i,1,N)fact[i]=mul(fact[i-1],i);
    finv[N-1]=pow_mod(fact[N-1],mod-2);
    per(i,0,N-1){
        finv[i]=mul(finv[i+1],i+1);
    }
    int T;
    for (scanf("%d", &T); T--; )
    {
        int k, m, n;
        scanf("%d%d%d", &n, &m, &k);
        int ans = 0;
        for (int i = 0; i <= k / n; ++i)
            ans = (i & 1)? sub(ans, mul(C(k - i * n + m - 1, m - 1), C(m, i))) : add(ans, mul(C(k - i * n + m - 1, m - 1), C(m, i)));
        printf("%d\n",ans);
    }
    return 0;
}