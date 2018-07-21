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
const int N = 105, M = 10005;

vector <pip> e;

int fa[N];

int find(int u) {
    return u == fa[u]? u: fa[u] = find(fa[u]);
}

int n, m, q;

pii Q[M];

int ans[M];
bool solved[M];
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int cs = 1;
    while (scanf("%d%d%d", &n, &m, &q)) {
        if (n == 0 && m == 0 && q == 0)
            return 0;
        e.resize(m);
        rep(i,0,m){
            scanf("%d%d%d",&e[i].se.fi,&e[i].se.se,&e[i].fi);
        }
        rep(i,0,q) {
            scanf("%d%d",&Q[i].fi,&Q[i].se);
        }
        for(int i=1;i<=n;++i)fa[i]=i;
        sort(all(e));
        memset(solved,false,sizeof(solved));
        rep(i,0,m){
            int u = find(e[i].se.fi), v = find(e[i].se.se), w = e[i].fi;
            if (u != v) {
                fa[u]=v;
                rep(j,0,q){
                    if(!solved[j]){
                        if(find(Q[j].fi)==find(Q[j].se)) {
                            ans[j]=w;
                            solved[j]=true;
                        }
                    }
                }
            }
        }
        if (cs != 1) {
            printf("\n");
        }
        printf("Case #%d\n",cs++);
        rep(i,0,q){
            if(solved[i])printf("%d\n",ans[i]);
            else puts("no path");
        }
    }
    return 0;
}
