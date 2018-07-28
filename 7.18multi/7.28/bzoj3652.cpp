#pragma optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i,a,n) for(int i=(a);i<(n);++i)
#define per(i,a,n) for(int i=(n)-1;i>=(a);--i)
#define all(x) (x).begin(), (x).end()
#ifdef Wavator
#define debug(...) fprintf(stderr, __VA_ARGS__), fprintf(stderr, "\n"), fflush(stderr)
#else
#define debug(...) 99
#endif
typedef long long ll;
typedef double db;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int mod = (int)1e9+7;
ll pow_mod(ll a,ll b=mod-2){
    assert(b>=0);ll res=1;for(a%=mod;b;b>>=1,a=a*a%mod)if(b&1)res=res*a%mod;
    return res;
}
namespace io {
    const int L=(1<<21)+1;
    char ibuf[L],*iS,*iT,obuf[L],*oS=obuf,*oT=obuf+L-1,c,st[55];int f,tp;
#define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,L,stdin),(iS==iT?EOF:*iS++)):*iS++)
    inline void flush() {
        fwrite(obuf,1,oS-obuf,stdout);
        oS=obuf;
    }
    inline void pc(char x) { *oS++=x; if (oS==oT) flush(); }
    template<class I> inline void sc(I&x) {
        for (f=1,c=gc();c<'0'||c>'9';c=gc()) if (c=='-') f=-1;
        for (x=0;c<='9'&&c>='0';c=gc()) x=x*10+(c&15); x*=f;
    }
    template<class T> inline bool read(T&x){
        for (f=1,c=gc();c<'0'||c>'9';c=gc()){ if(c==-1)return 0;if(c=='-') f=-1; }
        for(x=c-48;;x=x*10+(c&15)){ if(!isdigit(c=gc()))break;}x*=f; return 1;
    }
    template<class I> inline void p(I x) {
        if (!x) pc('0');
        if (x<0) pc('-'),x=-x;
        while (x) st[++tp]=x%10+'0',x/=10;
        while (tp) pc(st[tp--]);
    }
    template <typename T> inline void pl(T x){
        p(x);pc('\n');
    }
    template <typename T> inline void pl(){
        pc(10);
    }
    template <typename T> inline void ps(){
        pc(30);
    }
    inline void gs(char*s, int&l) {
        for (c=gc();c<'a'||c>'z';c=gc());
        for (l=0;c<='z'&&c>='a';c=gc()) s[l++]=c;
        s[l]=0;
    }
    template <typename A, typename B> inline void sc(A&x,B&y){sc(x),sc(y);};
    template <typename A, typename B> inline bool read(A&x,B&y){return read(x)&&read(y);};
    inline void ps(const char*s) { for (int i=0;s[i];++i) pc(s[i]); }
    struct IOFLUSHER{ ~IOFLUSHER() { flush(); } } _ioflusher_;
}
using io::pc;
using io::sc;
using io::gs;
using io::ps;
using io::p;
using io::pl;
using io::ps;
using io::read;
struct gay {
    ll x,tg;
    int y;
    gay(ll x=0,int y=0,ll tg=0):x(x),y(y),tg(tg){}
    inline bool operator < (const gay&o) const {
        return x < o.x;
    }
    inline void operator()(const gay&l, const gay &r) {
        *this = l < r? gay(r.x,r.y,tg): gay(l.x,l.y,tg);
    }
    inline void operator -= (ll o){
        x-=o;
        tg+=o;
    }
};
const int N = 200010;
int fa[N];
unsigned int val[N];
vector<int> e[N];
ll v[N];
int pos[N],clk,fin[N],mp[N];
void dfs(int u){
    mp[pos[u]=++clk]=u;
    v[u]=v[fa[u]]+val[u];
    for(int i=0,j=e[u].size();i<j;++i)dfs(e[u][i]);
    fin[u]=clk;
}
gay s[N<<2];
void build(int l,int r,int rt){
    if(l==r){
        s[rt]=gay(v[mp[l]], l);
        return;
    }
    int mid=l+r>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    s[rt](s[rt<<1],s[rt<<1|1]);
}
inline void push_down(int rt){
    if(s[rt].tg){
        s[rt<<1]-=s[rt].tg;
        s[rt<<1|1]-=s[rt].tg;
        s[rt].tg=0;
    }
}
void change(const int &L, const int &R, const ll &v, int l, int r, int x) {
    if(l>=L&&r<=R){
        s[x]-=v;
        return;
    }
    int mid=l+r>>1;
    push_down(x);
    if(L<=mid)change(L,R,v,l,mid,x<<1);
    if(R>mid)change(L,R,v,mid+1,r,x<<1|1);
    s[x](s[x<<1],s[x<<1|1]);
}
bool u[N];
int main() {
#ifdef Wavator
    freopen("test.in","r",stdin);
#endif
    int n, k;
    sc(n,k);
    for(int i=1;i<=n;++i)sc(val[i]);
    int x,y;
    rep(i,1,n){
        sc(x,y);
        e[x].push_back(y);
        fa[y]=x;
    }
    dfs(1);
    build(1,n,1);
    ll ans=0;
    for(;k--;){
        ans+=s[1].x;
        x=mp[s[1].y];
        while(!u[x]&&x!=0) {
            change(pos[x],fin[x],val[x],1,n,1);
            u[x]=1;
            x=fa[x];
        }
    }
    pl(ans);
    return 0;
}