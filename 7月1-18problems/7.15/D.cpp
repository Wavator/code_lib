#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B> inline ostream& operator << (ostream&os, const pair<A, B> &v) {
    return os << v.first << ' ' << v.second;
}
template <typename T> inline ostream& operator << (ostream&os, const vector<T> &v) {
    for (auto it = v.begin(); it != v.end(); os << (*it++)) if (it != v.cbegin()) os << ' ';
    return os;
}
#ifdef Wavator
#define debug(...) cerr << #__VA_ARGS__ << " = \n[ ", _debug(__VA_ARGS__), cerr << "]" << endl
#else
#define debug(...) 98
#define cerr if (false) cout
#endif
void _debug(){}
template <typename H, typename...T>
void _debug(H head, T...tail) {
    cerr << head << " ";
    _debug(tail...);
}
#define rep(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int oo = 0x3f3f3f3f;
namespace Dinic {
    const int N = 210 * 2;
    struct edge {
        int to, cap, flow;
        edge(int to, int cap): to(to), cap(cap), flow(0){}
    };

    int n, s, t;

    vector<edge> e;
    vector<int> G[N];

    bool vis[N];

    int d[N];

    int cur[N];

    inline void add_edge(int u, int v, int c) {
        G[u].push_back(SZ(e));
        e.push_back(edge(v, c));
        G[v].push_back(SZ(e));
        e.push_back(edge(u, 0));
    }

    inline bool bfs() {
        memset(vis, 0, sizeof vis);
        static int q[N];
        int head = 0, tail = 0;
        q[tail++] = s;
        d[s] = 0, vis[s] = true;
        for (; tail ^ head;) {
            int u = q[head++];
            for (const int &x: G[u]) {
                edge & now = e[x];
                if (!vis[now.to] && now.cap > now.flow) {
                    vis[now.to] = true;
                    d[now.to] = d[u] + 1;
                    q[tail++] = now.to;
                }
            }
        }
        return vis[t];
    }

    int dfs(int x,int a) {
        if (x == t || a == 0)return a;
        int flow = 0, f;
        for (int &i = cur[x]; i < G[x].size(); i++) {
            edge &now = e[G[x][i]];
            if (d[x] + 1 == d[now.to] && (f = dfs(now.to, min(a, now.cap - now.flow))) > 0) {
                now.flow += f;
                e[G[x][i] ^ 1].flow -= f;
                flow += f;
                a -= f;
                if (a == 0) break;
            }
        }
        return flow;
    }

    int get_max_flow() {
        int flow = 0;
        for (;bfs();) {
            memset(cur, 0, sizeof(cur));
            flow += dfs(s, oo);
        }
        return flow;
    }

    void init(int s, int t, int n) {
        Dinic::n = n;
        Dinic::s = s;
        Dinic::t = t;
        for (int i = 0; i <= n; ++i) {
            G[i].clear();
        }
        e.clear();
    }
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int n, m, s, t;
    while (~scanf("%d%d%d%d", &n, &m, &s, &t)) {
        Dinic::init(s, t + n, n * 2);
        rep(i, 1, n + 1) {
            static int c;
            scanf("%d", &c);
            Dinic::add_edge(i, i + n, c);
        }
        rep(i, 0, m) {
            static int u, v;
            scanf("%d%d", &u, &v);
            Dinic::add_edge(u + n, v, oo);
            Dinic::add_edge(v + n, u, oo);
        }
        printf("%d\n", Dinic::get_max_flow());
    }
    return 0;
}
