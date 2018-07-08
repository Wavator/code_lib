#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
class DSU {
public:
    vector<int> p, r;
    void init(int n) {
        p.resize(n+1);
        r.resize(n+1);
        for(int i = 0; i <= n; i++) {
            p[i] = i;
            r[i] = 0;
        }
    }
    int find(int x) {
        return p[x] == x? x: p[x] = find(p[x]);
    }
    bool unite(int x,int y) {
        x = find(x);
        y = find(y);
        if(x == y)
            return false;
        if(r[x] < r[y])
            p[x] = y;
        else {
            p[y] = x;
            if(r[x]==r[y])
                r[x]++;
        }
        return true;
    }
    bool same(int x,int y) {
        return find(x)==find(y);
    }
};
DSU dsu;
vector<pair<int,int> >god;
vector<vector<pair<int, int> >> e;
vector<int> c, value;
bool gao(int u, int color) {
    c[u] = 1;
    value[u] = color;
    for (auto &p: e[u]) {
        int v = p.first;
        int w = p.second;
        if (c[v] == 1 && ((color + w + value[v]) % 2) ) {
            return false;
        }
        if (!c[v] && !gao(v, (color + w) & 1))
            return false;
    }
    c[u] = 2;
    return true;
}
int main () {
    int n, m;
    scanf("%d%d", &n, &m);
    dsu.init(n);
    e.assign(n+1,vector<pair<int,int> >());
    for(int i = 0; i < m; ++i) {
        static int u, v, w;
        cin >> u >> v >> w;
        if (~w) {
            e[u].emplace_back(v,w);
            e[v].emplace_back(u,w);
            dsu.unite(u,v);
        } else {
            god.emplace_back(u,v);
        }
    }
    c.assign((unsigned)(n+1),0);
    value.assign(n+1,0);
    for (int i = 1; i <= n; ++i) {
        if (!c[i] && !gao(i, 0))
            return !printf("0\n");
    }
    int ans = 1;
    for (auto &ele: god) {
        if (dsu.unite(ele.first, ele.second)) {
            ans *= 2;
            if (ans >= mod)
                ans -= mod;
        }
    }
    return !printf("%d\n",ans);
}