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
const int M = 101*50;
const int INF = 0x3f3f3f3f;
struct edge {
    int u, v, w;
    inline bool operator < (const edge & o) const {
        return w < o.w;
    }
};
edge e[M];

int fa[N], n, m;

int find(int u) {
    return u == fa[u]? u: fa[u] = find(fa[u]);
}

inline int gao(int idx) {
    for(int i=1;i<=n;++i) fa[i] = i;
    int tot = 0;
    int mi = e[idx].w;
    int ma = -1;
    rep(i, idx, m) {
        int u = find(e[i].u), v = find(e[i].v), w = e[i].w;
        if (u != v) {
            fa[u] = v;
            ma = w;
            tot++;
        }
    }
    if (tot==n-1)
        return ma - mi;
    return INF;
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    while (~scanf("%d%d", &n, &m) && (n + m)) {
        rep(i,0,m) {
            scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
        }
        sort(e,e+m);
        int ans = INF;
        rep(i,0,m-n+2){
            ans=min(ans,gao(i));
        }
        if(ans==INF)
            ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}