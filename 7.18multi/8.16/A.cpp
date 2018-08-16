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

const ll mod = (ll)1e9 + 7;
ll pow_mod(ll a, ll b)
{
    ll res = 1;
    for (; b; b >>= 1, a = a * a % mod)
    {
        if (b & 1)
        {
            res = res * a % mod;
        }
    }
    return res;
}
void FWT(ll a[],ll n)
{
    for(ll d=1;d<n;d<<=1)
        for(ll m=d<<1,i=0;i<n;i+=m)
            for(ll j=0;j<d;j++)
            {
                ll x=a[i+j],y=a[i+j+d];
                //xor:
                a[i+j]=(x+y)%mod,a[i+j+d]=(x-y+mod)%mod;
                //and:a[i+j]=x+y;
                //or:a[i+j+d]=x+y;
            }
}
ll REV;
void UFWT(ll a[],ll n)
{
    for(ll d=1;d<n;d<<=1)
        for(ll m=d<<1,i=0;i<n;i+=m)
            for(int j=0;j<d;j++)
            {
                ll x=a[i+j],y=a[i+j+d];
                //xor:
                a[i+j]=1LL*(x+y)*REV%mod,a[i+j+d]=(1LL*(x-y)*REV%mod+mod)%mod;
                //and:a[i+j]=x-y;
                //or:a[i+j+d]=y-x;
            }
}
const int N = 1<<21;
ll a[N], b[N];

signed main() {
    REV = pow_mod(2,mod-2);
    ll n;
    scanf("%lld",&n);
    rep(i,0,n)
    {
        scanf("%lld",a+i);
    }
    rep(i,0,n)
    {
        scanf("%lld",b+i);
    }
    FWT(a, n);
    FWT(b, n);
    rep(i, 0, n)
    {
        a[i] = pow_mod(a[i], mod - 2);
    }
    rep(i, 0, n)
    {
        b[i] *= a[i];
        b[i] %= mod;
    }
    UFWT(b, n);
    rep(i, 0, n)
    {
        printf("%lld\n", b[i]);
    }
    return 0;
}