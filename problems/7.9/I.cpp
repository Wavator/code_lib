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

const int N = 101;

db x[N], y[N], z[N], r[N];

inline db sqr(db x) {
    return x*x;
}

inline double cal(int a,int b) {
    return sqrt(sqr(x[a]-x[b])+sqr(y[a]-y[b])+sqr(z[a]-z[b]))-r[a]-r[b];
}

const int M = N * N;

struct edge {
    int y;
    db w;
    edge * next;
};

int cnt;

edge e[M];

edge* li[N];

inline void insert_edge(int u, int v, db w) {
    e[cnt]=edge{v,w,li[u]};
    li[u]=&e[cnt++];
}

inline void insert(int u, int v, db w) {
    insert_edge(u,v,w);
    insert_edge(v,u,w);
}

db gao(int n, int s, int ed) {
    static db dis[N];
    for(int i=0;i<N;++i)
        dis[i]=1E10;
    static bool vis[N];
    memset(vis,0,sizeof(vis));
    priority_queue<pair<db,int> >q;
    q.push({dis[s]=0,s});
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        if (u == ed)
            return dis[u];
        for (edge *t = li[u]; t; t = t->next) {
            int v = t->y;
            db w = t->w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.emplace(-dis[v],v);
            }
        }
    }
    return 1E10;
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int n, ks = 1;
    while (scanf("%d", &n) && (~n)) {
        n++,++n;
        cnt=0;
        memset(li,0,sizeof(li));
        rep(i,2,n)
            scanf("%lf%lf%lf%lf",&x[i],&y[i],&z[i],&r[i]);
        rep(i,0,2)
            scanf("%lf%lf%lf",&x[i],&y[i],&z[i]);
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++){
                insert(i,j,max(0.0,cal(i,j)));
            }
        printf("Cheese %d: Travel time = %.0f sec\n", ks, gao(n,0,1)*10);
        ks++;
    }
    return 0;
}
