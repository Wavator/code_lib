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
const int N = 1e5 + 100;



struct node {
    int x, y;
    bool operator < (const node &o) const {
        return y < o.y;
    }
    inline int get()const {return (y + 1);}
};

node a[1000];

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int T;
    for (scanf("%d", &T); T--; ) {
        int n, m;
        scanf("%d%d", &n, &m);
        rep(i, 0, n) {
            scanf("%d%d", &a[i].x, &a[i].y);
        }
        sort(a,a+n);
        ll ans = 1;
        int t = 0;
        rep(i, 0, n) {
            ll now = a[i].get();
            if (ans * now > m) break;
            ans *= now;
            ++t;
        }
        printf("%d\n",t);
    }
    return 0;
}