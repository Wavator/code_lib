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

vector<pip> e;
int fa[101];
int find(int u) {
    return u == fa[u]? u: fa[u] = find(fa[u]);
}
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int n;
    while (scanf("%d", &n) && n) {
        e.clear();
        int m;
        e.resize(m = n * (n - 1) / 2);
        rep(i, 0, m) {
            scanf("%d%d%d", &e[i].second.first, &e[i].se.se, &e[i].fi );
        }
        sort(all(e));
        rep(i,0,n+1)fa[i]=i;
        int ans = 0;

        rep(i,0,m) {
            int u = find(e[i].se.se),v=find(e[i].se.fi),w=e[i].fi;
            if (u != v) {
                ans += w;
                fa[u]=v;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}