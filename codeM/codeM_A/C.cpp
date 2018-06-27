#include <bits/stdc++.h>
using namespace std;
const int N = 100003;
typedef long long ll;
const ll mod = (ll)1e9 + 7;
struct edge {
    int y;
    ll w, l;
    edge * next;
};

inline edge * new_edge() {
    static int top = 0;
    static edge e[N << 1];
    return &e[top++];
}

edge * li[N];

inline void insert(int u, int v, ll w, ll l) {
    edge * t = new_edge();
    t->y = v;
    t->w = w;
    t->l = l;
    t->next = li[u];
    li[u] = t;
}

int n;

int fa[N][17], dep[N];
ll  Y[N], X[N], all;

void dfs(int x, int fa, ll dis1, ll dis2)
{
    X[x] = dis1;
    Y[x] = dis2;
    if (fa){
        ::fa[x][0] = fa;
        for (int i = 0; ::fa[::fa[x][i]][i]; ++i)
            ::fa[x][i + 1] = ::fa[::fa[x][i]][i];
    }

    for (edge * t = li[x]; t; t = t->next){
        int u = t->y;
        if (u == fa) continue;
        dep[u] = dep[x] + 1;
        dfs(u, x, (dis1 + t->w * ((t->l) + !((t->l) % 2)) % mod) % mod, (dis2 + t->w * ((t->l) + (t->l) % 2) % mod) % mod);
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        ll w, l;
        cin >> u >> v >> w >> l;
        insert(u, v, w, l);
        insert(v, u, w, l);
        if (l % 2)
            all = (all + w * (l + 1) % mod);
        else
            all = (all + w * l % mod);
        all %= mod;
    }
    dep[1] = 1;
    dfs(1, 0, 0, 0);
    int m;
    for (cin >> m; m--; ) {
        int x, y;
        cin >> x >> y;
        int lca = LCA(x, y);
        ll temp = (Y[x] + Y[y]) % mod;
        temp = (temp - Y[lca] * 2 % mod + mod) % mod;
        ll ans = (all - temp + mod) % mod;
        temp = (X[x] + X[y]) % mod;
        temp = (temp - X[lca] * 2 % mod + mod) % mod;
        ans = (ans + temp) % mod;
        cout << ans << '\n';
    }
    return 0;
}