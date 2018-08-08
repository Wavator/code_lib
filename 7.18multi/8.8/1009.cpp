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
const int N = 100005;
int v[N],sure[N],vill[N];
vector<int> rev[N];
int fa[N];
int fd(int i){return (i==fa[i])?i:fa[i]=fd(fa[i]);}

int main(){
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int T;
    for (scanf("%d", &T); T--; )
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<=n;++i){
            fa[i]=i;rev[i].clear();
            sure[i]=0;
        }
        for(int i = 1; i <= n; i++) {
            static char wards[20];
            scanf("%d%s", &v[i], wards);
            vill[i]=(wards[0]=='v');
            if(vill[i]){
                rev[v[i]].pb(i);
                fa[i]=fa[fd(v[i])];
            }
        }
        static int que[N],hd,tl;
        hd=tl=0;
        for(int i=1;i<=n;++i)if(!vill[i]){
                int fx=fd(i);
                int fy=fd(v[i]);
                if(fx!=fy)continue;
                que[tl++]=v[i];
                sure[v[i]]=1;
            }
        for(int u;hd!=tl;hd++){
            u=que[hd];
            for(int&v:rev[u]){
                if(!sure[v]){
                    que[tl++]=v;
                    sure[v]=1;
                }
            }
        }
        printf("0 %d\n",hd);
    }
    return 0;
}