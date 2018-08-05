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

const int N = 1 << 15;
int n;
struct node
{
    int a[15];
    bool vis[15];
    int id;
    node()
    {
        memset(a, 0, sizeof(a));
        memset(vis, 0, sizeof(vis));
    }
    inline void init(int j)
    {
        this->id = j;
        rep(i, 0, n){
            scanf("%d", &a[i]);
        }
        sort(a, a + n, greater<int>() );
        memset(vis, 0, sizeof(vis));
    }
    inline node operator + (const node &o) const
    {
        node curr = *this;
        int ma1 = -1, ma2 = -1;
        rep(i, 0, n)
        {
            if(!curr.vis[i])
            {
                ma1 = curr.a[i];
                break;
            }
        }
        rep(i, 0, n)
        {
            if (!o.vis[i])
            {
                ma2 = o.a[i];
                break;
            }
        }
        if (ma1 > ma2)
        {
            per(i, 0, n)
            {
                if (!curr.vis[i] && curr.a[i] > ma2)
                {
                    curr.vis[i] = 1;
                    return curr;
                }
            }
        }
        node curr2 = o;
        per(i, 0, n)
        {
            if (!o.vis[i] && o.a[i] > ma1)
            {
                curr2.vis[i] = true;
                break;
            }
        }
        return curr2;
    }

};

node a[N];

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int T;
    int ks = 1;
    for (scanf("%d", &T); T--; )
    {
        scanf("%d", &n);
        int k = 1 << n;
        rep(i, 0, k) a[i].init(i);
        while (k != 1)
        {
            int p = 0;
            for (int i = 0; i < k; i += 2)
            {
                a[p++] = a[i] + a[i + 1];
            }
            k >>= 1;
        }
        printf("Case #%d: %d\n", ks++, a[0].id + 1);
    }
    return 0;
}