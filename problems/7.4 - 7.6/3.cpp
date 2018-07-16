#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
struct edge {
    int y;
    edge * next;
};
class Graph {
public:
    static const int N = ::N, M = N << 1;
    edge e[M], *li[N];
    int etop;
    void init() {
        memset(li, 0, sizeof(li));
        etop = 0;
    }
    inline void add_edge(int u, int v) {
        e[etop].y = v;
        e[etop].next = li[u];
        li[u] = &e[etop++];
    }
    inline void add_edges(int u, int v) {
        add_edge(u, v);
        add_edge(v, u);
    }
};

class tree:Graph {
public:
    using Graph::add_edge;
    using Graph::add_edges;
    int count_radius() {
        static int dep[N];
        int mx = -1, pos = -1;
        static function<void(int, int)> dfs = [&](int u, int fa) {
            if(dep[u] > mx)
                mx = dep[pos = u];
            int v;
            edge * t;
            for(t = li[u]; t; t = t->next) {
                v = t->y;
                if (v != fa) {
                    dep[v] = dep[u] + 1;
                    dfs(v, u);
                }
            }
        };
        memset(dep, 0, sizeof(dep));
        dfs(1, -1);
        memset(dep, 0, sizeof(dep));
        dfs(pos, -1);
        return mx;
    }
}t;


class bcc_bridge:Graph {
public:
    using Graph::add_edges;
    int clk, dfn[N], low[N], Father[N], stk[N],top, bcc_cnt, bcc_no[N];
    void Tarjan(int u,int fa) {
        dfn[u] = low[u] = ++clk;
        Father[u] = fa;
        stk[top++] = u;
        int k = 0;
        int v;
        edge * t;
        for(t = li[u]; t; t = t->next) {
            v = t->y;
            if(v == fa && !k) {
                k ++;
                continue;
            }
            if(!low[v]) {
                Tarjan(v, u);
                low[u] = min(low[u], low[v]);
            }
            else
                low[u] = min(low[u], dfn[v]);
        }
        if(dfn[u] == low[u]) {
            bcc_cnt++;
            for(;;) {
                v = stk[--top];
                bcc_no[v] = bcc_cnt;
                if (v == u)
                    break;
            }
        }
    }

    void find_bcc(int n) {
        for(int i = 1; i <= n; i++)
            if(dfn[i] == 0) Tarjan(i, i);
    }

    void re_build(tree &o, int n) { // rebuild a tree.
        for(int i = 1; i <= n; i++) {
            int v = Father[i];
            if(bcc_no[i] != bcc_no[v]) {
                o.add_edges(bcc_no[i], bcc_no[v]);
            }
        }
    }
}e;



int main () {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v; i < m; ++i) {
        scanf("%d%d", &u, &v);
        e.add_edges(u, v);
    }
    e.find_bcc(n);
    e.re_build(t, n);
    printf("%d\n", t.count_radius());
    return 0;
}