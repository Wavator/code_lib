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
unsigned A, B, C;
unsigned x, y, z;
inline unsigned tang()
{
    unsigned t;
    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;
    t = x;
    x = y;
    y = z;
    return z = t ^ x ^ y;
}
unsigned a[10000005];

unsigned long long lcm(unsigned long long a, unsigned long long b)
{
    return a / __gcd(a, b) * b;
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int T;
    scanf("%d",&T);
    rep(t, 0, T)
    {
        int n;
        scanf("%d%u%u%u", &n, &A, &B, &C);
        x = A, y = B, z = C;
        rep(i, 0, n) a[i] = tang();
        int magic = min(n, 100);
        nth_element(a, a + magic, a + n, greater<unsigned>());
        unsigned long long ans = 0;
        rep(i, 0, magic) {
            rep(j, i, magic)
            {
                ans = max(ans, lcm(a[i], a[j]));
            }
        }
        printf("Case #%d: %llu\n", t + 1, ans);
    }
    return 0;
}