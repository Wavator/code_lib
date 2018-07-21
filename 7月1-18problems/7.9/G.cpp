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
const int N = 505;
struct edge {
    int to, dist, a, b;
};
vector<edge> G[N];
int n, m, s, t, cs, d[N];
const int INF = 0x3f3f3f3f;
bool inq[N];

void spfa() {
    memset(d,INF,sizeof(d));
    memset(inq,0,sizeof(inq));
    d[s]=0;
    queue<int> q;   q.push(s);
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        inq[u] = false;
        for (const auto &e: G[u]) {
            int v = e.to, w = e.dist, a = e.a, b = e.b;
            if(a < w) continue;
            int now = d[u] % (a + b);
            if(a - now >= w)
            {
                if(d[v] > d[u] + w)
                {
                    d[v] = d[u] + w;
                    if(!inq[v]) q.push(v);
                }
            }
            else
            {
                int tmp = d[u] + w + (a+b) - now;
                if(d[v] > tmp)
                {
                    d[v] = tmp;
                    if(!inq[v]) q.push(v);
                }
            }
        }
    }
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    cs = 1;
    while(~scanf("%d%d%d%d", &n, &m, &s, &t)) {
        rep(i,0,n+1)
            G[i].clear();
        rep(i,0,m) {
            static int u, v, a, b, t;
            scanf("%d%d%d%d%d", &u, &v, &a, &b, &t);
            G[u].push_back((edge){v, t, a, b});
        }
        spfa();
        printf("Case %d: %d\n", cs++, d[t]);
    }
    return 0;
}
