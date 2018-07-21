#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#define debug(...) fprintf(stderr, __VA_ARGS__), fprintf(stderr, "\n")
#else
#define debug(...) 98
#define cerr if (false) cout
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second

const int N = 30000 + 100;

struct edge {
    int y;
    edge * next;
};
static edge* li[N];
inline void add_edge(int u, int v) {
    static edge e[N << 1];
    static edge* ee = e;
    li[u] = &(*ee++ = (edge){v, li[u]});
    li[v] = &(*ee++ = (edge){u, li[v]});
}

static int sz[N], dep[N], fa[N], son[N];

void dfs_size(int u) {
    sz[u] = 1;
    son[u] = 0;
    int v;
    for (edge * t = li[u]; t; t = t->next) {
        v = t->y;
        if (v ^ fa[u]) {
            fa[v] = u;
            dep[v] = dep[u] + 1;
            dfs_size(v);
            sz[u] += sz[v];
            if (sz[son[u]] < sz[v]) son[u] = v;
        }
    }
}

static int bl[N], pos[N], clk;

void dfs(int u, int c) {
    pos[u] = ++clk;
    bl[u] = c;
    if (!son[u])
        return;
    dfs(son[u], c);
    int v;
    for (edge * t = li[u]; t; t = t->next) {
        v = t->y;
        if (v != fa[u] && v != son[u])
            dfs(v, v);
    }
}

static int s[N << 2], ma[N << 2];

inline void push_up(int rt) {
    ma[rt] = max(ma[rt << 1], ma[rt << 1 | 1]);
    s[rt] = s[rt << 1] + s[rt << 1 | 1];
}

void change(const int &pos, const int &val, int l, int r, int rt) {
    if (l == r) {
        ma[rt] = s[rt] = val;
        return;
    }
    int mid = l + r >> 1;
    pos > mid? change(pos, val, mid + 1, r, rt << 1 | 1): change(pos, val, l, mid, rt << 1);
    push_up(rt);
}

int query_max(const int &L, const int &R, int l, int r, int rt) {
    if (l >= L && r <= R)
        return ma[rt];
    int mid = l + r >> 1;
    if (L > mid)
        return query_max(L, R, mid + 1, r, rt << 1 | 1);
    if (R <= mid)
        return query_max(L, R, l, mid, rt << 1);
    return max(query_max(L, R, l, mid, rt << 1), query_max(L, R, mid + 1, r, rt << 1 | 1));
}

int query_sum(const int &L, const int &R, int l, int r, int rt) {
    if (l >= L && r <= R)
        return s[rt];
    int mid = l + r >> 1;
    if (L > mid)
        return query_sum(L, R, mid + 1, r, rt << 1 | 1);
    if (R <= mid)
        return query_sum(L, R, l, mid, rt << 1);
    return query_sum(L, R, l, mid, rt << 1) + query_sum(L, R, mid + 1, r, rt << 1 | 1);
}
int n;
inline int solve_sum(int x, int y) {
    int res = 0;
    while (bl[x] ^ bl[y]) {
        if (dep[bl[x]] < dep[bl[y]])
            swap(x, y);
        res += query_sum(pos[bl[x]], pos[x], 1, n, 1);
        x = fa[bl[x]];
    }
    if (pos[x] > pos[y])
        swap(x, y);
    return res + query_sum(pos[x], pos[y], 1, n, 1);
}

inline int solve_max(int x, int y) {
    int res = -0x3f3f3f3f;
    while (bl[x] ^ bl[y]) {
        if (dep[bl[x]] < dep[bl[y]])
            swap(x, y);
        res = max(res, query_max(pos[bl[x]], pos[x], 1, n, 1));
        x = fa[bl[x]];
    }
    if (pos[x] > pos[y])
        swap(x, y);
    return max(res, query_max(pos[x], pos[y], 1, n, 1));
}
int val[N];
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    scanf("%d", &n);
    rep(i, 1, n) {
        static int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
    }
    for (int i = 1; i <= n; ++i) scanf("%d", &val[i]);

    dfs_size(1);

    dfs(1, 1);

    for (int i = 1; i <= n; ++i) change(pos[i], val[i], 1, n, 1);

    int Q;
    for (scanf("%d", &Q); Q--; ) {
        static char op[10];
        static int x, y;
        scanf("%s%d%d", op, &x, &y);
        if (op[0] == 'C') change(pos[x], y, 1, n, 1);
        else if (op[1] == 'M') printf("%d\n", solve_max(x, y));
        else printf("%d\n", solve_sum(x, y));
    }
    return 0;
}
