#include <bits/stdc++.h>
#pragma optimize("-O3")
using namespace std;
template <typename A, typename B>
inline ostream& operator << (ostream&os, const pair<A, B> &v) {
    return os << v.first << ' ' << v.second;
}
template <typename T>
inline ostream& operator << (ostream&os, const vector<T> &v) {
    for (auto it = v.begin(); it != v.end(); os << (*it++)) if (it != v.cbegin()) os << '\n';
    return os;
}
#ifdef Wavator
#define debug(...) cerr << #__VA_ARGS__ << " = \n[ ", _debug(__VA_ARGS__), cerr << "]" << endl
#else
#define debug(...) 98
#define cerr if (false) cout
#endif
void _debug(){}
template <typename H, typename...T>
void _debug(H head, T...tail) {
    cerr << head << " ";
    _debug(tail...);
}
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, pii> pip;

void Main();

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Main();
    return 0;
}
const int N = 1000005;

struct edge {
    int y;
    edge * next;
};

edge * li[N];

inline void add_edge(int u, int v) {
    static edge e[N << 1];
    static edge* top = e;
    li[u] = &(*top++ = (edge){v, li[u]});
    li[v] = &(*top++ = (edge){u, li[v]});
}

struct node{
    int x, y;
    inline bool operator < (const node &b) const {
        return x == b.x ? y < b.y : x > b.x;
    }
} s[N << 2];

int c[N], deep[N], sz[N];
int n;
int ans[N];
//vector <int> v[N];

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

void pre(int x, int fa, int dep){
    deep[x] = dep;
    sz[x] = 1;
    for (edge *t  = li[x]; t; t = t->next){
        int u = t->y;
        if (u == fa) continue;
        pre(u, x, dep + 1);
        sz[x] += sz[u];
    }
}


node query(int i, int l, int r, int x, int y){
    if (x <= l && r <= y) return s[i];

    int mid = (l + r) >> 1;

    node ret;
    ret.x = -1;
    ret.y = 1e6 + 10;
    if (x <= mid) ret = min(ret, query(i << 1, l, mid, x, y));
    if (y >  mid) ret = min(ret, query(i << 1 | 1, mid + 1, r, x, y));

    return ret;
}


void update(int i, int l, int r, int x, int val){
    if (l == r && l == x){
        s[i].x += val;
        return;
    }

    int mid = (l + r) >> 1;

    if (x <= mid) update(i << 1, l, mid, x, val);
    else update(i << 1 | 1, mid + 1, r, x, val);

    s[i] = min(s[i << 1], s[i << 1 | 1]);
}



inline void up(int x, int op){
    update(1, 1, n, deep[x], op);
}

inline void add(int x, int fa, int op){
    up(x, op);
    for (edge *t  = li[x]; t; t = t->next){
        int u = t->y;
        if (u == fa) continue;
        add(u, x, op);
    }
}

void dfs(int x, int fa, int keep){
    int mx = -1, son = -1;

    int u;
    for (edge *t  = li[x]; t; t = t->next){
        u = t->y;
        if (u != fa && sz[u] > mx){
            mx = sz[u];
            son = u;
        }
    }

    for (edge *t  = li[x]; t; t = t->next){
        u = t->y;
        if (u != son && u != fa) dfs(u, x, 0);
    }

    if (~son) dfs(son, x, 1);

    for (edge *t  = li[x]; t; t = t->next){
        u = t->y;
        if (u != son && u != fa){
            add(u, x, 1);
        }
    }


    up(x, 1);

    if (deep[x] > n) ans[x] = 0;
    else{
        node ss = query(1, 1, n, deep[x], n);
        if (ss.x > 0) ans[x] = ss.y - deep[x];
        else ans[x] = 0;
    }


    if (keep == 0) add(x, fa, -1);
}

void build(int i, int l, int r){
    if (l == r){
        s[i].y = l;
        return;
    }

    int mid = (l + r) >> 1;

    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);

    s[i] = min(s[i << 1], s[i << 1 | 1]);
}
struct print_writer {
    static const int OUT_LEN = 1<<20;
    char obuf[OUT_LEN], *oh = obuf;
    inline void print(char c) {
        if (oh == obuf + OUT_LEN)
            fwrite(obuf, 1, OUT_LEN, stdout), oh = obuf;
        *oh++ = c;
    }
    template<class T>
    inline void print(T x) {
        static int buf[30], cnt;
        if (x == 0) {
            print('0');
        } else {
            if (x < 0) print('-'), x = -x;
            for (cnt = 0; x; x /= 10) buf[++cnt] = x % 10 + 48;
            while (cnt) print((char)buf[cnt--]);
        }
    }

    ~print_writer() {
        fwrite(obuf, 1, oh - obuf, stdout);
    }
}out;
void Main(){

    read(n);
    for (int i = 1; i < n; ++i){
        int x, y;
        read(x);
        read(y);
        add_edge(x, y);
    }
    pre(1, 0, 1);
    build(1, 1, n);
    dfs(1, 0, 0);
    for (int i = 1; i <= n; ++i)
        out.print(ans[i]), out.print(char(10));
}