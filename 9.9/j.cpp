//while (clock()<=4.9*CLOCKS_PER_SEC)
#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
constexpr db PI = acos(-1), eps = 1e-8;
int pa[505 * 505];

inline int find(int u) {
    return u == pa[u]? u: pa[u] = find(pa[u]);
}

inline bool merge(int u, int v) {
    u=find(u);
    v=find(v);
    if(u==v)return 0;
    pa[u]=v;
    return true;
}

const int N = 505 * 505;
struct bian {
    int u, v, w;
    bool operator < (const bian& o) const {
        return w > o.w;
    }
};//b[N << 1];

vector<int> e[N];

int n, m;

inline int cal(int x,int y) {
    return (x - 1) * n + y;
}

const int LOG = (int)log2(N) + 3;

int fa[N][LOG], dep[N];
inline int LCA(int a,int b){
    if (dep[a] > dep[b]) {
        swap(a,b);
    }
    for (int i = dep[b] - dep[a], j = 0; i > 0;i >>= 1, j++) {
        if (i & 1) {
            b = fa[b][j];
        }
    }
    if (a == b) {
        return a;
    }
    int k;
    for (k = 0; (1 << k) <= dep[a]; k++);
    for (; ~k; k--) {
        if ((1 << k) <= dep[a] && fa[a][k] != fa[b][k]) {
            a = fa[a][k], b = fa[b][k];
        }
    }
    return fa[a][0];
}
void dfs(int u, int f) {
    dep[u] = dep[f] + 1;
    fa[u][0] = f;
    for (int i = 1; i < LOG; ++i) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (auto &v: e[u]) {
        if (v != f) {
            dfs(v, u);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    char lh[3], rh[3];
    int M = n * m;
    int cnm = 0;
    for(int i=1;i<=M;++i)pa[i]=i, cnm |= rand();//return 0;
    vector<bian> b;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1, u, v; j <= m; ++j) {
            scanf("%s%d%s%d", lh, &u, rh, &v);
            if (lh[0] == 'D') {
                b.push_back((bian) {cal(i, j), cal(i + 1, j), u});
            }
            if (rh[0] == 'R') {
                b.push_back((bian) {cal(i, j), cal(i, j + 1), v});
            }
        }
    }
    sort(all(b));
    for(auto&bb:b) {
        int u = bb.u, v = bb.v;
        if (merge(u,v)) {
            e[u].pb(v);
            e[v].pb(u);
        }
    }
    dfs(1, 0);
    int Q;
    for (scanf("%d", &Q); Q--; ) {
        int u, v;
        scanf("%d%d", &u, &v);
        int dx = cal(u, v);
        scanf("%d%d", &u, &v);
        int dy = cal(u, v);
        int l = LCA(dx, dy);
        if (l < 0 || dx < 0 | dy < 0) return 0;
        printf("%d\n", dep[dx] + dep[dy] - 2 * dep[l]);
    }
    return 0;
}
