#pragma GCC optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#define debug(...) fprintf(stderr, __VA_ARGS__), fprintf(stderr, "\n"), fflush(stderr)
#else
#define debug(...) 99
#endif
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;typedef unsigned long long ull;typedef double db;
template <typename T> using pqmin = priority_queue<T, vector<T>, greater<T> >;template <typename T> using pqmax = priority_queue<T>;
template <typename T> using V = vector<T>;typedef V<int> vi;typedef pair<int,int> pii;
inline char gc() { static char buf[1<<20],*h=buf,*t=buf;return (h==t&&(t=(h=buf)+fread(buf,1,1<<20,stdin),h==t)?-1:*h++);}
template <typename T> inline bool read(T &x){static int f;static char c;for(c=gc(),f=1;!isdigit(c);c=gc()){if(c==-1)return false;else if(c==45)f=-1;}for(x=c-48;isdigit(c=gc());x=x*10+c-48);return x*=f,true; }
template <typename A, typename B> inline bool read(A&x, B&y) {return read(x) && read(y);}
template <typename A, typename B, typename C> inline bool read(A&x,B&y,C&z){return read(x)&&read(y)&&read(z);}
/*
 *
 */
typedef bitset<1003> b;

const int N = 100005;

vi e[N];
int n, m;
int pos[N], fin[N], value[N], clk;

void change1(const int &pos, const int &x, int l, int r, int rt);

void dfs(int u, int fa) {
    pos[u] = ++clk;
    change1(clk, value[u], 1, n, 1);
    for (const int &v: e[u]) if (v != fa) dfs(v, u);
    fin[u] = clk;
}

int lzy[N << 2];
b s[N << 2];

inline void my_add(int rt, int val) {
    val %= m;
    s[rt] = (s[rt] << val)  | (s[rt] >> (m - val));
}

inline void push_up(int rt) {
    s[rt] = s[rt << 1] | s[rt << 1 | 1];
}

inline void add(int &x, int y) {
    x += y;
    if (x >= m) x -= m;
}

void push_down(int rt) {
    if (lzy[rt]) {
        add(lzy[rt << 1], lzy[rt]);
        add(lzy[rt << 1 | 1], lzy[rt]);
        my_add(rt << 1, lzy[rt]);
        my_add(rt << 1 | 1, lzy[rt]);
        lzy[rt] = 0;
    }
}

void change1(const int &pos, const int &x, int l, int r, int rt) {
    if (l == r) {
        s[rt].set(x);
        return;
    }
    int mid = l + r >> 1;
    if (pos <= mid) change1(pos, x, l, mid, rt << 1);
    else change1(pos, x, mid + 1, r, rt << 1 | 1);
    push_up(rt);
}

void change(const int &L, const int &R, const int &x, int l, int r, int rt) {
    if (l >= L && r <= R) {
        my_add(rt, x);
        add(lzy[rt], x);
        return;
    }
    int mid = l + r >> 1;
    push_down(rt);
    if (L <= mid) change(L, R, x, l, mid, rt << 1);
    if (R > mid) change(L, R, x, mid + 1, r, rt << 1 | 1);
    push_up(rt);
}


b query(const int &L, const int &R, int l, int r, int rt) {
    if (l >= L && r <= R) return s[rt];
    int mid = l + r >> 1;
    push_down(rt);
    if (L > mid) return query(L, R, mid + 1, r, rt << 1 | 1);
    if (R <= mid) return query(L, R, l, mid, rt << 1);
    return query(L, R, l, mid, rt << 1) | query(L, R, mid + 1, r, rt << 1 | 1);
}

b p;

inline bool ck_prime(int x) {
    for (int i = 2; i * i <= x; ++i) if (x % i == 0) return false;
    return true;
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    read(n, m);
    p.reset();
    for (int i = 2; i < m; ++i)
        p[i] = ck_prime(i);
    for (int i = 1; i <= n; ++i) read(value[i]), value[i] %= m;
    for (int i = 1, u, v; i < n; ++i) {
        read(u, v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    int Q;
    for (read(Q); Q--;) {
        static int tp, x, y;
        read(tp);
        if (tp == 1) {
            read(x, y);
            change(pos[x], fin[x], y % m, 1, n, 1);
        } else {
            read(x);
            printf("%d\n", (int)(p & query(pos[x], fin[x], 1, n, 1)).count());
        }
    }
    return 0;
}