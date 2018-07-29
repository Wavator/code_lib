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
    #define debug(...) 0
    #define err(x) 0
#endif
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
const ll mod = (ll)1e9 + 7;
ll pow_mod(ll a, ll b) {
    assert(b >= 0);ll res=1;
    for (a %= mod; b; b >>= 1, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}
const int N = 2002;
struct interval {
    int l, r, w;
    inline bool operator < (const interval &o) const {
        return r < o.r;
    }
};
 
interval inter[N];
int n, m;
 
inline bool check(int md) {
    static bool f[N][N];
    for (int i = 1; i <= n; ++i) fill(f[i], f[i] + m + 1, false);
    for (int i = 1; i <= n; ++i) {
        if (inter[i].w > md) continue;
        if (inter[i].l == 1)
            f[i][0] = true;
    }
    for (int i = 1; i <= n; ++i) {
        if (inter[i].w > md) continue;
        for (int j = 1; j < i; ++j) {
            if (inter[j].r + 1 < inter[i].l) continue;
            if (inter[j].r >= inter[i].l && inter[i].w + inter[j].w > md) continue;
            f[i][inter[j].r] |= f[j][inter[i].l - 1];
        }
        for (int j = 1; j <= m; ++j) f[i][j] |= f[i][j - 1];
        if (f[i][m] && inter[i].r == m) return true;
    }
    return false;
}
 
int main() {
#ifdef Wavator
    freopen("test.in","r",stdin);
#endif
    int T;
    for (scanf("%d", &T); T--; ) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d%d",&inter[i].l,&inter[i].r,&inter[i].w);
        }
        sort(inter + 1, inter + n + 1);
        int l = 0, r = 2001;
        while (l < r) {
            int mid = l + r >> 1;
            if (check(mid))
                r = mid;
            else
                l = mid + 1;
        }
        if (l == 2001) l = -1;
        printf("%d\n", l);
    }
    return 0;
}