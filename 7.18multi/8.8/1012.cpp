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
const ll mod = (ll)1e9+7;
ll pow_mod(ll a, ll b, ll mod = ::mod) {
    assert(b >= 0);ll res=1;
    for (a %= mod; b; b >>= 1, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}
const long double eps = 1e-8;
const long double g = 9.8;
int a,b,x,y;

int main(){
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int T;
    scanf("%d",&T);
    while (T--){
        scanf("%d%d%d%d",&a,&b,&x,&y);
        x= -x;
        long double gay, sin_, cos_, h, vt, vx, vy, L;
        gay = 1.0 * b / a;
        sin_ = 1.0 * b / (sqrt(1.0 * a * a + 1.0 * b * b));
        cos_ = 1.0*a/(sqrt(1.0*a*a+1.0*b*b));
        h = 1.0 * y - 1.0 * x * gay;
        vt = sqrt(2.0 * g * h);
        vx = vt * sin_;
        vy = vt * cos_;
        L = 1.0 * x / a * sqrt(1.0 * a * a + 1.0 * b * b);
        int ans = 0;
        for(;;) {
            ++ans;
            long double t = 2.0*vy/g/cos_;
            long double X = vx*t + 0.5*g*sin_*t*t;
            vx = vx + g*sin_*t;
            vy = g*cos_*t-vy;
            L -= X;
            if (L < 1.0 + eps)
                break;
        }
        printf("%d\n",ans);
    }
    return 0;
}