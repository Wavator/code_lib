#include <bits/stdc++.h>
using namespace std;
const int N = 50000 + 200;

struct edge {
    int y;
    edge * next;
};
int cnt;
edge* li[N];

void clr() {
    cnt=0;
    memset(li,0,sizeof(li));
}

inline void add_edge(int u, int v) {
    static edge e[N<<1];
    e[cnt] = (edge){v,li[u]};
    li[u]=&e[cnt++];
    e[cnt] = (edge){u,li[v]};
    li[v]=&e[cnt++];
}

int sz[N], son[N], fa[N], dep[N];

void dfs_1(int u) {
    sz[u] = 1;
    int k = 0;
    for (edge * t = li[u]; t; t = t->next) {
        int v = t->y;
        if (v != fa[u]) {
            fa[v] = u;
            dep[v] = dep[u] + 1;
            dfs_1(v);
            if (sz[v] > sz[k])
                k = v;
        }
    }
    son[u] = k;
}

int pos[N], bl[N], clk;

void cut(int u, int chain) {
    bl[u] = chain;
    pos[u]=++clk;
    if (!son[u])
        return;
    cut(son[u], chain);
    for (edge * t = li[u];t;t=t->next) {
        int v = t->y;
        if (v != fa[u] && v != son[u]) {
            cut(v,v);
        }
    }
}

int lz[N<<2], a[N<<2];

inline void push_up(int rt) {
    a[rt] = a[rt << 1] + a[rt << 1 | 1];
}

inline void push_down(int rt, int le, int ri) {
    if (lz[rt]) {
        lz[rt << 1] += lz[rt];
        lz[rt << 1 | 1] += lz[rt];
        a[rt << 1] += le * lz[rt];
        a[rt << 1 | 1] += ri * lz[rt];
        lz[rt] = 0;
    }
}

void change(const int &L, const int &R, const int &val, int l, int r, int rt) {
    if (l >= L && r <= R) {
        a[rt] += (r - l + 1) * val;
        lz[rt] += val;
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

int query(const int &pos, int l, int r, int rt) {
    if (l == r)
        return a[rt];
    int mid = l + r >> 1;
    push_down(rt, mid - l + 1, r - mid);
    return pos > mid? query(pos, mid + 1, r, rt << 1 | 1): query(pos, l, mid, rt << 1);
}
int n;
inline void solve_chain(int x, int y, int val) {
    while (bl[x] != bl[y]){
        if (dep[bl[x]] < dep[bl[y]])
            swap(x, y);
        change(pos[bl[x]], pos[x], val, 1, n, 1);
        x = fa[bl[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    change(pos[x], pos[y], val, 1, n, 1);
}
int values[N];

int main() {
    int m, p;
    while (~scanf("%d%d%d", &n, &m, &p)) {
        clr();
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &values[i]);
        }
        for (int x, y;m--;) {
            scanf("%d%d",&x,&y);
            add_edge(x,y);
        }
        clk=0;
        dep[1]=0;
        fa[1]=0;
        dfs_1(1);
        cut(1,1);
        memset(lz,0,sizeof(int)*(4*n));
        memset(a,0,sizeof(int)*(4*n));
        for (int i = 1; i <= n; ++i) {
            change(pos[i],pos[i],values[i],1,n,1);
        }
        static char op[3];
        for (int x, y, z; p--;) {
            scanf("%s",op);
            if (op[0] == 'I') {
                scanf("%d%d%d",&x,&y,&z);
                solve_chain(x,y,z);
            } else if (op[0] == 'D') {
                scanf("%d%d%d",&x,&y,&z);
                solve_chain(x,y,-z);
            } else {
                scanf("%d",&x);
                printf("%d\n",query(pos[x],1,n,1));
            }
            getchar();
        }
    }
    return 0;
}