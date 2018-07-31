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


int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> val(2*n);
    rep(i, 0, 2 * n) cin >> val[i];
    sort(all(val));
    ll ans=(ll)1e18;
    for(int i=0;i<n;++i) {
        if(!i)
            ans = min(ans,1ll * (val[n - 1]-val[0])*(val.back()-val[n]));
        else
            ans = min(ans,1ll * (val[i + n -1] - val[i])*(val.back()-val[0]));
    }
    cout << ans << endl;
    return 0;
}