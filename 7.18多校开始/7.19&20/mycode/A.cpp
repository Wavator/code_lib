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
const ll mod = (ll) 1e9 + 7;
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
const int N = 1200 * 2;
ll fact[N], finv[N];
 
ll pow_mod(ll a, ll b = mod - 2) {
    ll res = 1;
    for (a %= mod; b; b >>= 1, a = a * a % mod) {
        if (b & 1) {
            res = res * a % mod;
        }
    }
    return res;
}
 
 
inline ll C(ll n, ll m) {
    return (fact[n] * finv[n - m] % mod) * finv[m] % mod;
}
 
inline ll F(int n, int k) {
    return (C(n - 1, k - 1) * C(n, k - 1) % mod) * pow_mod(k) % mod;
}
 
int main(){
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    fact[0] = 1;
    rep(i, 1, N) fact[i] = fact[i - 1] * i % mod;
 
    finv[N - 1] = pow_mod(fact[N - 1]);
 
    for (ll i = N - 2; ~i; --i) {
 
        finv[i] = finv[i + 1] * (i + 1) % mod;
    }
 
    int n, m;
    while (read(n) && read(m)) {
 
        if (n < m) swap(n, m);
 
        out.println(F(n + m + 1, m + 1));
 
    }
 
    return 0;
}