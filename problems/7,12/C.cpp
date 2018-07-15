#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) 42
#endif
typedef long long ll;
const int N = 20010;

struct edge {
    int y;
    ll w;
    edge * next;
};

edge* li[N];

inline void add_edge(int u, int v, ll w) {
    static edge e[N << 1];
    static edge* top = e;
    li[u] = &(*top++ = (edge){v, w, li[u]});
    li[v] = &(*top++ = (edge){u, w, li[v]});
}


ll dp[4][N];
ll ans;

void dfs(int u, int fa, ll dis) {
    ++dp[dis % 3][u]; ++ans;
    for (edge * t = li[u]; t; t = t->next) {
        int v = t->y;
        if (v == fa)
            continue;
        dfs(v, u, t->w + dis);

        for (int i = 0; i < 3; ++i) {

            for (int j = 0; j < 3; ++j) {

                if ((i + j + (dis % 3)) % 3 == 0) {

                    ans += dp[i][u] * dp[j][v] * 2;

                }

            }

        }

        for (int i = 0; i < 3; ++i) dp[i][u] += dp[i][v];
    }
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        static int u, v;
        static ll w;
        scanf("%d%d%lld", &u, &v, &w);
        add_edge(u, v, w);
    }
    dfs(1, 0, 0);
    ll tot = 1ll * n * n;
    ll gcd = __gcd(tot, ans);
    ans /= gcd;
    tot /= gcd;
    printf("%lld/%lld", ans, tot);
    return 0;
}
