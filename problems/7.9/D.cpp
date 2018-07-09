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
const int N = 1005;
const int M = N * N / 2;

struct edge {
    int u, v, w;
    inline bool operator < (const edge &o) const {
        return w < o.w;
    }
};

edge e[M];
int fa[N];
int find(int u) {
    return u == fa[u]? u: fa[u] = find(fa[u]);
}

struct Q {
    vector<int> c;
    int size, cost;
    void read() {
        scanf("%d%d",&size,&cost);
        c.resize(size);
        rep(i,0,size)scanf("%d",&c[i]);
    }
    int use() {
        if (size) {
            int u = find(c[0]);
            rep(i, 1, size){
                int v = find(c[i]);
                fa[v] = u;
            }
        }
        return cost;
    }
};
int n, q;
Q g[10];
int remain[N];
bool used[10];
int ans;
void dfs(int k) {
    if (k == q) {
        int current = 0;
        for(int i = 1; i <= n; ++i) fa[i] = i;
        rep(i,0,q){
            if (used[i]) {
                current += g[i].use();
            }
        }
        rep(i,0,n-1) {
            int u = find(e[remain[i]].u), v = find(e[remain[i]].v), w = e[remain[i]].w;
            if (u != v) {
                fa[u] = v;
                current += w;
            }
        }

        ans = min(ans,current);
        return;
    }
    used[k]=0;
    dfs(k+1);
    used[k]=1;
    dfs(k+1);
}

int x[N], y[N];

inline int sqr(int x) {
    return x * x;
}

inline int cal(int a, int b) {
    return sqr(x[a] - x[b]) + sqr(y[a] - y[b]);
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int T;
    for (scanf("%d",&T); T--;) {
        scanf("%d%d",&n,&q);
        rep(i,0,q) {
            g[i].read();
        }
        for (int i = 1; i <= n; ++i) fa[i] = i;

        rep(i,1,n+1) {
            scanf("%d%d",&x[i],&y[i]);
        }
        int m = 0;
        rep(i,1,n+1) {
            rep(j,i+1,n+1) {
                e[m].u=i;
                e[m].v=j;
                e[m++].w=cal(i,j);
            }
        }
        sort(e,e+m);
        ans=0;
        int cnt=0;
        rep(i,0,m){
            int u=find(e[i].u),v=find(e[i].v),w=e[i].w;
            if(u!=v){
                ans+=w;
                fa[u]=v;
                remain[cnt++]=i;
            }
        }
        dfs(0);
        printf("%d\n",ans);
        if (T)
            puts("");
    }
    return 0;
}