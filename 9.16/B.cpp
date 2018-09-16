//while (clock()<=4.9*CLOCKS_PER_SEC)
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
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
constexpr ll mod = (ll)1e9 + 7;
constexpr ll OO = 0x3f3f3f3f3f3f3f3f;
ll pow_mod(ll a, ll b) {
    assert(b >= 0);
    ll res = 1;
    for (a %= mod; b; b >>= 1, a = a * a % mod) {
        if (b & 1) {
            res = res * a % mod;
        }
    }
    return res;
}

const int N = 100005, LOG = (int)log2(N) + 1;
struct edge {
    int y, w;
    edge * next;
} e[N << 1], *tp, * li[N];

inline void add_edge(int u, int v, int w) {
    li[u] = &(*tp++ = (edge){v, w, li[u]});
    li[v] = &(*tp++ = (edge){u, w, li[v]});
}

int fa[N][LOG], dep[N];

void init_graph() {
    memset(li, 0, sizeof(li));
    tp = e;
}
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
void lca_dfs(int u, int f) {
    for (int i = 1; i < LOG; ++i) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    int v;
    for (edge * t = li[u]; t; t = t->next) {
        v = t->y;
        if (v != f) {
            dep[v] = dep[u] + 1;
            fa[v][0] = u;
            lca_dfs(v, u);
        }
    }
}
void lca_prepare() {
    memset(fa, 0, sizeof(fa));
    dep[1] = 0;
    lca_dfs(1, 0);
}

int red_ver[N];
bool is_red[N];

ll dp1[N], dp2[N];

void dfs(int u, ll dis) {
    ::dp2[u] = dis;
    for (edge *t = li[u]; t; t = t->next) {
        int v = t->y;
        if (v != fa[u][0]) {
            if (is_red[v]) {
                dp1[v] = 0;
            } else {
                dp1[v] = dp1[u] + t->w;
            }
            dfs(v, dis + t->w);
        }
    }
}
struct question {
    int who;
    void read() {
        scanf("%d", &who);
    }
    bool operator < (const question &o) const {
        if(dp1[who] != dp1[o.who]) {
            return dp1[who] > dp1[o.who];
        }
        return dep[who] > dep[o.who];
    }
}q[1000005];

inline void ckmax(ll &a, ll b) {
    if (a < b) {
        a = b;
    }
}

int main() {
    int T;
    for (scanf("%d", &T); T--;) {
        init_graph();
        int n, m, Q;
        scanf("%d%d%d", &n, &m, &Q);
        rep(i, 0, m) {
            scanf("%d", red_ver + i);
        }
        memset(is_red, false, sizeof(is_red));
        rep(i, 0, m) {
            is_red[red_ver[i]] = true;
        }
        rep(i, 1, n) {
            static int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            add_edge(u, v, w);
        }
        lca_prepare();
        dp1[1] = 0;
        dfs(1, 0ll);
        while (Q--) {
            int num;
            scanf("%d", &num);
            rep(i, 0, num) {
                q[i].read();
            }
            if (num == 1) {
                puts("0");
            } else {
                sort(q, q + num);
                int lca = q[0].who, now_lca;
                ll ans1 = dp1[q[1].who];
                ll dp_dis = 0;
                ll tmp_dis = 0;
                ll ans2 = OO;
                for (int j = 1; j < num && ans2 >= ans1; lca = now_lca) {
                    now_lca = LCA(lca, q[j].who);
                    ans2 = ans1;
                    if (dp1[lca] > dp2[lca] - dp2[now_lca]) {
                        ckmax(dp_dis,
                                     tmp_dis + dp2[lca] - dp2[now_lca]);
                        ckmax(dp_dis,
                                     min(dp1[q[j].who], dp2[q[j].who] - dp2[now_lca]));
                        tmp_dis = tmp_dis + dp2[lca] - dp2[now_lca];
                        if (dp1[q[j].who] > dp2[q[j].who] - dp2[now_lca]) {
                            ckmax(tmp_dis,
                                          dp2[q[j].who] - dp2[now_lca]);
                        }
                    } else {
                        ckmax(dp_dis, tmp_dis + dp1[lca]);
                        tmp_dis = dp1[q[j].who] <= dp2[q[j].who] - dp2[now_lca] ?
                                  -OO :
                                  dp2[q[j].who] - dp2[now_lca];
                    }
                    for (++j; j < num; ++j) {
                        if (LCA(q[j].who, now_lca) == now_lca) {
                            ckmax(
                                    dp_dis,
                                    min(dp2[q[j].who] - dp2[now_lca],
                                        dp1[q[j].who])
                            );
                            if (dp1[q[j].who] > dp2[q[j].who] - dp2[now_lca]) {
                                ckmax(tmp_dis,
                                              dp2[q[j].who] - dp2[now_lca]);
                            }
                        } else {
                            break;
                        }
                    }
                    ans1 = dp_dis;
                    if (j < num) {
                        ckmax(ans1,
                                   dp1[q[j].who]);
                    }
                }
                printf("%lld\n", min(ans2, ans1));
            }
        }
    }
    return 0;
}

