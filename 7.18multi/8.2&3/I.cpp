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
#define debug(...) 99
    #define err(x) 99
#endif
namespace io {
    const int LEN=(1<<21)+1; char ibuf[LEN],*iS,*iT,obuf[LEN],*oS=obuf,*oT=obuf+LEN-1,c,st[55];int f,tp;
#define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,LEN,stdin),(iS==iT?EOF:*iS++)):*iS++)
    inline void flush() {fwrite(obuf,1,oS-obuf,stdout);oS=obuf;}
    inline void pc(char x) { *oS++=x; if (oS==oT) flush(); }
    template<class I> inline void sc(I&x) {
        for (f=1,c=gc();c<'0'||c>'9';c=gc()) if (c=='-') f=-1;
        for (x=0;c<='9'&&c>='0';c=gc()) x=x*10+(c&15); x*=f;
    }
    template<class T> inline bool read(T&x){
        for (f=1,c=gc();c<'0'||c>'9';c=gc()){ if(c==-1)return 0;if(c=='-') f=-1; }
        for(x=c-48;;x=x*10+(c&15)){ if(!isdigit(c=gc()))break;}x*=f; return 1;
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
    inline void pstr(const char*s) { for (int i=0;s[i];++i) pc(s[i]); }
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
using io::pstr;
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
const ll mod = 998244353;
ll pow_mod(ll a, ll b) {
    assert(b >= 0);ll res=1;
    for (a %= mod; b; b >>= 1, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}


inline ll add(ll x, ll y)
{
    x += y;
    return x >= mod? x - mod: x;
}

inline ll mul(ll x, ll y)
{
    x *= y;
    return x >= mod? x % mod: x;
}

inline ll sub(ll x, ll y)
{
    x -= y;
    return x < 0? x + mod: x;
}

const int N = 100010;

int x[N], y[N], tx[N], ty[N];

struct point
{
    int x, y;
    point(int x = 0, int y = 0): x(x), y(y){}
    inline bool operator < (const point &o) const {
        return x == o.x? y < o.y: x < o.x;
    }
};

point p[N];

map<int, int> mp;
int xz, yz;

inline int get_x(int v)
{
    return int(lower_bound(x, x + xz, v) - x);
}

inline int get_y(int v)
{
    return int(lower_bound(y, y + yz, v) - y);
}

int n;
struct Bit
{
    ll a[N];
    inline void ins(int pos, int val)
    {
        for (;pos < N;pos += pos & -pos)
        {
            a[pos] += val;
        }
    }
    inline ll q(int pos)
    {
        ll res = 0;
        for (; pos; pos -= pos & -pos)
        {
            res += a[pos];
        }
        return res;
    }
    inline ll q(int l, int r)
    {
        return q(r) - q(l - 1);
    }
}b;
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    sc(n);
    rep(i, 0, n)
    {
        sc(x[i], y[i]);
    }
    memcpy(tx, x, sizeof(tx));
    memcpy(ty, y, sizeof(ty));
    sort(x, x + n);
    sort(y, y + n);
    xz = int(unique(x, x + n) - x);
    yz = int(unique(y, y + n) - y);
    ll ans = 0;
    rep(i, 0, n)
    {
        p[i] = point(1 + get_x(tx[i]), 1 + get_y(ty[i]));
        mp[p[i].y]++;
    }
    for (const auto &it: mp)
    {
        ans = add(ans, mul(it.second, n - it.second));
    }
    debug("%lld\n", ans);
    ans = mul(ans, pow_mod(2, mod - 2));
    ans = add(ans, n);
    sort(p, p + n);
    int la = 0;
    per(i, 0, n)
    {
        ll l = b.q(1, p[i].y - 1), r = (n - i - 1 - b.q(1, p[i].y));
        if (i < n - 1 && p[i].x == p[i + 1].x)++la;
        else
            la = 0;
        ans = add(ans, mul(l, r - la));
        b.ins(p[i].y, 1);
    }
    cout << ans << endl;
    return 0;
}