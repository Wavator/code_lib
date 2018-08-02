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
const ll mod = (ll)1e9 + 7;
ll pow_mod(ll a, ll b) {
    assert(b >= 0);ll res=1;
    for (a %= mod; b; b >>= 1, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    ll t, a, b;
    cin >> t >> a >> b;
    ll num = t / 6, curr = t % 6;
    ll ans = min(a * 3, b * 2) * num;
    if (curr == 5) {
        curr = min(b*2,min(a + b, a * 3));
    }
    else if (curr == 4) {
        curr = min(b * 2, min(a + b, a * 2));
    }
    else if (curr == 3) {
        curr = min(b, a * 2);
    }
    else if (curr == 2) {
        curr = min(a, b);
    }
    else if (curr == 1) {
        if (a * 3 > b * 2) {
            curr = min(a, min(b, 2 * a - b));
        }
        else {
            curr = min(a, min(b, b - a));
        }
    }
    else if (curr == 0)curr = 0;
    ans += curr;
    cout << ans << endl;
    return 0;
}