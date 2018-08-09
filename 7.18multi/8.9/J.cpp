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
#define debug(fmt, ...) fprintf(stderr, "func[%s] line %d: %s = " fmt "\n", \
                __func__, __LINE__, #__VA_ARGS__, __VA_ARGS__), fflush(stderr)
#define err(x) cerr << "func[" << __func__ << "] line " << __LINE__ << ": " \
                    << #x << " = " << x << endl << flush
#else
#define debug(...) 99
#define err(x) 99
#endif
//#define int long long
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
const ll mod = (ll)1e9 + 7;
const db eps = 1e-7;
ll pow_mod(ll a, ll b) {
    assert(b >= 0);ll res=1;
    for (a %= mod; b; b >>= 1, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}
const int N = 1002;
char G[N][N];
int lft[N][N], wyn[N][N];
int n, m;
void prework()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)
        scanf("%s", G[i] + 1);
    //rep(i,1,n+1)cerr<<G[i]+1<<endl;
    for (int i = 1; i <= n; i ++) {
        unordered_set<char> St;
        for (int j = 1, k = 1; j <= m; j ++) {
            while (k <= m && !St.count(G[i][k]))
                St.insert(G[i][k++]);
            lft[i][j] = k - j;
            St.erase(G[i][j]);
        }
    }
    for (int j = 1; j <= m; j ++)
    {
        unordered_set<char> St;
        for (int i = 1, k = 1; i <= n; i ++)
        {
            while (k <= n && !St.count(G[k][j]))
                St.insert(G[k++][j]);
            wyn[i][j] = k - i;
            St.erase(G[i][j]);
        }
    }
    //rep(i,1,n+1)rep(j,1,m+1)cerr<<wyn[i][j]<<(char)(j==m?'\n':' ');
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    prework();
    ll ans = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) {
            //cerr << i << ' ' << j << endl;
            deque<int> q;
            for (int k = j + lft[i][j] - 1; k > j; k --) {
                while (!q.empty() && q.back() > wyn[i][k]) q.pop_back();
                q.push_back(wyn[i][k]);
            }
            int p = j + lft[i][j] - 1;
            for (int k = i, l = p; k < i + wyn[i][j]; k++) {
                p = min(p, j + lft[k][j] - 1);
                while (l > p) {
                    if (q.front() == wyn[i][l]) q.pop_front();
                    l--;
                }
                while (l > j && q.front() < k - i + 1) {
                    if (q.front() == wyn[i][l]) q.pop_front();
                    l--;
                }
                ans += l - j + 1;
            }
        }
    cout << ans << endl;
    return 0;
}