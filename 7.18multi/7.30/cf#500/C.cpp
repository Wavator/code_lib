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

class solver {
public:
    vector<vector<int> > f, pre_mini;
    vector<int> a;
    int n;
    solver(int n): n(n), f(n + 3, vi(2, 0)), pre_mini(n + 3, vi(2, 0)), a(n + 3){};
    void solve() {
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        int kk = n + 1;
        kk >>= 1;
        vector<int> ans;
        const int inf = static_cast<int>(1e9);
        //cerr<<"22";
        for (int j = 1; j <= kk; ++j) {
            //cerr<<j<<' '<<kk<<endl;
            int used=j & 1,temp = used ^ 1;
            pre_mini[j*2-2][used]=inf;
            int bb = j << 1;
            --bb;
            for (int i = bb; i <= n; ++i) {
                //cerr<<i<<' '<<n<<endl;
                f[i][used]=max(0,a[i-1]-a[i]+1);
                if(j>1) {
                    int tmp=f[i-2][temp]+max(0,min(a[i]-1,a[i-1])-a[i-2]+1);
                    tmp=min(tmp,pre_mini[i-3][temp]);
                    f[i][used]+=tmp;
                }
                pre_mini[i][used]=min(f[i][used]+max(0,a[i+1]-a[i]+1),pre_mini[i-1][used]);
            }
            ans.push_back(pre_mini[n][used]);
        }
        //cerr<<"ll";
        for (const int &x: ans) printf("%d ", x);
        puts("");
    }
};

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.tie(nullptr);
    int n;
    cin>>n;
    (new solver(n))->solve();
    return 0;
}