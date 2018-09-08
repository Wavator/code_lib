#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Dinic {
public:
    static const int N = 5010 * 2;
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
        G[u].push_back(e.size());
        e.push_back(edge(v, c));
        G[v].push_back(e.size());
        e.push_back(edge(u, 0));
    }
    inline bool bfs() {
        memset(vis, 0, sizeof(vis[0]) * (n + 1));
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
        for (int &i = cur[x]; i < (int)G[x].size(); i++) {
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
            memset(cur, 0, sizeof(cur[0]) * (n + 1));
            flow += dfs(s, 0x3f3f3f3f);
        }
        return flow;
    }
    void init(int s, int t, int n) {
        this->n = n;
        this->s = s;
        this->t = t;
        for (int i = 0; i <= n; ++i) {
            G[i].clear();
        }
        e.clear();
    }
}mf;

int dg[5010];

int main() {
    //freopen("test.in", "r", stdin);
    int n, m, k;
    for (int kase = 1; ~scanf("%d%d%d", &n, &m, &k); kase ++) {
        int low, up;
        scanf("%d%d", &low, &up);
        int s = 0, t = n + m + 1;
        int S = n + m + 2, T = n + m + 3;
        mf.init(S, T, n + m + 3);
        memset(dg, 0, sizeof dg);
        for (int i = 1; i <= k; i ++) {
            int u, v;
            scanf("%d%d", &u, &v);
            mf.add_edge(u, n + v, 1);
        }
        for (int i = 1; i <= n; i ++) {
            mf.add_edge(s, i, up - low);
            dg[s] -= low;
            dg[i] += low;
        }
        for (int i = 1; i <= m; i ++)
        {
            mf.add_edge(n + i, t, 1);
            dg[n + i] -= low;
            dg[t] += low;
        }
        mf.add_edge(t, s, 0x3f3f3f3f);
        int sum = 0;
        for (int i = 0; i <= n + m + 1; i ++) {
            if (dg[i] > 0) {
                mf.add_edge(S, i, dg[i]);
                sum += dg[i];
            }
            else if (dg[i]) {
                mf.add_edge(i, T, -dg[i]);
            }
        }
        int flow = mf.get_max_flow();
        printf("Case %d: %s\n", kase, flow == sum? "Yes": "No");
    }
    return 0;
}
