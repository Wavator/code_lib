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
typedef double db;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
const ll mod = (ll)1e9+7;
ll pow_mod(ll a,ll b=mod-2){
    assert(b>=0);ll res=1;for(a%=mod;b;b>>=1,a=a*a%mod)if(b&1)res=res*a%mod;
    return res;
}

struct query{int l, r, idx;};
int n, m, Q;
const int N = 200005;
int a[N];
int ans[N];
struct gay {
    int a[21];
    gay() {
        memset(a,0,sizeof(a));
    }
    gay(int x){
        *this = gay(); ++a[x]; ++a[0];
    }
    inline int&operator[] (const int &x) {
        return a[x%m];
    }
    inline gay operator + (const int &x) const {
        gay res = *this;
        for(int i=0;i<m;++i){
            (res[i+x]+=a[i]) %= mod;
        }
        return res;
    }
};
gay pre[N], suf[N];
query q[N];
void solve(int l, int r, vector<int> &o) {
    if(!o.size()||l<1||r>n||l>r)
        return;
    int mid=l+r>>1;
    debug("%d %d %d", l, r, mid);
    pre[mid]=gay(a[mid]);
    suf[mid+1]=gay(a[mid+1]);
    for(int i=mid-1;i>=l;--i)pre[i]=pre[i+1]+a[i];
    for(int i=mid+2;i<=r;++i)suf[i]=suf[i-1]+a[i];
    vector<int> ql, qr;
    for(const int&xx: o) {
        int le=q[xx].l,ri=q[xx].r;
        if (le > mid || ri < mid) {
            if(le > mid)
                qr.push_back(xx);
            else
                ql.push_back(xx);
            continue;
        }
        static gay x, y;
        x = pre[le];
        if(ri^mid) y=suf[ri];
        else y=gay(),y[0]=1;
        for(int i=0;i<m;++i){
            (ans[q[xx].idx]+=((1ll*x[i]*y[m-i])%mod))%=mod;
        }
    }
    o.clear();
    solve(l,mid-1,ql);
    solve(mid+1,r,qr);
}

int main() {
#ifdef Wavator
    freopen("test.in","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i)scanf("%d",&a[i]), a[i]%=m;
    scanf("%d",&Q);
    vector<int> vq(Q);
    rep(i,0,Q){
        scanf("%d%d",&q[i].l, &q[i].r);
        q[i].idx=i;
        vq[i]=i;
    }
    solve(1,n,vq);
    rep(i, 0, Q) {
        printf("%d\n",ans[i]);
    }
    return 0;
}