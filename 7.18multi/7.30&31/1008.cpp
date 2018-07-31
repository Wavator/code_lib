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
#define debug(...) 99
#define err(x) 99
#endif
namespace io {
    const int LEN=(1<<23)+1; char ibuf[LEN],*iS,*iT,obuf[LEN],*oS=obuf,*oT=obuf+LEN-1,c,st[55];int f,tp;
#define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,LEN,stdin),(iS==iT?EOF:*iS++)):*iS++)
    inline void flush() {fwrite(obuf,1,oS-obuf,stdout);oS=obuf;}
    inline void pc(char x) { *oS++=x; if (oS==oT) flush(); }
    template<class I> inline void sc(I&x) {
        for (c=gc();c<'0'||c>'9';c=gc());
        for(x=c-48;;x=(x<<1)+(x<<3)+(c^48))if(!isdigit(c=gc()))break;
    }
    template<class T> inline bool read(T&x){
        for (c=gc();c<'0'||c>'9';c=gc());
        for(x=c-48;;x=(x<<1)+(x<<3)+(c^48)){ if(!isdigit(c=gc()))break;}x*=f; return 1;
    }
    template<class I> inline void pr(I x) {
        if (!x) pc('0');
        if (x<0) pc('-'),x=-x;
        while (x) st[++tp]=x%10+'0',x/=10;
        while (tp) pc(st[tp--]);
    }
    template <typename T> inline void pl(T x){ pr(x);pc(10); }
    inline void pl(){ pc(10); }
    inline void ps(){ pc(30); }
    template <typename T> inline void ps(T x){ pr(x);pc(30); }
    inline void gs(char*s, int&l) {
        for (c=gc();c<'a'||c>'z';c=gc()); for (l=0;c<='z'&&c>='a';c=gc()) s[l++]=c; s[l]=0;
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
using io::pr;
using io::pl;
using io::ps;
using io::read;
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

struct monster {
    ll a, b;
    monster(){}
    monster(ll a, ll b): a(a), b(b){};
    monster(const monster &x) {a=x.a,b=x.b;};
    inline bool operator < (const monster &o) const {
        if (a<=b&&o.a>o.b) return 1;
        if (a>b&&o.a<o.b) return 0;
        if (a<=b&&o.a<=o.b) return a<o.a;
        if (a>b&&o.a>o.b) return b>o.b;
        return 0;
    }
    inline void operator+=(const monster &o) {
        ll u=max(a,a-b+o.a);
        *this = monster(u, u - a + b - o.a + o.b);
    }
};
typedef pair<monster, int> information;

const int N = 100010;
monster mo[N];
set<information> s;
int fa[N], p[N];

int find(int i){return i == fa[i]? i: fa[i] = find(fa[i]);}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int T;fa[1]=1;
    for (sc(T); T--; ) {
        int n;
        sc(n);
        mo[1]=monster(0,0);
        for (int i = 2, a, b; i <= n; ++i) {
            fa[i]=i;
            sc(a);
            sc(b);
            mo[i] = monster(a, b);
            s.insert(information(mo[i], i));
        }
        for (int i = 1, u, v; i < n; ++i) {
            sc(u);
            sc(v);
            p[v] = u;
        }
        for (int id, f; !s.empty();) {
            id = s.begin()->se;
            f = find(p[id]);
            fa[id] = f;
            s.erase(s.begin());
            if (f > 1) s.erase(information(mo[f], f));
            mo[f] += mo[id];
            if (f > 1) s.insert(information(mo[f], f));
        }
        pl(mo[1].a);
    }
    return 0;
}