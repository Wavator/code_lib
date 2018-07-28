#pragma optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i,a,n) for(int i=(a);i<(n);++i)
#define per(i,a,n) for(int i=(n)-1;i>=(a);--i)
#define all(x) (x).begin(), (x).end()
#ifdef Wavator
#define dbg(...) fprintf(stderr, __VA_ARGS__), fprintf(stderr, "\n"), fflush(stderr)
#else
#define dbg(...) 99
#endif
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
const ll mod = (ll)1e9+7;
ll pow_mod(ll a,ll b=mod-2){
    assert(b>=0);ll res=1;for(a%=mod;b;b>>=1,a=a*a%mod)if(b&1)res=res*a%mod;
    return res;
}
ll p[20];
inline bool ck(int i) {
    rep(j,2,i)if(i%j==0)return 0;
    return 1;
}
int pt,x;
ll ans, n;
void dfs(int id, ll mi, int y) {
    if(!y){
        static ll t;
        t=(ll)pow(n,1./mi);
        while(pow(t,mi)>n)t--;
        while(pow(t+1,mi)<=n)t++;
        ans+=t*x;
        return;
    }
    if(id>=pt)return;
    if(mi*p[id]<=60)dfs(id+1,mi*p[id],y-1);
    dfs(id+1,mi,y);
}
int main() {
#ifdef Wavator
    freopen("test.in","r",stdin);
#endif
    for (int i = 2; i <= 60; ++i) {
        if(ck(i))p[pt++]=i;
    }
    while (~scanf("%lld", &n)) {
        ans=0;
        x=1;int y=1;
        rep(i,0,3){
            dfs(0,1,y);
            x*=-1;
            y++;
        }
        printf("%lld\n",ans-1);
    }
    return 0;
}