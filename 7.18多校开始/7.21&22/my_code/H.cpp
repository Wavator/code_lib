#pragma GCC optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#define debug(...) fprintf(stderr, __VA_ARGS__), fprintf(stderr, "\n"), fflush(stderr)
#else
#define debug(...) 99
#endif
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;typedef unsigned long long ull;typedef double db;
template <typename T> using pqmin = priority_queue<T, vector<T>, greater<T> >;template <typename T> using pqmax = priority_queue<T>;
template <typename T> using V = vector<T>;typedef V<int> vi;typedef pair<int,int> pii;
inline char gc() { static char buf[1<<20],*h=buf,*t=buf;return (h==t&&(t=(h=buf)+fread(buf,1,1<<20,stdin),h==t)?-1:*h++);}
template <typename T> inline bool read(T &x){static int f;static char c;for(c=gc(),f=1;!isdigit(c);c=gc()){if(c==-1)return false;else if(c==45)f=-1;}for(x=c-48;isdigit(c=gc());x=x*10+c-48);return x*=f,true; }
template <typename A, typename B> inline bool read(A&x, B&y) {return read(x) && read(y);}
template <typename A, typename B, typename C> inline bool read(A&x,B&y,C&z){return read(x)&&read(y)&&read(z);}
/*
 *
 */
const int N = 400005;

struct edge {
    int y;
    edge * next;
};

edge * li[N];

inline void add_edge(int u, int v) {
    static edge e[N << 1];
    static edge * top = e;
    li[u] = &(*top++=(edge){v, li[u]});
    li[v] = &(*top++=(edge){u, li[v]});
}

ll val[N];
ll dp[N][4][2];

inline void ckmax(ll &x, ll y) {
    if (x < y) x = y;
}

void dfs(int u, int fa) {

    //cerr << u << ' ' << fa << '\n' << flush;

    ll pre[4][3], f[4][3];

    memset(f, 0, sizeof(f));

    memset(pre, 0, sizeof(pre));

    int v;
    for(edge * t = li[u]; t; t = t->next) if ((v = t->y) != fa) {

        dfs(v, u);

        for (int s1 = 0; s1 <= 4; ++s1) {

            for (int s2 = 0; s2 <= 4; ++s2) {

                if (s1 + s2 <= 3) {

                    for (int g1 = 0; g1 <= 2; ++g1) {

                        for (int g2 = 0; g2 < 2; ++g2) {

                            if (g1 + g2 <= 2) {

                                ckmax(f[s1 + s2][g1 + g2], dp[v][s2][g2] + pre[s1][g1]);

                            }

                        }

                    }

                }

            }

        }

        memcpy(pre, f, sizeof(pre));
    }


    for (int i = 0; i < 3; ++i) {

        ckmax(dp[u][i][0], f[i][0]);
        ckmax(dp[u][i][1], f[i][1] + val[u]);


        for (int x = 0; x < 2; ++x) {

            for (int y = x + 1; y < 3; ++y) {

                ckmax(dp[u][i + 1][x], val[u] + f[i][y]);

            }

        }

    }

    ckmax(dp[u][3][0], f[3][0]);
    ckmax(dp[u][3][1], f[3][1] + val[u]);

}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int n;
    read(n);

    for (int i = 1; i <= n; ++i) read(val[i]);

    for (int i = 1, u, v; i < n; ++i) {
        read(u, v);
        add_edge(u, v);
    }
    dfs(1, 0);
    ll ans = 0;
    for (int i = 0; i <= 3; ++i)
        ckmax(ans, dp[1][i][false]);
    cout << ans << '\n';
    return 0;
}
