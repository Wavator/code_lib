#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#define debug(...) fprintf(stderr, __VA_ARGS__), fprintf(stderr, "\n")
#else
#define debug(...) 98
#define cerr if(false)cout
#endif
#define rep(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define per(i, a, b) for (int (i) = (b) - 1; (i) >= (a); --(i))
#define REP(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
#define PER(i, a, b) for (int (i) = (b); i >= (a); --i)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int oo = 0x3f3f3f3f;
const int N = 200005;
vector<int> e[N];

int dfn[N], fin[N], clk, mp[N];

void dfs(int u) {
    dfn[u] = ++clk;
    mp[clk] = u;
    for (const int&v: e[u])
        dfs(v);
    fin[u] = clk;
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int n, Q;
    scanf("%d%d", &n, &Q);
    REP(i, 2, n) {
        static int u;
        scanf("%d", &u);
        e[u].push_back(i);
    }
    REP(i, 1, n) sort(all(e[i]));
    dfs(1);
    rep(q, 0, Q) {
        static int x, y;
        scanf("%d%d", &x, &y);
        if (fin[x] - dfn[x] + 1 < y) puts("-1");
        else printf("%d\n", mp[dfn[x] + y - 1]);
    }
    return 0;
}