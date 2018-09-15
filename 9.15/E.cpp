//while (clock()<=4.9*CLOCKS_PER_SEC)
#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#ifndef Wavator
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#define unordered_map __gnu_pbds::cc_hash_table
#endif
using namespace std;
#ifdef Wavator
#include "local_debug.h"
#else
#define debug(...)
#endif
#define pb push_back
#define rep(i,a,n) for(int i=(a);i<(n);++i)
#define per(i,a,n) for(int i=(n)-1;i>=(a);--i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef unsigned long long ll;
typedef unsigned long long ull;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
constexpr db PI = acos(-1), eps = 1e-8;
typedef unsigned long long LL;
const int N = 200005;
struct Tree1 {
//    struct Seg {
////        int l, r;
////        LL sum;
////
////        void reset() {
////            sum = 0;
////            add = 0;
////            mul = 1;
////        }
////
////        inline int mid() {
////            return (l + r) >> 1;
////        }
////
////        inline int range() {
////            return r - l + 1;
////        }
////
////        LL add, mul = 1;
////    };
////
////
////    Seg tree[N << 2];
////
////
////    inline void push_up(int rt) {
////        tree[rt].sum = (tree[rt << 1].sum + tree[rt << 1 | 1].sum);
////    }
////
////    void build(int l, int r, int rt) {
////        tree[rt].l = l;
////        tree[rt].r = r;
////        tree[rt].reset();
////        if (l == r) {
////            //scanf("%lld", &tree[rt].sum);
////            return;
////        }
////        int mid = (l + r) >> 1;
////        build(l, mid, rt << 1);
////        build(mid + 1, r, rt << 1 | 1);
////        push_up(rt);
////    }
////
/////*
////void push_down_mul(int rt) {
////    if (tree[rt].mul > 1) {
////
////        (tree[rt << 1].mul *= tree[rt].mul) %= mod;
////
////        (tree[rt << 1 | 1].mul *= tree[rt].mul) %= mod;
////
////        (tree[rt << 1 | 1].sum *= tree[rt].mul) %= mod;
////
////        (tree[rt << 1].sum *= tree[rt].mul) %= mod;
////
////        tree[rt].mul = 1;
////    }
////}
////
////void push_down_add(int rt) {
////    if (tree[rt].add) {
////        int l = tree[rt].l;
////        int r = tree[rt].r;
////        int mid = tree[rt].mid();
////
////        (tree[rt << 1].sum += 1ll * (mid - l + 1) * tree[rt].add) %= mod;
////
////        (tree[rt << 1 | 1].sum += 1ll * (r - mid) * tree[rt].add) %= mod;
////
////        (tree[rt << 1 | 1].add += tree[rt].add) %= mod;
////
////        (tree[rt << 1].add += tree[rt].add) %= mod;
////
////        tree[rt].add = 0;
////    }
////}
////*/
////
////    void push_down(int rt) {
////
////        int mid = tree[rt].mid();
////
////        int le = mid - tree[rt].l + 1;
////
////        int ri = tree[rt].r - mid;
////
////        (tree[rt << 1].mul *= tree[rt].mul);
////
////        (tree[rt << 1 | 1].mul *= tree[rt].mul);
////
////        ((tree[rt << 1].add *= tree[rt].mul) += tree[rt].add);
////
////        ((tree[rt << 1 | 1].add *= tree[rt].mul) += tree[rt].add);
////
////
////        ((tree[rt << 1].sum *= tree[rt].mul) += (1ll * le * tree[rt].add));
////
////        ((tree[rt << 1 | 1].sum *= tree[rt].mul) += (1ll * ri * tree[rt].add));
////
////        tree[rt].mul = 1;
////        tree[rt].add = 0;
////
////    }
////
////    void add(int L, int R, int rt, LL val) {
////
////        if (tree[rt].l >= L && tree[rt].r <= R) {
////            (tree[rt].sum += 1ll * tree[rt].range() * val);
////            (tree[rt].add += val);
////            return;
////        }
////        push_down(rt);
////        int mid = tree[rt].mid();
////        if (L <= mid)
////            add(L, R, rt << 1, val);
////        if (R > mid)
////            add(L, R, rt << 1 | 1, val);
////        push_up(rt);
////    }
////
////    void mul(int L, int R, int rt, LL val) {
////
////        if (tree[rt].l >= L && tree[rt].r <= R) {
////            tree[rt].sum *= val;
////            tree[rt].mul *= val;
////            (tree[rt].add *= val);
////            return;
////        }
////        push_down(rt);
////        int mid = tree[rt].mid();
////        if (L <= mid)
////            mul(L, R, rt << 1, val);
////        if (R > mid)
////            mul(L, R, rt << 1 | 1, val);
////        push_up(rt);
////    }
////
////    LL query(int L, int R, int rt) {
////        if (tree[rt].l >= L && tree[rt].r <= R) {
////            return tree[rt].sum;
////        }
////        push_down(rt);
////        int mid = tree[rt].mid();
////        LL ans = 0;
////        if (L <= mid)
////            ans += query(L, R, rt << 1);
////        if (R > mid)
////            ans += query(L, R, rt << 1 | 1);
////        return ans;
////    }

    ll tr[N << 2], mul_tag[N << 2], add_tag[N << 2];
    int sz[N << 2], n;

    void pushdown(int t) {
        tr[t << 1] *= mul_tag[t];
        tr[t << 1 | 1] *= mul_tag[t];
        tr[t << 1] += add_tag[t] * sz[t << 1];
        tr[t << 1 | 1] += add_tag[t] * sz[t << 1 | 1];
        mul_tag[t << 1] *= mul_tag[t];
        mul_tag[t << 1 | 1] *= mul_tag[t];
        add_tag[t << 1] *= mul_tag[t];
        add_tag[t << 1 | 1] *= mul_tag[t];
        add_tag[t << 1] += add_tag[t];
        add_tag[t << 1 | 1] += add_tag[t];
        add_tag[t] = 0;
        mul_tag[t] = 1;
    }

    void pushup(int t) {
        tr[t] = tr[t << 1] + tr[t << 1 | 1];
    }

    void build(int l, int r, int t) {
        tr[t] = add_tag[t] = 0;
        mul_tag[t] = 1;
        sz[t] = r - l + 1;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(l, mid, t << 1);
        build(mid + 1, r, t << 1 | 1);
    }

    void modify1(int L, int R, ll x){
        modify1(1, n, L, R, 1, x);
    }
    void modify2(int L, int R, ll x){
        modify2(1, n, L, R, 1, x);
    }
    void modify3(int L, int R, ll x){
        modify3(1, n, L, R, 1, x);
    }
    void modify1(int l, int r, int L, int R, int t, ll val) {
        pushdown(t);
        if (L > R) return;
        if (l == L && R == r) {
            tr[t] *= val;
            mul_tag[t] *= val;
            add_tag[t] *= val;
            return;
        }
        int mid = (l + r) >> 1;
        if (R <= mid) modify1(l, mid, L, R, t << 1, val);
        else if (L > mid) modify1(mid + 1, r, L, R, t << 1 | 1, val);
        else modify1(l, mid, L, mid, t << 1, val), modify1(mid + 1, r, mid + 1, R, t << 1 | 1, val);
        pushup(t);
    }

    void modify2(int l, int r, int L, int R, int t, ll val) {
        pushdown(t);
        if (L > R) return;
        if (l == L && R == r) {
            tr[t] += sz[t] * val;
            add_tag[t] += val;
            return;
        }
        int mid = (l + r) >> 1;
        if (R <= mid) modify2(l, mid, L, R, t << 1, val);
        else if (L > mid) modify2(mid + 1, r, L, R, t << 1 | 1, val);
        else modify2(l, mid, L, mid, t << 1, val), modify2(mid + 1, r, mid + 1, R, t << 1 | 1, val);
        pushup(t);
    }

    void modify3(int l, int r, int L, int R, int t, ll val) {
        pushdown(t);
        if (L > R) return;
        if (l == L && R == r) {
            tr[t] = -tr[t];
            mul_tag[t] = -mul_tag[t];
            add_tag[t] = -add_tag[t];
            tr[t] -= sz[t];
            add_tag[t]--;
            return;
        }
        int mid = (l + r) >> 1;
        if (R <= mid) modify3(l, mid, L, R, t << 1, val);
        else if (L > mid) modify3(mid + 1, r, L, R, t << 1 | 1, val);
        else modify3(l, mid, L, mid, t << 1, val), modify3(mid + 1, r, mid + 1, R, t << 1 | 1, val);
        pushup(t);
    }

    ll query(int l, int r, int L, int R, int t) {
        pushdown(t);
        if (L > R) return 0ll;
        if (l == L && R == r) return tr[t];
        if (L > R) return 0;
        int mid = (l + r) >> 1;
        if (R <= mid) return query(l, mid, L, R, t << 1);
        if (L > mid) return query(mid + 1, r, L, R, t << 1 | 1);
        return query(l, mid, L, mid, t << 1) + query(mid + 1, r, mid + 1, R, t << 1 | 1);
    }
    ll query(int L, int R) {
        return query(1, n, L, R, 1);
    }


}tree1;

vector<int> e[N];

int fa[N], dep[N], siize[N], son[N];
int dfn[N], bl[N], clk;
void clr() {
    memset(dfn, 0, sizeof dfn);
    memset(siize, 0, sizeof(siize));
    memset(tree1.tr, 0, sizeof(tree1.tr));
    memset(tree1.sz, 0, sizeof(tree1.sz));
    memset(bl, 0, sizeof(bl));
    memset(fa, 0, sizeof(fa));
    memset(dep, 0, sizeof(dep));
    memset(son, 0, sizeof(son));
    clk = 0;
}
void dfs1(int u, int d, int f) {
    fa[u] = f; dep[u] = d; siize[u] = 1; son[u] = 0;
    for(auto&v:e[u]) {
        if (v != f) {
            dfs1(v, d + 1, u);
            siize[u] += siize[v];
            if (siize[v] > siize[son[u]]) son[u] = v;
        }
    }
}

void dfs2(int u, int t) {
    bl[u] = t; dfn[u] = ++clk;
    if(son[u]) dfs2(son[u], t);
    for(auto&v:e[u]) {
        if (!dfn[v]) {
            dfs2(v, v);
        }
    }
}

void tree_change(int L, int R, int op, LL x) {
    if (op == 2) {
        tree1.modify2(L, R, x);
    } else if (op == 1) {
        tree1.modify1(L, R, x);
    } else {
        tree1.modify3(L, R, x);
    }
}

void change(int u, int v, int opt, ll val) {
    int f1 = bl[u], f2 = bl[v];
    while (f1 != f2) {
        if (dep[f1] < dep[f2]) {
            swap(f1, f2);
            swap(u, v);
        }
        tree_change(dfn[f1], dfn[u], opt, val);
        u = fa[f1];
        f1 = bl[u];
    }
    if (dep[u] > dep[v]) swap(u, v);
    tree_change(dfn[u], dfn[v], opt, val);
}

ll query(int u, int v) {
    int f1 = bl[u], f2 = bl[v]; ll ans = 0;
    while(f1 != f2) {
        if(dep[f1] < dep[f2]) {
            swap(f1, f2);
            swap(u, v);
        }
        ans += tree1.query(dfn[f1], dfn[u]);
        u = fa[f1]; f1 = bl[u];
    }
    if(dep[u] > dep[v]) {
        swap(u, v);
    }
    ans += tree1.query(dfn[u], dfn[v]);
    return ans;
}
int main() {
    int n;
    while (~scanf("%d", &n)) {
        debug(n);
        clr();
        tree1.n = n;
        tree1.build(1, n, 1);
        for (int i = 0; i <= n; ++i)e[i].clear();
        for (int u = 2, v; u <= n; u++) {
            scanf("%d", &v);
            e[v].push_back(u);
        }
        dfs1(1, 0, 1);
        dfs2(1, 1);
        int q;
        scanf("%d", &q);
        while (q--) {
            int opt, u, v;
            ll val=0;
            scanf("%d%d%d", &opt, &u, &v);
            debug(opt, u, v);
            if (opt == 1 || opt == 2) {
                scanf("%llu", &val);
            }
            if (opt == 4) {
                printf("%llu\n", query(u, v));
            } else {
                change(u, v, opt, val);
            }
        }
    }
    return 0;
}
