#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) 42
#endif
typedef long long ll;
const int N = 100010;

struct edge {
    int y;
    edge * next;
};

edge* li[N];

inline void add_edge(int u, int v) {
    static edge e[N << 1];
    static edge* top = e;
    li[u] = &(*top++ = (edge){v, li[u]});
    li[v] = &(*top++ = (edge){u, li[v]});
}

int sz[N], dep[N], fa[N], son[N];

void dfs_size(int u) {
    sz[u] = 1;
    int v;
    for (edge * t = li[u]; t; t = t->next) {
        v = t->y;
        if (v ^ fa[u]) {
            dep[v] = dep[u] + 1;
            fa[v] = u;
            dfs_size(v);
            sz[u] += sz[v];
            if (sz[son[u]] < sz[v])
                son[u] = v;
        }
    }
}

int fin[N], pos[N], bl[N], clk;

void dfs(int u, int c) {
    pos[u] = fin[u] = ++clk;
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
    fin[u] = clk;
}

ll sum[N * 4], tag[N * 4];

inline void push_up(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

inline void push_down(int rt, ll le, ll ri) {
    if (tag[rt]) {
        tag[rt << 1] += tag[rt];
        tag[rt << 1 | 1] += tag[rt];

        sum[rt << 1] += le * tag[rt];
        sum[rt << 1 | 1] += ri * tag[rt];

        tag[rt] = 0;
    }
}


void change(const int &L, const int &R, const int &val, int l, int r, int rt) {
    if (l >= L && r <= R) {
        sum[rt] += (ll)(r - l + 1) * val;
        tag[rt] += val;
        return;
    }
    int mid = l + r >> 1;
    push_down(rt, mid - l + 1, r - mid);
    if (L <= mid)
        change(L, R, val, l, mid, rt << 1);
    if (R > mid)
        change(L, R, val, mid + 1, r, rt << 1 | 1);
    push_up(rt);
}

ll query(const int &L, const int &R, int l, int r, int rt) {
    if (l >= L && r <= R)
        return sum[rt];
    int mid = l + r >> 1;
    push_down(rt, mid - l + 1, r - mid);
    if (L > mid)
        return query(L, R, mid + 1, r, rt << 1 | 1);
    else if (R <= mid)
        return query(L, R, l, mid, rt << 1);
    else
        return query(L, R, l, mid, rt << 1) + query(L, R, mid + 1, r, rt << 1 | 1);
}




int values[N];
int n;


int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int Q;
    scanf("%d%d", &n, &Q);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &values[i]);
    for (int i = 1; i < n; ++i) {
        static int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
    }
    dfs_size(1);
    dfs(1, 1);
    for (int i = 1; i <= n; ++i) {
        change(pos[i], pos[i], values[i], 1, n, 1);
    }
    for (int op, x, y; Q--; ) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d%d", &x, &y);
            change(pos[x], pos[x], y, 1, n, 1);
        } else if (op == 2) {
            scanf("%d%d", &x, &y);
            change(pos[x], fin[x], y, 1, n, 1);
        } else {
            ll res = 0;
            scanf("%d", &x);
            while (bl[x] != 1) {
                res += query(pos[bl[x]], pos[x], 1, n, 1);
                x = fa[bl[x]];
            }
            res += query(1, pos[x], 1, n, 1);
            printf("%lld\n", res);
        }
    }
    return 0;
}