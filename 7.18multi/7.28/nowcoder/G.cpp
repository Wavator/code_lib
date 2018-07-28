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
    #define debug(fmt, ...) fprintf(stderr, "%s: %s = " fmt "\n", \
                __func__, #__VA_ARGS__, __VA_ARGS__), fflush(stderr)
#else
    #define debug(...) 99
#endif
typedef long long ll;
 
const int N=100005;
map<ll, ll> mp;
struct node {
    ll id, sum;
    inline bool operator < (const node &rhs) const {
        return sum>rhs.sum;
    }
}d[N];
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        mp.clear();
        for(int i=1,x;i<=n;++i) {
            scanf("%d",&x);
             mp[x]++;
        }
        ll ans=-1,k=0;
        for(auto it: mp)
            d[++k].id=it.first,d[k].sum=it.second;
        sort(d+1,d+k+1);
        ll pos=1;
        ll tmp=0;
        for(int i=1;i<=k;++i) {
            while(d[pos].sum>=d[i].sum&&pos<=k)
                tmp+=d[pos].sum,pos++;
            ll now=tmp-(d[i].sum-1)*(pos-1)-1;
            if(now<=m)
                ans=max(ans,d[i].id);
        }
        printf("%lld\n",ans);
    }
    return 0;
}