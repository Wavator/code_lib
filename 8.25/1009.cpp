#pragma optimize("-O3")
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
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int N = 1e5 + 100;
const ll mod=1e9+7;
vector<int> e[N];
ll dep[N], sz[N];
struct bian {
    int x, y, z;
};
bian bians[100005];
ll dfs(int u, int fa)
{
    sz[u] = 1;
    for (const int &v : e[u])
    {
        if (v == fa) continue;
        dep[v] = dep[u] + 1;
        sz[u] += dfs(v, u);
    }
    return sz[u];
}
int main() {
    ll n;
    while (~scanf("%lld", &n))
    {
        rep(i, 0, n + 1)
        {
            e[i].clear();
        }
        for (int i = 1; i < n; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            e[u].push_back(v);
            e[v].push_back(u);
            bians[i] = (bian){u, v, w};
        }
        dep[1]=0;
        dfs(1, 0);
        ll tot = 0;
        for (int i = 1; i < n; i++) {
            ll u = bians[i].x, v = bians[i].y, w = bians[i].z;
            if (dep[u] < dep[v])
                swap(u, v);
            tot += sz[u] * (n - sz[u]) % mod * w % mod;
        }
        ll ans = 2ll * tot % mod;
        rep(i, 1, n)
        {
            ans = ans * i % mod;
        }
        printf("%lld\n", ans % mod);
    }
    return 0;
}
