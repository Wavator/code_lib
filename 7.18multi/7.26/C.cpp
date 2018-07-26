#pragma optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
template <typename T> using V = vector<T>;
template <typename T> using pqmax = priority_queue<T>;
template <typename T> using pqmin = priority_queue<T, V<T>, greater<T> >;
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define SZ(x) ((int)(x).size())
#define pb push_back
 
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
const ll mod = (ll)1e9+7;
ll pow_mod(ll a, ll b = mod - 2) {
    assert(b >= 0); ll res = 1; for (a %= mod; b; b >>= 1, a = a * a % mod) if (b & 1) res = res * a % mod;
    return res;
}
const int N = 100005;
int a[N];
int sz[N], ch[N][2], fa[N];
int key[N], rev[N];
int root, tot;
int stk[N], top;
void push_down(int x) {
    if (rev[x]) {
        swap(ch[x][0], ch[x][1]);
        if (ch[x][0])
            rev[ch[x][0]] ^= 1;
        if (ch[x][1])
            rev[ch[x][1]] ^= 1;
        rev[x] = 0;
    }
}
void push_up(int x) { sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1; }
int new_node(int p = 0, int k = 0) {
    int x = top ? stk[top--] : ++tot;
    fa[x] = p;
    sz[x] = 1;
    ch[x][0] = ch[x][1] = 0;
    key[x] = k;
    rev[x] = 0;
    return x;
}
int build(int l, int r, int p) {
    if (l > r) return 0;
    int mid = l + r >> 1;
    int x = new_node(p, a[mid]);
    ch[x][0] = build(l, mid - 1, x);
    ch[x][1] = build(mid + 1, r, x);
    push_up(x);
    return x;
}
void init(int n) {
    tot = 0, top = 0;
    root = new_node(0, -1);
    ch[root][1] = new_node(root, -1);
    for (int i = 0; i < n; i++) a[i] = i + 1;
    ch[ch[root][1]][0] = build(0, n - 1, ch[root][1]);
    push_up(ch[root][1]);
    push_up(root);
}
 
void rotate(int x, int d) {
    int y = fa[x];
    push_down(y), push_down(x);
    ch[y][d ^ 1] = ch[x][d];
    fa[ch[x][d]] = y;
    if (fa[y]) ch[fa[y]][ch[fa[y]][1] == y] = x;
    fa[x] = fa[y];
    ch[x][d] = y;
    fa[y] = x;
    push_up(y);
}
void splay(int x, int goal = 0) {
    push_down(x);
    while (fa[x] != goal) {
        if (fa[fa[x]] == goal)
            rotate(x, ch[fa[x]][0] == x);
        else {
            int y = fa[x];
            int d = ch[fa[y]][0] == y;
            ch[y][d] == x ? rotate(x, d ^ 1) : rotate(y, d);
            rotate(x, d);
        }
    }
    push_up(x);
    if (goal == 0) root = x;
}
int kth(int r, int k) {
    push_down(r);
    int t = sz[ch[r][0]] + 1;
    if (t == k) return r;
    return t > k ? kth(ch[r][0], k) : kth(ch[r][1], k - t);
}
void dfs(int u) {
    if (u) {
        dfs(ch[u][0]);
        if (~key[u]) printf("%d ", key[u]);
        dfs(ch[u][1]);
    }
}
 
void gen_len(int l, int r) {
    splay(kth(root, l), 0);
    splay(kth(ch[root][1], r - l + 2), root);
}
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
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int n, m;
    read(n);
    init(n);
    for(read(m);m--;) {
        int l, len;
        read(l);
        read(len);
        int r = l + len - 1;
        gen_len(l, r);
        auto t = ch[ch[root][1]][0];
        ch[ch[root][1]][0] = 0;
        gen_len(1, 0);
        ch[ch[root][1]][0] = t;
        fa[t] = ch[root][1];
    }
    dfs(root);
    return 0;
}