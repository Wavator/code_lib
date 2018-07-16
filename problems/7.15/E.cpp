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
#define per(i, a, b) for (int (i) = (b) - 1; (i) >= (a); --(i))
#define REP(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
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
class MCMF {
public:
    struct edge {
        int from, to, cap, flow, cost;
        edge(int from = 0, int to = 0, int cap = 0, int flow = 0, int cost = 0): from(from), to(to), cap(cap), flow(flow), cost(cost){}
    };

    static const int N = 2100;
    int n, s, t;
    vector<edge> edges;
    vi G[N];
    bool inq[N];
    int d[N], p[N], a[N];

    void init(int n) {
        this->n = n;
        REP(i, 0, n) G[i].clear();
        edges.clear();
    }
    inline void add_edge(int u, int v, int cap, int cost) { // cost
        G[u].push_back(SZ(edges));
        edges.emplace_back(u, v, cap, 0, cost);
        G[v].push_back(SZ(edges));
        edges.emplace_back(v, u, 0, 0, -cost);
    }
    inline bool bfs(int &flow, int &cost) {
        REP(i, 0, n) d[i] = oo, inq[i] = false;
        d[s] = 0;
        inq[s] = 1;
        p[s] = 0;
        a[s] = oo;
        static queue<int> q;
        for(;!q.empty();q.pop());
        for (q.push(s); !q.empty(); q.pop()) {
            static int u;
            u = q.front();
            inq[u] = 0;
            for (const int&i: G[u]) {
                edge & e = edges[i];
                if (e.cap > e.flow && d[e.to] > d[u] + e.cost) {
                    d[e.to] = d[u] + e.cost;
                    p[e.to] = i;
                    a[e.to] = min(a[u], e.cap - e.flow);
                    if (!inq[e.to]) {
                        q.push(e.to);
                        inq[e.to] = true;
                    }
                }
            }
        }
        if (d[t] == oo) return false;
        flow += a[t];
        cost += d[t] * a[t];
        for (int u = t; u != s; u = edges[p[u]].from) {
            edges[p[u]].flow += a[t];
            edges[p[u] ^ 1].flow -= a[t];
        }
        return true;
    }

    int get_min_cost_flow(int s, int t) {
        int flow = 0, cost = 0;
        for (this->s = s, this->t = t; bfs(flow, cost););
        return cost;
    }

};

MCMF mcmf;

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int n, m;
    while (~scanf("%d%d%*c", &n, &m)) {
        mcmf.init(n * 2);
        rep(i, 0, m) {
            static int u, v, c;
            scanf("%d %d %d%*c", &u, &v, &c);
            mcmf.add_edge(u + n, v, 1, c);
        }
        rep(i, 2, n)
            mcmf.add_edge(i, i + n, 1, 0);
        mcmf.add_edge(1, n + 1, 2, 0);
        mcmf.add_edge(n, n * 2, 2, 0);
        printf("%d\n", mcmf.get_min_cost_flow(1, n * 2));
    }
    return 0;
}