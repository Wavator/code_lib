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
 
int n, m1, m2;
 
int e[15][15];
 
struct bian {
    int x, y;
};
 
vector<bian> bians;
 
map<pii, int> my_map;
 
inline int genId(pii x) {
    if (x.fi > x.se) swap(x.fi, x.se);
    if (my_map.count(x)) return my_map[x];
    return my_map[x] = my_map.size() + 1;
}
 
int my_per[15];
 
struct hasher {
 
    static const ull hash_base = 151;
 
    ull hash_power[200];
 
    hasher() {
        hash_power[0] = 1;
        rep(i, 1, 200) {
            hash_power[i] = hash_power[i - 1] * hash_base;
        }
    }
 
    inline ull gethash(const pii &o) {
        return hash_power[genId(o)];
    }
 
    inline ull operator()(const vector<bian> &e) {
        ull res = 0;
        for (const bian & b: e) {
            int u = my_per[b.x];
            int v = my_per[b.y];
            if (::e[u][v] == 0) return 0;
            res += gethash({u, v});
        }
        return res;
    }
 
};
 
hasher hh;
 
ull ans[500000];
void solve() {
    memset(e, 0, sizeof(e));
    bians.clear();
    my_map.clear();
    int u, v;
    REP(i, 1, m1) {
        read(u);
        read(v);
        bians.push_back((bian){u, v});
    }
    REP(i, 1, m2) {
        read(u);
        read(v);
        e[u][v] = 1;
        e[v][u] = 1;
    }
    REP(i, 1, n) my_per[i] = i;
 
    int cnt = 0;
 
    do {
 
        auto x = hh(bians);
        if (x)
            ans[cnt++] = x;
    } while (next_permutation(my_per + 1, my_per + n + 1));
 
    sort(ans, ans + cnt);
 
    out.println(unique(ans, ans + cnt) - ans);
 
}
 
int main(){
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    while (read(n) && read(m1) && read(m2)) solve();
    return 0;
}