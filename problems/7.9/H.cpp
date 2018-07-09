#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
inline ostream& operator << (ostream&os, const pair<A, B> &v) {
    return os << v.first << ' ' << v.second;
}
template <typename T>
inline ostream& operator << (ostream&os, const vector<T> &v) {
    auto it = v.begin(); os << *it; for (++it; it != v.end(); ++it) os << ' ' << *it;
    return os;
}
#ifdef Wavator
#define debug(...) cerr << #__VA_ARGS__ << " = [ ", _debug(__VA_ARGS__), cerr << "]" << endl;
#else
#define debug(...) 98;
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
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, pii> pip;

const int N = 100002 + 1000000;
const int M = 1000001 * 4;
struct edge {
    int y;
    ll w;
    edge * next;
};
edge e[M];
edge* li[N];
int cnt = 0;

inline void insert(int u, int v, ll w) {
    e[cnt] = (edge){v, w, li[u]};
    li[u] = &e[cnt++];
    e[cnt] = (edge){u, w, li[v]};
    li[v] = &e[cnt++];
}
const ll inf = 1ll<<60;
void dij(int n, int st, ll * dis){

    static bool vis[N];
    fill(vis+1,vis+n+1,false);
    fill(dis+1,dis+n+1,inf);
    priority_queue<pair<ll, int> > q;
    q.emplace(dis[st] = 0, st);
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if(vis[u])
            continue;
        vis[u] = true;
        for(edge*t = li[u]; t; t = t->next) {
            int v = t->y;
            ll w = t->w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.emplace(-dis[v],v);
            }
        }
    }
}



void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    cnt = 0;
    memset(li,0,sizeof(li));
    int nn=n+m;

    rep(i, 0, m) {
        ll cost;
        int id = n + i + 1;
        int size;
        scanf("%lld%d",&cost, &size);
        rep(j, 0, size) {
            static int x;
            scanf("%d", &x);
            insert(id,x,cost);
        }
    }
    static ll d1[N], d2[N];
    dij(nn,1,d1), dij(nn,n,d2);
    ll mx=inf;
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        mx = min(mx, max(d1[i], d2[i]));
    }
    if (mx==inf) {
        puts("Evil John");
        return;
    }
    printf("%lld\n", (mx + 1) / 2);
    vector<int> s;
    for(int i = 1; i <= n; ++i) {
        if (max(d1[i], d2[i]) == mx)
            s.push_back(i);
    }
    auto it = s.begin();
    printf("%d", *it);
    for (++it; it != s.end(); ++it) {
        printf(" %d", *it);
    }
    puts("");
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int T;
    scanf("%d",&T);
    for (int cs = 1; cs <= T; ++cs) {
        printf("Case #%d: ",cs);
        solve();
    }
    return 0;
}
