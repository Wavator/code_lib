/*
 *      Author name: Wavator
 *      Mail: 11612908@mail.sustc.edu.cn
 * */
#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#ifdef Wavator
#define debug(...) fprintf(stderr, __VA_ARGS__), fprintf(stderr, "\n")
#else
#define debug(...) 42
#endif
#define rep(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define per(i, a, b) for (int (i) = (b) - 1; (i) >= (a); --(i))
#define REP(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
#define PER(i, a, b) for (int (i) = (b); i >= (a); --i)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vp;
const ll mod = (ll)1e9 + 7;
const db eps = 1e-9;
/*
 * head template
 */

const int N = 1000002;

struct edge {
    int y;
    edge * next;
};

edge * li[N];

inline void add_edge(int u, int v) {
    static edge e[N << 1];
    static edge* top = e;
    li[u] = &(*top++ = (edge){v, li[u]});
    li[v] = &(*top++ = (edge){u, li[v]});
}

int dep[N], son[N], sz[N];

void pre_dfs(int u, int fa) {
    dep[u] = dep[fa] + 1;
    sz[u] = 1;
    int v;
    for (edge * t = li[u]; t; t = t->next) {
        v = t->y;
        if (v != fa) {
            pre_dfs(v, u);
            sz[u] += sz[v];
            if (sz[v] > sz[son[u]]) son[u] = v;
        }
    }
}

struct my_map {

    map<int, int> mp;
    int mx;
    void init() {
        mp.clear();
        mx = 0;
    }
    inline void add(int x) {
        mp[dep[x]]++;
        if (mp[dep[x]] > mp[dep[mx]]) mx = x;
        else if (mp[dep[x]] == mp[dep[mx]] && dep[mx] > dep[x]) mx = x;
    }

    inline int query() {
        return dep[mx];
    }

    void print(bool f = false) {
#ifdef Wavator
        debug("mx: %d", mx);
        if (f) {
            for (const auto& p: mp) {
                debug("dep, count: %d %d", p.first, p.second);
            }
        }
#endif
    }

};

my_map mp;

void merge(int x, int fa) {
    mp.add(x);
    for (edge * t = li[x]; t; t = t->next) {
        if (t->y != fa) merge(t->y, x);
    }
}
int ans[N];
void dfs(int u, int fa) {
    edge * t;
    int v;
    for (t = li[u]; t; t = t->next) {
        v = t->y;
        if (v != fa && v != son[u]) {
            dfs(v, u);
            mp.init();
        }
    }

    if (son[u]) dfs(son[u], u);

    for (t = li[u]; t; t = t->next) {
        v = t->y;
        if (v != fa && v != son[u]) {
            merge(v, u);
        }
    }

    mp.add(u);

    //mp.print();

    ans[u] = mp.query() - dep[u];

    //cerr << u << ' ' << mp.query() << ' ' << dep[u] << endl;
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    rep(i, 1, n) {
        static int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
    }
    pre_dfs(1, 0);
    dfs(1, 0);
    REP(i, 1, n) printf("%d\n", ans[i]);
    return 0;
}