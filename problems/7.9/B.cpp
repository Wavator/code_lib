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

const int N = 100010;
const int M = 200010;

vector<pip> e;
int fa[N];

int find(int u) {
    return u == fa[u]? u: fa[u] = find(fa[u]);
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        db x, y;
        rep(i,0,n) {
            scanf("%lf%lf",&x,&y);
        }
        rep(i,1,n+1) fa[i]=i;
        e.resize(m);
        int sum = 0;
        rep(i,0,m){
            scanf("%d%d%d",&e[i].se.fi,&e[i].se.se,&e[i].fi);
            sum += e[i].fi;
        }
        sort(rall(e));
        int tot = 0;
        rep(i, 0, m){
            int u = find(e[i].se.fi), v = find(e[i].se.se), w = e[i].fi;
            if (u != v){
                fa[u] = v;
                sum -= w;
                tot++;
            }
        }
        printf("%d %d\n",m-tot, sum);
    }
    return 0;
}