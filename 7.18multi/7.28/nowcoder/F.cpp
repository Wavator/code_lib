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
    #define debug(fmt, ...) fprintf(stderr, "%s: %s = " fmt "\n", \
                __func__, #__VA_ARGS__, __VA_ARGS__), fflush(stderr)
#else
    #define debug(...) 99
#endif
const int S = 2004;
class solver {
public:
    int lc[S], lr[S];
    char a[S][S];
    int n, m;
    solver(){}
    void init(int n, int m){
        this->n = n;
        this->m = m;
        rep(i, 1, n + 1)
            scanf("%s",a[i]+1);
    }
    void solve() {
        rep(i, 1, n + 1){
            if (a[i][1]!=a[i][m]){
                puts("0");
                return;
            }
        }
        rep(i, 1, m + 1){
            if (a[1][m]!=a[n][m]){
                puts("0");
                return ;
            }
        }
        int N = n / 2;
        int M = m / 2;
        rep(i, 1, n + 1) {
            int now = 1;
            while (now < M && a[i][now + 1] == a[i][m - now])
                now++;
            lr[i] = now;
        }
        rep(i, 1, m + 1){
            int now = 1;
            while (now<N&&a[now+1][i]==a[n-now][i])now++;
            lc[i] = now;
        }
        int mi1 =1;
        while (mi1<N&&lr[mi1]==M&&lr[n-mi1+1]==M)mi1++;
        int mi2 =1;
        while (mi2<M&&lc[mi2]==N&&lc[m-mi2+1]==N)mi2++;
        for (int i=N-1;i>=1;i--){
            lr[i] = min(min(lr[i],lr[i+1]),lr[n-i+1]);
        }
        for (int i=M-1;i>=1;i--){
            lc[i] = min(min(lc[i],lc[i+1]),lc[m-i+1]);
        }
        int ans =0;
        for (int i=mi1;i>1;i--) for (int j=mi2;j>1;j--){
                if (lr[i]>=j-1&&lc[j]>=i-1){
                    ans++;
                }
            }
        printf("%d\n",ans);
    }
};
 
solver sol;
 
int main(){
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int T;
    scanf("%d",&T);
    while (T--){
        int n, m;
        scanf("%d%d", &n, &m);
        sol.init(n, m);
        sol.solve();
    }
    return 0;
}