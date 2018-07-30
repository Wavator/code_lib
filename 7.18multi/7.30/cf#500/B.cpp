#pragma optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i,a,n) for(int i=(a);i<(n);++i)
#define per(i,a,n) for(int i=(n)-1;i>=(a);--i)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
#ifdef Wavator
    #define debug(fmt, ...) fprintf(stderr, "func[%s]: %s = " fmt "\n", \
                __func__, #__VA_ARGS__, __VA_ARGS__), fflush(stderr)
    #define err(x) cerr << "func[" << __func__ << "]: " \
                    << #x << " = " << x << endl << flush
#else
    #define debug(...) 0
    #define err(x) 0
#endif
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;


const int N=400005;

int n, m, q;

vector<int>G[N];
bool vis[N];
inline void dfs(int u) {
    vis[u]=1;
    for(int i=0;i<G[u].size();++i) {
        int v=G[u][i];
        if(!vis[v])
            dfs(v);
    }
}
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.tie(nullptr);
    cin >> n >> m >> q;
    for(int i=1;i<=q;++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v + n), G[v + n].push_back(u);
    }
    int k = n + m;
    int ans = -1;
    for(int i = 1; i <= k; ++i) {
        if(!vis[i]) {
            dfs(i);
            ++ans;
        }
    }
    return !printf("%d\n",ans);
}