/*
 *      Author name: Wavator
 *      Mail: 11612908@mail.sustc.edu.cn
 * */
#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#ifdef Wavator
#define debug(...) fprintf(stderr, __VA_ARGS__), fprintf(stderr, "\n")
#else
#define debug(...) 42
#endif
#define rep(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define per(i, a, b) for (int (i) = (b) - 1; (i) >= (a); --(i))
#define REP(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
#define PER(i, a, b) for (int (i) = (b); i >= (a); --i)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vp;
const ll mod = (ll)1e9 + 7;
const db eps = 1e-9;
/*
 * head template
 */

inline char gc() {
    static char buf[1<<20], *head = buf, *tail = buf;
    return (head == tail && (tail = (head = buf) + fread(buf, 1, 1 << 20, stdin), head == tail)? -1: *head++);
}
template <typename T> inline bool read(T &x) {
    static bool f;
    static char c;
    for (c = gc(), f = false; !isdigit(c); c = gc()) {
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
const int N = 100005;
vi e[N];

int c[N];
//
//int sz[N], son[N];
//
//void pre_dfs(int u, int fa) {
//    sz[u] = 1;
//    for (const auto &v: e[u]) if (v != fa) {
//        pre_dfs(v, u);
//        sz[u] += sz[v];
//        if (sz[son[u]] < sz[v]) son[u] = v;
//    }
//}

struct my_map {
    map<int, int> mp;
    int mx;// cnt;
    //set<pii> s;
    set<int> s;
    ll sum;
    void clear() {
        sum = 0;
        s.clear();
        mp.clear();
        mx = 0;
        //cnt = 0;
    }
    void insert(int u) {
        mp[c[u]]++;
        int x = mp[c[u]];
        int y = mp[mx];
        if (x > y) {
            s.clear();
            mx = c[u];
            sum = c[u];
            s.insert(mx);
            //cnt = x;
        } else if (x == y && !s.count(c[u])) {
            sum += c[u];
            s.insert(c[u]);
        }
    }


    inline bool operator < (const my_map &o) const {
        return SZ(mp) < SZ(o.mp);
    }

    inline void operator += (const my_map &o){
//        for (const auto &p: o.mp) {
//            mp[p.fi] += p.se;
//            if (mp[mx] < mp[p.fi]) mx = p.fi;
//        }
//        s.clear();
//        sum = 0;
//        for (const auto &p: mp) {
//            if (p.second == mp[mx]) {
//                sum += p.first;
//                s.insert(p.first);
//            }
//        }

        //assert(SZ(mp) >= SZ(o.mp));
        int pre_mx = mp[mx];

        for (const auto &p: o.mp) {
            mp[p.fi] += p.se;
            if (pre_mx < mp[p.fi]) {
                mx = p.fi;
                pre_mx = mp[p.fi];
                s.clear();
                sum = p.fi;
                s.insert(p.fi);
            } else if (pre_mx == mp[p.fi] && !s.count(p.fi)) {
                sum += p.fi;
                s.insert(p.fi);
            }
        }
    }

//    friend my_map operator + (const my_map&l, const my_map&r) {
//        my_map res;
//        res.clear();
//        if (l < r) {
//            res = r;
//            res.pull(l);
//        } else {
//            res = l;
//            res.pull(r);
//        }
//        return res;
//    }

    ll query() {
        return sum;
    }

};

my_map maps[N];

ll ans[N];

void dfs(int u, int fa) {
//    for (const auto&v: e[u]) {
//        if (v != fa && v != son[u]) {
//            dfs(v, u);
//
//        }
//    }
    maps[u].insert(u);
    for (const auto &v: e[u]) {
        if (v != fa) {
            dfs(v, u);
            if (maps[u] < maps[v]) swap(maps[v], maps[u]);
            maps[u] += maps[v];
        }
    }

    ans[u] = maps[u].query();
}
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
    inline void println() {
        pc(10);
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
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int n;
    read(n);
    REP(i, 1, n) {
        read(c[i]);
    }
    rep(i, 1, n) {
        static int u, v;
        read(u);
        read(v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    REP(i, 1, n) out.prints(ans[i]);
    out.println();
//    srand((unsigned)time(0));
//    int n = 20;
//    for (int i = 1; i <= n; ++i) {
//        out.prints(1 + abs(rand()) % 20);
//    }
//    out.println();

    return 0;
}