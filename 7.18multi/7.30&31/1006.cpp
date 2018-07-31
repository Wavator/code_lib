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
const ll mod = (ll)1e9 + 7;
ll pow_mod(ll a, ll b) {
    assert(b >= 0);ll res=1;
    for (a %= mod; b; b >>= 1, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}
const int LEN=(1<<21)+1; char ibuf[LEN],*iS,*iT,obuf[LEN],*oS=obuf,*oT=obuf+LEN-1,c,st[55];int f,tp;
#define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,LEN,stdin),(iS==iT?EOF:*iS++)):*iS++)
inline void flush() {fwrite(obuf,1,oS-obuf,stdout);oS=obuf;}
inline void pc(char x) { *oS++=x; if (oS==oT) flush(); }
template<class I> inline void sc(I&x) {
    for (f=1,c=gc();c<'0'||c>'9';c=gc()) if (c=='-') f=-1;
    for (x=0;c<='9'&&c>='0';c=gc()) x=x*10+(c&15); x*=f;
}
const int N = 100010;

int w[N];
int n;

int main() {
#ifdef Wavator
    freopen("test.in","r",stdin);
#endif
    int T;
    for (sc(T); T--; ) {
        sc(n);
        for (int i = 1; i <= n; ++i) sc(w[i]);
        int l, r;
        for (int i = 1; i < n; ++i) {
            sc(l);
            sc(r);
        }
        ll s = 0;
        for (int i = 1; i <= n; ++i) s ^= w[i];
        puts(s? "Q": "D");
    }
    return 0;
}