#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#define debug(...) fprintf(stderr, __VA_ARGS__);
#else
#define debug(...) 42;
#endif
#define pb push_back
#define mp make_pair
#define SZ(x) (int)(x).size()

const int N = 100005;
typedef long long ll;
struct edge {
    int v, w , c;
    edge(int v = 0, int w = 0, int c = 0):v(v), w(w), c(c){}
};

vector<edge> e[N];

int fa[N][18], dep[N];

ll dis[N], disback[N];

void dfs(int u, ll now) {
    debug(u)
    dis[u] = now;
    for (int i = 1; fa[u][i - 1]; ++i)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (auto &b: e[u]) {
        if (fa[u][0] == b.v)
            continue;
        fa[b.v][0] = u;
        dep[b.v] = dep[u] + 1;
        disback[b.v]=disback[u]+b.c;
        dfs(b.v,now+b.w);
    }
}

int LCA(int a,int b){
    if (dep[a] > dep[b])
        swap(a,b);
    for (int i = dep[b] - dep[a], j = 0; i > 0;i >>= 1, j++)
        if (i & 1)
            b = fa[b][j];
    if (a == b)
        return a;
    int k;
    for (k=0;(1<<k)<=dep[a];k++);
    for (;k>=0;k--)
        if ((1<<k)<=dep[a]&&fa[a][k]!=fa[b][k])
            a=fa[a][k],b=fa[b][k];
    return fa[a][0];
}

int main() {
    int T;
    for (scanf("%d", &T); T--; ) {
        int n;
        scanf("%d", &n);
        for(int i=1;i<=n;++i)
            e[i].clear();
        ll ac = 0;
        for (int i = 1; i < n; ++i) {
            int u, v, w, c;
            scanf("%d%d%d%d", &u, &v, &w, &c);
            ac+=w;
            ac+=c;
            e[u].pb(edge(v,w,c));
            e[v].pb(edge(u,c,w));
        }
        memset(fa, 0, sizeof(fa));
        dfs(1, 0);
        int Q;
        for(scanf("%d", &Q); Q--; ) {
            int u, v;
            scanf("%d%d", &u, &v);
            int f = LCA(u, v);
            ll ans = disback[v] - disback[f] + dis[u] - dis[f];
            printf("%lld\n", ac - ans);
        }
    }
    return 0;
}