#pragma optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
template <typename T> using V = vector<T>;
template <typename T> using pqmax = priority_queue<T>;
template <typename T> using pqmin = priority_queue<T, V<T>, greater<T> >;
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define SZ(x) ((int)(x).size())
#define pb push_back
#define gc getchar
template <typename T> inline bool read(T& x) {
    static int ch;
    static int f;
    for (f = 1, ch = gc(); !isdigit(ch); ch = gc()) {
        if (ch == -1) return false;
        if (ch == 45) f = -1;
    }
    for (x = ch - 48; ;x = x * 10 + ch - 48)
        if (!isdigit(ch = gc())) break;
    x *= f;
}
typedef unsigned long long ll;
typedef unsigned long long ull;
typedef double db;
const ll mod = (ll)1e9+7;
ll pow_mod(ll a, ll b = mod - 2) {
    assert(b >= 0); ll res = 1; for (a %= mod; b; b >>= 1, a = a * a % mod) if (b & 1) res = res * a % mod;
    return res;
}
 
const int N=38;
int p[N],a[N],c[N],m[N],g[N];
int tdp[2][N][N][N][N];
bool dp[N][N][N][N][N];
int ans[1000000];
int xx,yy,zz,ww,mx, n, P,A,C,M;
int anss;
int main(){
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> p[i] >> a[i] >> c[i] >> m[i] >> g[i];
    cin >> P >> A >> C >> M;
    rep(i,0,n+1){
        rep(j,0,P+1)rep(k,0,A+1)rep(l,0,C+1)rep(q,0,M+1){ if(j>=p[i]&&k>=a[i]&&l>=c[i]&&q>=m[i]){
                            dp[i][j][k][l][q]=1;tdp[i&1][j][k][l][q]= (tdp[(i - 1) & 1][j - p[i]][k - a[i]][l - c[i]][q - m[i]] + g[i]);
                        }
                        if(tdp[(i-1)&1][j][k][l][q]>=tdp[i&1][j][k][l][q])tdp[i&1][j][k][l][q]=tdp[(i-1)&1][j][k][l][q],dp[i][j][k][l][q]=0;
                    }
        memset(tdp[1^(i&1)],0,sizeof(tdp[1^(i&1)]));
    }
    rep(j,0,P+1)rep(k,0,A+1)rep(l,0,C+1)rep(q,0,M+1)
                    if(tdp[n&1][j][k][l][q]>mx){
        xx=j,yy=k,zz=l,ww=q,mx=tdp[n&1][j][k][l][q];
    }
    for(int i=n;i>=1;i--){
        if(dp[i][xx][yy][zz][ww]){
            ans[anss++]=i;
            xx-=p[i],yy-=a[i],zz-=c[i],ww-=m[i];
        }
    }
    printf("%d\n", anss);
    rep(i,0,anss)
        printf("%d ",ans[i]-1);
    puts("");
    return 0;
}
