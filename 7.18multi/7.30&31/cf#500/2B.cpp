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
const ll mod = (ll)1e9 + 7;
ll pow_mod(ll a, ll b) {
    assert(b >= 0);ll res=1;
    for (a %= mod; b; b >>= 1, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}

int a[100100], i, x,f[100100];
int main() {
    int n;
    scanf("%d%d", &n,&x);
    int wa = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (f[a[i]]==1)wa = 1;
        else f[a[i]] = 1;
    }
    if (wa==1)
        return !printf("0\n");
    for (i = 0; i < n; i++) {
        if (f[a[i] & x]&&((a[i]&x)!=a[i]))
            return !printf("1\n");
    }
    for (i = 0; i < n; i++) {
        if (f[a[i] & x] && ((a[i] & x) != a[i]))
            return !printf("2\n");
        else f[a[i] & x] = 1;
    }
    return !printf("-1\n");
}