#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#define debug(...) fprintf(stderr, __VA_ARGS__), fprintf(stderr, "\n")
#else
#define debug(...) 99
#endif
#define forn(i, n) for(int i = 0; i < (n); ++i)
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, a, b) for(int i = (a); i <= (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
ll mod;
class print_writer {
public:
    template<class T>
    inline void print(T x) {
        static int a[30], cnt;
        if (x == 0) {
            pc(48);
        } else {
            if (x < 0) pc(45), x = -x;
            for (cnt = 0; x; x /= 10) a[++cnt] = x % 10 + 48;
            for(;cnt;)
                pc((char)a[cnt--]);
        }
    }
    inline void print(const char * s) {
        static int i;
        for (i = 0; s[i]; ++i) pc(s[i]);
    }
    inline void print(char c) {
        pc(c);
    }
    inline void print(const string &s) {
        for (const auto&c : s) pc(c);
    }
    template <typename T> inline void println(const T&x) {
        print(x), pc(10);
    }
    template <typename T> inline void prints(const T &x) {
        print(x), pc(' ');
    }
    inline void flush() {
        fwrite(obuf, 1, OUT_LEN, stdout), oh = obuf;
        fflush(stdout);
    }
    ~print_writer() {
        fwrite(obuf, 1, oh - obuf, stdout);
    }
private:
    static const int OUT_LEN = 1<<20;
    char obuf[OUT_LEN], *oh = obuf;
    inline void pc(char c) {
        if (oh == obuf + OUT_LEN)
            fwrite(obuf, 1, OUT_LEN, stdout), oh = obuf;
        *oh++ = c;
    }
 
}out;
inline char gc() {
    static char buf[1<<20], *head = buf, *tail = buf;
    return (head == tail && (tail = (head = buf) + fread(buf, 1, 1 << 20, stdin), head == tail)? -1: *head++);
}
template <typename T> inline bool read(T &x) {
    static bool f;
    static char c;
    for (c = gc(), f = false; !isdigit(c); c =gc()) {
        if (c == EOF)
            return false;
        else if (c == 45)
            f = true;
    }
    for (x = 0; isdigit(c); c = gc())
        x = x * 10 + c - 48;
    if (f)
        x = -x;
    return true;
}
ll pow_mod(ll a, ll b) {
    assert(b >= 0);
    ll res = 1;
    for (a %= mod; b; b >>= 1, a = a * a % mod) {
        if (b & 1) {
            res = res * a % mod;
        }
    }
    return res;
}
void exgcd(ll a,ll b,ll& d,ll& x,ll& y) {
    if(!b) { d = a; x = 1; y = 0; }
    else{ exgcd(b, a%b, d, y, x); y -= x*(a/b); }
}
 
ll inv(ll a) {
    ll d, x, y;
    exgcd(a, mod, d, x, y);
    return d == 1 ? (x + mod) % mod : -1;
}
const int N = 100005;
 
ll f[N];
 
ll fact[N], finv[N];
 
inline ll C(ll n, ll m) {
    return (fact[n] * (finv[n - m]) % mod) * finv[m] % mod;
}
//ll t;
//ll a(ll n) {
//    if (n == 0) return 1;
//    if (n == 2) return 0;
//    if (n == 3) return 1;
//    if (n == 4) return 6;
//    return f[n] = (((n-1)*((a(n-1)+a(n-2))%mod)%mod - (((n - 1) * (n-2) % mod) * a(n-3)%mod)*t%mod ) + mod) % mod;
//}
 
int main(){
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int N;
    //ll m;
    while (read(N) && read(mod)) {
        f[0] = 1;
        f[1] = 0;
        f[2] = 1;
        f[3] = 1;
        //f[4] = 6;
        ll t = inv(2);
        //assert(t*2%mod==1);
        for (ll n = 4; n <= N; ++n) {
            f[n] = (1ll * (n - 1) * ((f[n - 1] + f[n - 2]) % mod)) % mod - ((((1ll * ((n - 1) * (n - 2)/2) % mod) * f[n - 3] % mod)) % mod);
            f[n] += mod;
            f[n] %= mod;
            assert(f[n] >= 0);
        }
        out.println(f[N]);
    }
    return 0;
}