#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#define debug(...) fprintf(stderr, __VA_ARGS__), fprintf(stderr, "\n"), fflush(stderr)
#else
#define debug(...) 98
#endif
#define fi first
#define se second
typedef long long ll;;
const ll mod = (ll)1e9+7;
const int N = (int)1e6+10;
ll inv[N], ans;
template <typename T>
class Descartes_treap {
public:
    int stk[N], ls[N], rs[N], vis[N], n, rt;
    pair<T, int> a[N];

    inline void init_big_treap(int _, const T * in) {
        n = _;
        rt = 0;
        for (int i = 1; i <= n; ++i) ls[i] = 0, rs[i] = 0, vis[i] = 0;
        for (int i = 1; i <= n; ++i) a[i].fi = -in[i], a[i].se = i;
    }

    inline void init_small_treap(int _, const T * in) {
        n = _;
        rt = 0;
        for (int i = 1; i <= n; ++i) ls[i] = 0, rs[i] = 0, vis[i] = 0;
        for (int i = 1; i <= n; ++i) a[i].fi = in[i], a[i].se = i;
    }

    inline void build() {
        int top = 0;
        for (int i = 1; i <= n; ++i) {
            int k = top;
            while (k > 0 && a[stk[k - 1]] > a[i]) --k;
            if (k) rs[stk[k - 1]] = i;
            if (k < top) ls[i] = stk[k];
            stk[k++] = i;
            top = k;
        }
        for (int i = 0; i <= n; ++i) vis[ls[i]] = vis[rs[i]] = 1;
        for (int i = 0; i <= n; ++i) if (vis[i] == 0) rt = i;
    }

    int dfs(int u) {
        int sz = 1;
        if (ls[u]) sz += dfs(ls[u]);
        if (rs[u]) sz += dfs(rs[u]);
        (ans *= inv[sz]) %= mod;
        return sz;
    }
    void print(int u) {
        if (ls[u]) print(ls[u]);
        cerr << a[u].first << ' ';
        if (rs[u]) print(rs[u]);
    }
};

Descartes_treap<int> treap;
int a[N];
int main() {
    inv[1]=1;
    for (int i = 2; i < N; ++i) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    int T;
    for (scanf("%d", &T); T--; ) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        treap.init_big_treap(n, a);
        ans=n*inv[2]%mod;
        treap.build();
        treap.dfs(treap.rt);
        printf("%lld\n", ans);
    }
    return 0;
}
