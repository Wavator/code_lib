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
const ll mod = 998244353;
ll pow_mod(ll a, ll b, ll mod = ::mod) {
    assert(b >= 0); ll res = 1;
    for (a %= mod; b; b >>= 1, a = a * a % mod) if (b & 1) res = res * a % mod;
    return res;
}
 
 
ll sum[100005], a[100005];
int main() {
    int T;cin>>T;
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        long long tmp=pow_mod(2,((long long)n*m)%(mod-1));
        sum[0]=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            sum[i]=(sum[i-1]+a[i])%mod;
        }
        while (m--)
        {
            int op,x,y;
            scanf("%d%d%d",&op,&x,&y);
            if (op==2)
            {
                long long ans=(sum[y]-sum[x-1]+mod)%mod;
                ans=(ans*tmp)%mod;
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}
