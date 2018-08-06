#include <bits/stdc++.h>
#pragma optimize("-O3")
using namespace std;
namespace Quick_in {
    const int LEN=(1<<21)+1; char ibuf[LEN],*iH,*iT;int f,c;
#define gc() (iH==iT?(iT=(iH=ibuf)+fread(ibuf,1,LEN,stdin),(iH==iT?EOF:*iH++)):*iH++)
    inline char nc(){
        while((c=gc())<=32)if(c==-1)return -1;
        return (char)c;
    }
    template<class T> inline void sc(T&x) {
        for (f=1,c=gc();c<'0'||c>'9';c=gc()) if (c=='-') f=-1;
        for (x=0;c<='9'&&c>='0';c=gc()) x=x*10+(c&15); x*=f;
    }
    template<class T> inline bool read(T&x) {
        for (f=1,c=gc();c<'0'||c>'9';c=gc()){ if(c==-1)return 0;if(c=='-') f=-1; }
        for(x=c-48;;x=x*10+(c&15)){ if(!isdigit(c=gc()))break;}x*=f; return 1;
    }
    inline int gline(char*s) {
        int l=-1;
        for (c=gc();c<=32;c=gc())if(c==-1)return c;
        for (;c>32||c==' ';c=gc()){
            s[++l]=c;
        }
        s[l+1]=0;
        return l;
    }
    inline int gs(char *s) {
        int l=-1;
        for (c=gc();c<=32;c=gc())if(c==-1)return c;
        for (;c>32;c=gc()){
            s[++l]=c;
        }
        s[l+1]=0;
        return l;
    }
    template <typename A, typename B> inline void sc(A&x,B&y){sc(x),sc(y);};
    template <typename A, typename B> inline bool read(A&x,B&y){return read(x)&&read(y);};
}
namespace Quick_out {
    static const int BUFFER_MAX_SIZE = 1<<18;
    char buf[BUFFER_MAX_SIZE], *ph = buf, *pt = buf + BUFFER_MAX_SIZE;
    char tmp[100];
    const double dx[15] = {5e-1,5e-2,5e-3,5e-4,5e-5,5e-6,5e-7,5e-8,5e-9,5e-10,5e-11,5e-12,5e-13,5e-14,5e-15};
    inline void my_flush() {
        fwrite(buf, sizeof(char), ph - buf, stdout);
        ph = buf;
    }
    inline void pc(char c) {
        *(ph++) = c;
        if (ph == pt) my_flush();
    }
    inline void ps(const char *s) {
        for (int i = 0; s[i]; ++i) pc(s[i]);
    }
    inline void ps(const string&s) {
        ps(s.c_str());
    }
    template<class T>
    inline void pi(T x, char ec = '\n') {
        if (x < 0) pc('-'), x = -x;
        int len = 0;
        if (!x) tmp[len++] = '0';
        for(;x;) tmp[len++] = x % 10 + '0', x /= 10;
        for(;len;)  pc(tmp[--len]);
        pc(ec);
    }
    inline void pd(double x, int fix = 8, char bc = '\n') {
        x += dx[fix];
        if (x < 0) pc('-'), x = -x;
        pi((long long)x, '.');
        x -= (long long)x;
        for(;fix--;) {
            x *= 10;
            pc('0' + (int)x);
            x -= (int)x;
        }
        pc(bc);
    }
    struct Quick_{~Quick_(){my_flush();}}ooo;
}
using Quick_in::sc;
using Quick_in::read;
using Quick_in::gline;
using Quick_in::gs;
using Quick_in::nc;
using Quick_out::pi;
using Quick_out::pc;
using Quick_out::ps;
using Quick_out::pd;
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
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
const ll mod = (ll)1e9 + 7;
const db eps = 1e-7;
ll pow_mod(ll a, ll b) {
    assert(b >= 0);ll res=1;
    for (a %= mod; b; b >>= 1, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}

struct Gen
{
    unsigned x, y, z, w;
    inline void input()
    {
        scanf("%u%u%u", &x, &y, &z);
    }
    inline unsigned operator()()
    {
        x = x ^ (x << 11);
        x = x ^ (x >> 4);
        x = x ^ (x << 5);
        x = x ^ (x >> 14);
        w = x ^ (y ^ z);
        x = y;
        y = z;
        z = w;
        return z;
    }
};

Gen gen;

const int md = 1 << 30;

const int N = 100005;
ll mi[N << 2];
int L, R, v;
void change(int l, int r, int rt)
{
    if (mi[rt] >= v)
        return;
    if (l == r) {
        mi[rt] = v;
        return;
    }
    int mid = l + r >> 1;
    if (L <= mid)
        change(l, mid, rt << 1);
    if (R > mid)
        change(mid + 1, r, rt << 1 | 1);
    mi[rt] = min(mi[rt << 1], mi[rt << 1 | 1]);
}
int pos;
int query(int l, int r, int rt)
{
    if (l == r)
        return mi[rt];
    int mid = l + r >> 1;
    if (pos <= mid)
        return query(l, mid, rt << 1);
    else
        return query(mid + 1, r, rt << 1 | 1);
}

int main()
{
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int T;
    for (scanf("%d", &T); T--;)
    {
        int n, m;
        scanf("%d%d",&n,&m);
        gen.input();
        memset(mi, 0, sizeof(mi));
        rep(i, 0, m)
        {
            L = gen() % n + 1;
            R = gen() % n + 1;
            v = gen() % md;
            //cerr<<L<<' '<<R<<' '<<v<<endl;
            if(L > R)
                swap(L, R);
            change(1,n,1);
        }
        long long ans = 0;
        for(pos = 1; pos <= n; ++pos)
        {
            ans ^= 1ll*pos*query(1,n,1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
