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
#define int long long
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 998244353;
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
vector<pair<pii,int> > opts;
int fact[N], finv[N];
inline int C(int n, int m) {
    if (n < m) return 0;
    return mul(fact[n], mul(finv[m], finv[n - m]));
}
void init() {
    fact[0]=1;
    rep(i,1,N)fact[i]=mul(fact[i-1],i);
    finv[N-1]=pow_mod(fact[N-1],mod-2);
    per(i,0,N-1){
        finv[i]=mul(finv[i+1],i+1);
#ifdef Wavator
        assert(1ll*fact[i]*finv[i]%mod==1);
#endif
    }
}
 
signed main() {
    init();
    int T;
    scanf("%lld", &T);
    while(T--) {
        int max_d = 0;
        int n, q;
        scanf("%lld%lld", &n, &q);
        opts.clear();
        for(;q--;)
        {
            int op,l,r,x;
            scanf("%lld", &op);
            if(op==1)
            {
                scanf("%lld%lld%lld", &l, &r, &x);
                opts.push_back({{l,max_d-1},x});
                opts.push_back({{r+1,max_d-1},-x});
            }
            else if(op==2)
            {
                max_d++;
            }
            else if(op==3)
            {
                scanf("%lld%lld",&l,&r);
                int ans=0;
                for (auto &v: opts)
                {
                    int L=v.fi.fi,D=max_d-v.fi.se,V=v.se;
                    if(L<=l-1)
                    {
                        ans = sub(ans, mul(V, C(l-L+D-1,l-L-1)));
                        ans=ans%mod+mod;
                        ans%=mod;
                    }
                    if(L<=r)
                    {
                        ans = add(ans, mul(V,C(r-L+D,r-L)));
                        ans=ans%mod+mod;
                        ans%=mod;
                    }
                }
                printf("%lld\n",ans);
            }
        }
    }
}
