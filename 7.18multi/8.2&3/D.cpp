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
#define int long long
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
const ll mod = 1000000007;
ll pow_mod(ll a, ll b = mod - 2) {
    assert(b >= 0);ll res=1;
    for (a %= mod; b; b >>= 1, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}

const int N = 100005;

namespace cal
{
    int c[N], n;
    void add(int x)
    {
        for(;x;x-=x&-x)
            c[x]++;
    }
    int query(int x){
        int ret=0;
        for(;x<=n;x+=x&-x)
            ret+=c[x];
        return ret;
    }

    int gao(int *x, int _)
    {
        n = _;
        int res = 0;
        for (int i = 1; i <= n; ++i)
        {
            res += query(x[i]);
            add(x[i]);
        }
        return res;
    }

}

int mi[N << 2], lz[N << 2];

inline void push_up(int rt)
{
    mi[rt] = min(mi[rt << 1], mi[rt << 1 | 1]);
}

inline void push_down(int rt)
{
    if (lz[rt])
    {
        lz[rt << 1] += lz[rt];
        lz[rt << 1 | 1] += lz[rt];
        mi[rt << 1] += lz[rt];
        mi[rt << 1 | 1] += lz[rt];
        lz[rt] = 0;
    }
}


void change(int L, int R, int l, int r, int rt, int add)
{
    if(L > r || R < l)
        return;
    if (l >= L &&r <= R)
    {
        mi[rt] += add;
        lz[rt] += add;
        return;
    }
    int mid = l + r >> 1;
    push_down(rt);
    if (L <= mid) change(L, R, l, mid, rt << 1, add);
    if (R > mid) change(L, R, mid + 1, r, rt << 1 | 1, add);
    push_up(rt);
}
int n;
int query(int L, int R, int l, int r, int rt)
{
    if(L > r || R < l)
        return INT_MAX;
    if (l >= L && r <= R) return mi[rt];
    int mid = l + r >> 1;
    push_down(rt);
    int res = INT_MAX;
    if (L <= mid) res = min(res, query(L, R, l, mid, rt << 1));
    if (R > mid) res = min(res, query(L, R, mid + 1, r, rt << 1 | 1));
    return res;
}

int a[N];
int mp[N];
signed main()
{
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    scanf("%lld", &n);
    n >>= 1;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", a + i);
        a[i] >>= 1;
        mp[a[i]] = i;
    }
    ll ans = cal::gao(a, n);
    int m = n + 1;
    for (int i = 1; i <= n; ++i) change(i + 1, m, 1, m, 1, 1);
    for (int i = 1; i <= n; ++i)
    {
        ans += query(1, m, 1, m, 1);
        change(1, mp[i], 1, m, 1, 1);
        change(mp[i] + 1, m, 1, m, 1, -1);
    }
    cout << ans << endl;

    return 0;
}