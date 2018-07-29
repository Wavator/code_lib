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
    #define debug(...) 0
    #define err(x) 0
#endif
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
const ll mod = (ll)1e9 + 7;
ll pow_mod(ll a, ll b) {
    assert(b >= 0);ll res=1;
    for (a %= mod; b; b >>= 1, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}
const int N = 2 * 100005;
struct finwick {
    int a[N];
    int n;
    inline void reset(int n){
        this->n=n;
        for(int i=1;i<=n;++i)a[i]=0;
    }
    inline void add(int pos, int val) {
        for(;pos<=n;pos+=pos&-pos)a[pos]+=val;
    }
    inline bool query(int l, int r) {
        if(l>r)return true;
        int res=0;
        for(int i=r;i;i-=i&-i)res+=a[i];
        for(int i=l-1;i;i-=i&-i)res-=a[i];
        return r-l+1==res;
    }
};
struct edge {
    int y;
    edge * next;
}e[N*80], * top = e, *li[N*4];
int in_deg[N*4];
inline void add_edge(int u, int v){
    in_deg[v]++;
    li[u] = &(*top++ = (edge){v, li[u]});
}
int a[N];
priority_queue<pii,vector<pii>,greater<pii> > q;
template <size_t N>
struct seg {
    int f[N], tot;
    int id[N], v[N];
    void build(int l, int r, int x) {
        f[x]=++tot;
        if(l==r) {
            id[l]=tot;
            v[tot]=a[l];
            return;
        }
        v[tot]=-1;
        int mid=l+r>>1;
        build(l,mid,x<<1);
        build(mid+1,r,x<<1|1);
        add_edge(f[x<<1],f[x]);
        add_edge(f[x<<1|1],f[x]);
    }
    void add(const int &L, const int &R, const int &who, int l, int r, int rt) {
        if (l >= L && r <= R) {
            add_edge(f[rt], id[who]);
            return;
        }
        int mid = l + r >> 1;
        if (L <= mid) add(L, R, who, l, mid, rt << 1);
        if (R > mid) add(L, R, who, mid + 1, r, rt << 1 | 1);
    }
 
    void gao() {
        for (int i = 1; i <= tot; ++i)
            if(!in_deg[i])q.emplace(v[i],i);
    }
 
    int get(int x){return v[x];}
 
    void clr_g() {
        memset(li,0,sizeof(li[0])*(tot+1));
        memset(in_deg,0,sizeof(int)*(tot+1));
        top=e;
        for(int i=0;i<=tot;++i)f[i]=id[i]=v[i]=0;
        tot=0;
    }
 
};
 
seg<N*4> s;
 
int n;
finwick bit;
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int T;
    for (scanf("%d", &T); T--; ) {
        scanf("%d",&n);
        bit.reset(n);
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            if (~a[i]) {
                ++cnt;
                bit.add(i, 1);
            }
        }
        if (!cnt) {
            puts("");
        } else {
            bool f = 1;
            s.build(1,n,1);
            for (int i = 1; i <= n && f; ++i) {
                if (~a[i]) {
                    int p = a[i] % n + 1;
                    if(p < i){
                        f &= bit.query(p,i - 1);
                        s.add(p, i - 1, i, 1, n, 1);
                    } else if (p > i) {
                        f &= bit.query(p, n);
                        s.add(p, n, i, 1, n, 1);
                        if (i > 1) {
                            f &= bit.query(1, i - 1);
                            s.add(1, i - 1, i, 1, n, 1);
                        }
                    }
                }
            }
 
            if (!f) {
                puts("-1");
            }
            else {
                static int ans[N];
                int x = 0;
                while(!q.empty())q.pop();
                for (s.gao(); !q.empty();) {
                    int u = q.top().se, y = q.top().fi; q.pop();
                    for (edge * t = li[u]; t; t = t->next) {
                        int v=t->y;
                        in_deg[v]--;
                        if(!in_deg[v])q.emplace(s.get(v), v);
                    }
                    if (~y)ans[x++]=y;
                }
                if(x!=cnt)puts("-1");
                else{
                    rep(i,0,x-1)printf("%d ",ans[i]);
                    printf("%d\n",ans[x-1]);
                }
            }
            s.clr_g();
        }
    }
    return 0;
}
