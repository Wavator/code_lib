#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;
const int M = 200020;
struct edge
{
    int y;
    ll w;
    edge * next;
};

inline edge * new_edge() {
    static int top = 0;
    static edge e[M];
    return &e[top++];
}

edge * li[N];

inline void insert(int u, int v, ll w) {
    edge * t = new_edge();
    t->y = v;
    t->w = w;
    t->next = li[u];
    li[u] = t;
}

int n, m;

ll dis[N];

int pre[N];

bool vis[N];

int p[N];

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        scanf("%d%d%lld", &u, &v, &w);
        insert(u, v, w);
        insert(v, u, w);
    }
    const ll inf = 0x3f3f3f3f3f3f3f3f;
    for (int i = 0; i <= n; ++i) {
        dis[i] = inf;
    }
    priority_queue<pair<ll, int> > qqqqqqqqqq;
    qqqqqqqqqq.emplace(dis[1] = 0, 1);
    while (!qqqqqqqqqq.empty()) {
        int u = qqqqqqqqqq.top().second;
        qqqqqqqqqq.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        for (edge * t = li[u]; t; t = t->next) {
            int v = t->y;
            ll c = t->w;
            if (dis[v] > dis[u] + c) {
                pre[v] = u;
                dis[v] = dis[u] + c;
                qqqqqqqqqq.emplace(-dis[v], v);
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (edge * t = li[u]; t; t = t->next) {
            int v = t->y;
            if (pre[u] == v || vis[v])
                continue;
            vis[v] = 1;
            p[v] = u;
            q.push(v);
        }
    }
    if (!vis[1])
    {
        return !printf("impossible");
    }
    int now = 1;
    vector<int> ans;
    while (now) {
        ans.push_back(now);
        now = p[now];
    }
    ans.push_back(0);
    reverse(ans.begin(),ans.end());
    cout << ans.size() << ' ';
    for (auto&v:ans)
        printf("%d ", v);
    puts("");
    return 0;
}
