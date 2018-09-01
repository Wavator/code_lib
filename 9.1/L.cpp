#pragma optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#include "local_debug.h"
#else
#define debug(...)
#endif
#define pb push_back
#define rep(i,a,n) for(int i=(a);i<(n);++i)
#define per(i,a,n) for(int i=(n)-1;i>=(a);--i)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
constexpr db PI = acos(-1), eps = 1e-8;
constexpr ll mod = (ll)1e9 + 7;
ll pow_mod(ll a, ll b) {
    assert(b >= 0);
    ll r = 1;
    for (a %= mod; b; b >>= 1, a = a * a % mod) {
        if (b & 1) {
            r = r * a % mod;
        }
    }
    return r;
}
namespace Quick_in {
    const int LEN = (1 << 21) + 1;
    char ibuf[LEN], *iH, *iT;
    int f, c;
#define gc() (iH==iT?(iT=(iH=ibuf)+fread(ibuf,1,LEN,stdin),(iH==iT?EOF:*iH++)):*iH++)

    inline char nc() {
        while ((c = gc()) <= 32)if (c == -1)return -1;
        return (char) c;
    }

    template<class T>
    inline void sc(T &x) {
        for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
        for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15);
        x *= f;
    }

    template<class T>
    inline bool read(T &x) {
        for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) {
            if (c == -1)return 0;
            if (c == '-') f = -1;
        }
        for (x = c - 48;; x = x * 10 + (c & 15)) { if (!isdigit(c = gc()))break; }
        x *= f;
        return 1;
    }

    inline int gline(char *s) {
        int l = -1;
        for (c = gc(); c <= 32; c = gc())if (c == -1)return c;
        for (; c > 32 || c == ' '; c = gc()) {
            s[++l] = c;
        }
        s[l + 1] = 0;
        return l;
    }

    inline int gs(char *s) {
        int l = -1;
        for (c = gc(); c <= 32; c = gc())if (c == -1)return c;
        for (; c > 32; c = gc()) {
            s[++l] = c;
        }
        s[l + 1] = 0;
        return l;
    }

    template<typename A, typename B>
    inline void sc(A &x, B &y) { sc(x), sc(y); };

    template<typename A, typename B>
    inline bool read(A &x, B &y) { return read(x) && read(y); };
}
using Quick_in::sc;
const ll inf = 1e18;
const int N = 1e5+10;

struct Edge{
    int to,w;
    Edge(){}
    Edge(int to, int w):to(to),w(w){}
};
int n,m,K;
vector<Edge>g[N];
ll dp[N][11];
bool done[N][11];

struct node{
    int u,kk;
    ll d;
    node(){}
    node(int u,int kk, ll d):u(u),kk(kk),d(d){}
    bool operator <(const node& rhs) const {
        return d>rhs.d || d == rhs.d && kk>rhs.kk;
    }
};

priority_queue<node>que;


int main(){
    int T; sc(T);
    while (T--) {
        sc(n, m);
        sc(K);
        for (int i=1; i<=n; ++i) g[i].clear();
        for (int i=1; i<=m; ++i) {
            int u,v,w;
            sc(u, v);
            sc(w);
            g[u].push_back(Edge(v,w));
        }
        for (int i=1; i<=n; ++i) {
            for (int j=0; j<=K; ++j) dp[i][j] = inf;
            for (int j=0; j<=K; ++j) done[i][j] = 0;
        }
        for (int i=0; i<=K; ++i) dp[1][i] = 0;
        while (!que.empty()) que.pop();
        que.push(node(1,0,0));
        int u,kk;
        node now;
        while (!que.empty()) {
            now = que.top(); que.pop();
            u = now.u; kk = now.kk;
            if (done[u][kk]) continue; done[u][kk] = 1;
            for (int i=0; i<g[u].size(); ++i) {
                Edge& e = g[u][i];
                if (dp[e.to][kk]>dp[u][kk] + (ll)e.w) {
                    dp[e.to][kk] = dp[u][kk] + (ll)e.w;
                    que.push(node(e.to,kk,dp[e.to][kk]));
                }
                if (kk<K) {
                    if (dp[e.to][kk+1]>dp[u][kk]) {
                        dp[e.to][kk+1] = dp[u][kk];
                        que.push(node(e.to,kk+1,dp[e.to][kk+1]));
                    }
                }
            }
        }
        ll ans = inf;
        for (int k=0; k<=K; ++k) ans = min(ans,dp[n][k]);
        printf("%lld\n",ans);

    }
    return 0;
}