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
    #define debug(fmt, ...) fprintf(stderr, "func[%s]: %s = " fmt "\n", \
                __func__, #__VA_ARGS__, __VA_ARGS__), fflush(stderr)
    #define err(x) cerr << "func[" << __func__ << "]: " \
                    << #x << " = " << x << endl << flush
#else
    #define debug(...) 0
    #define err(x) 0
#endif
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
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
#define sc2(x, y) sc((x)); sc((y))
#define sc3(x, y, z) sc((x)); sc((y)); sc((z))
const int N = 10000005;
int n,m,k,p,q,r,mod;
int a[N], suff[N];

inline int my_add(int a, int b) {
    a += b;
    return a >= mod? a - mod: a;
}

inline int my_mult(int a, int b) {
    ll res = (ll)a * b;
    return res >= mod? res % mod: res;
}

void solve() {
    sc3(n, m, k);
    sc3(p, q, r);
    sc(mod);
    for (int i = 1; i <= k; i ++)
        read(a[i]);
    for (int i = k + 1; i <= n; i ++)
        a[i] = my_add(my_add(my_mult(p, a[i - 1]), my_mult(q, i)), r);
    fill(suff + 1, suff + n + 1, 0);
    int cnt = 0;
    deque<int> dq;
    ll ans1 = 0, ans2 = 0;
    for (int i = 1, head = 1, tl = 1; i <= n - m + 1; ++i) {
        while (tl < i + m) {
            while (!dq.empty() && a[tl] > a[dq.back()])
                dq.pop_back();
            if (dq.empty())
                cnt++;
            else
                suff[dq.back()]++;
            dq.push_back(tl++);
        }
        if (head < i) {
            if (head == dq.front())
                dq.pop_front();
            cnt += suff[head++] - 1;
        }
        ans1 += (a[dq.front()] ^ i);
        ans2 += (cnt ^ i);
    }
    printf("%lld %lld\n", ans1, ans2);
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int T;
    for (sc(T); T--; solve());
    return 0;
}