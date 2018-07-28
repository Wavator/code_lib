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
typedef long long ll;
int ans[300][300];
int main() {
#ifdef Wavator
    freopen("test.in","r",stdin);
#endif
    for(int i = 1;i <= 200;i++)
        for(int j = 1;j <= 200;j++){
            if(i == j){
                if(i & 1)
                    ans[i][j] = 1;
                else
                    ans[i][j] = 0;
 
            }
            if(i < j){
                if(i & 1)
                    ans[i][j] = 1;
 
                else
                    ans[i][j] = -1;
 
            }
            if(i >j){
                if(j & 1)
                    ans[i][j] = -1;
 
                else
                    ans[i][j] = 1;
            }
        }
    int T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        if(n & 1){
            puts("impossible");
        }
        else {
            puts("possible");
            for(int i = 1;i <= n;i++){
                for(int j = 1;j <= n;j++){
                    printf("%d%c",ans[i][j],j == n ?'\n':' ');
                }
            }
 
        }
    }
    return 0;
}