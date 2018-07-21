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
static const int up = 0, le = 1, down = 2, ri = 3;
static const int dx[4] = {-1,0,1,0};
static const int dy[4] = {0,-1,0,1};
static const int dback[4] = {2,3,0,1};

static const int N = 101;

vector<pii > e[N * N * 8];

inline void add_edges(int u, int v, int w) {
    e[u].emplace_back(v,w);
}

int dis[N * N * 8];

inline void dij(int st) {
    static const int inf = 0x3f3f3f3f;
    memset(dis,inf,sizeof(dis));
    static bool vis[N * N * 8];
    memset(vis,0,sizeof(vis));
    priority_queue<pii> q;
    q.emplace(dis[st]=0,st);
    while(!q.empty()) {
        int u=q.top().second;
        q.pop();
        if(vis[u])
            continue;
        vis[u]=true;
        for(const auto&ele: e[u]) {
            int v=ele.fi,w=ele.se;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.emplace(-dis[v],v);
            }
        }
    }
}

int g[N][N][4];
int n;
int id[N][N][4][2];

// (r, c, dir, double?)

inline int gao(int r, int c, int dir, int d) {
    int &x = id[r][c][dir][d];
    if (x)
        return x;
    x = ++n;
    return x;
}

int ro, co;

inline bool can(int r, int c, int dir) {
    return r >= 0 && c >= 0 && r < ro && c < co && g[r][c][dir] > 0;
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int r1, c1, r2, c2, ks = 1;
    while (scanf("%d%d%d%d%d%d", &ro, &co, &r1, &c1, &r2, &c2) == 6 && ro) {
        r1--;
        c1--;
        r2--;
        c2--;
        memset(g,0,sizeof(g));
        rep(r,0,ro) {
            rep(c,0,co-1){
                int x;
                scanf("%d",&x);
                g[r][c][ri] = g[r][c+1][le] = x;
            }
            if (r != ro-1){
                rep(c,0,co){
                    int x;
                    scanf("%d",&x);
                    g[r][c][down]=g[r+1][c][up]=x;
                }
            }
        }
        n=0;
        memset(id,0,sizeof(id));
        rep(i,0,ro*co*8+1)e[i].clear();
        rep(d,0,4){
            if(can(r1,c1,d)){
                add_edges(0,gao(r1+dx[d],c1+dy[d],d,1),g[r1][c1][d]*2);
            }
        }
        rep(r,0,ro){
            rep(c,0,co){
                rep(d,0,4){
                    if(can(r,c,dback[d])){
                        rep(nd,0,4){
                            if(can(r,c,nd)){
                                rep(f,0,2){
                                    int nowr = r+dx[nd], nowc = c + dy[nd];
                                    int v = g[r][c][nd], newf = 0;
                                    if (d != nd) {
                                        if (!f)
                                            v += g[r][c][dback[d]];
                                        newf=1;
                                        v += g[r][c][nd];
                                    }
                                    add_edges(gao(r,c,d,f), gao(nowr,nowc,nd,newf),v);
                                }
                            }
                        }
                    }
                }
            }
        }
        dij(0);
        int ans = 0x3f3f3f3f;
        rep(d,0,4){
            if(can(r2,c2,dback[d])){
                rep(f,0,2){
                    int v = dis[gao(r2,c2,d,f)];
                    if (!f){
                        v+=g[r2][c2][dback[d]];
                    }
                    ans=min(ans,v);
                }
            }
        }
        printf("Case %d: ", ks++);
        if (ans == 0x3f3f3f3f)
            puts("Impossible");
        else
            printf("%d\n",ans);
    }
    return 0;
}
