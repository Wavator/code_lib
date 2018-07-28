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
        for (c=gc();c<'0'||c>'2';c=gc()); for (l=0;c<='2'&&c>='0';c=gc()) s[l++]=c; s[l]=0;
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
const int mod = (int)1e9+7;
const int N = 1e5 + 10;
char s[N];
int  T;
int n;
//const int M = 1e6+10;
//int phi[M];
inline ll myphi(ll n) {
    //if (n < M) return phi[n];
    int ans = n;
    for (int i = 2; i * i <= n; ++i){
        if (n % i == 0){
            ans -= ans / i;
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) ans -= ans / n;
    return ans;
}
#define int long long
unordered_map<int, int> mp;
 
inline int kiss_me(int a, int b, int mod){
    int ret=1;
    for (; b; b >>= 1, a = (ll) a * a % mod) if (b & 1) ret = (ll)ret * a % mod;
    return ret;
}
int a[N];
ll ans[N], c[N];
void Main(){
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    mp[mod]=mod-1;
    mp[mod-1]=500000002;
    mp[500000002]=243900800;
    mp[243900800]=79872000;
    mp[79872000]=19660800;
    mp[19660800]=5242880;
    mp[5242880]=2097152;
    mp[2097152]=1048576;
    mp[1048576]=524288;
    mp[524288]=262144;
    mp[262144]=131072;
    mp[131072]=65536;
    mp[65536]=32768;
    mp[32768]=16384;
    mp[16384]=8192;
    mp[8192]=4096;
    mp[4096]=2048;
    mp[2048]=1024;
    mp[1024]=512;
    mp[512]=256;
    mp[256]=128;
    mp[128]=64;
    mp[64]=32;
    mp[32]=16;
    mp[16]=8;
    mp[8]=4;
    mp[4]=2;
    for (sc(T); T--; ){
        gs(s+1,n);
        rep(i, 0, n + 2) a[i] = 0;
        rep(i, 1, n + 1) a[i] = s[i] - '0';
        rep(i, 0, n + 2) c[i] = 0;
        c[n] = mod;
        for (int i = n; i ; --i){
            if (a[i] == 2){
                if(!mp.count(c[i]))mp.insert({c[i],myphi(c[i])});
                c[i-1]=mp[c[i]];
            }
            else c[i - 1] = c[i];
        }
 
        rep(i, 0, n + 2) ans[i] = 0;
 
        rep(i, 1, n+1) {
            if (a[i] == 0) ans[i] = (ans[i - 1] + 1) % c[i];
            else if (a[i] == 1) ans[i] = (ans[i - 1] * 2ll + 2ll) % c[i];
            else ans[i] = (6ll * kiss_me(2ll, ans[i - 1], c[i]) % c[i] - 3ll + c[i] * 10ll) % c[i];
        }
        pl(ans[n]);
    }
    return ;
}
signed main() {
#define OPENSTACK
#ifdef OPENSTACK
    size_t size = 70 << 20; // 256MB
    char *p = (char*)malloc(size) + size;
#if (defined _WIN64) or (defined __unix)
    __asm__("movq %0, %%rsp\n" :: "r"(p));
#else
    __asm__("movl %0, %%esp\n" :: "r"(p));
#endif
#endif
    Main();
#ifdef OPENSTACK
    exit(0);
#else
    return 0;
#endif
 
}