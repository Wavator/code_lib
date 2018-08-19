#pragma optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#include "local_debug.h"
#else
#define debug(...)
#endif
#define pb push_back
#define rep(i,a,n) for(int i=(a);i<(n);++i)
#define per(i,a,n) for(int i=(n)-1;i>=(a);--i)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
const ll mod= 998244353;
 
 
ll dist[666][666], G[666][666];
ll tans[666];
signed main() {
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                scanf("%lld",&G[i][j]);
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
            {
                dist[i][j] = G[i][j];
            }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++) {
                for (int j = 1; j <= n; j++) {
                    {
                        if (dist[i][j] > dist[i][k] + dist[k][j])
                            dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        ll ans = 0;
        for(int i = 1;i <= n;i++)
            for(int j = i + 1;j <= n;j++){
                for(int k = 1;k <= n;k++)
                {
                    tans[k] = min(dist[i][k],dist[j][k]);
                }
                sort(tans + 1, tans + n + 1);
                for(int k = 1;k <= n;k++)
                    ans += tans[k]*(n-k)%mod;
            }
        for(int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                ans += G[i][j] * (n * (n - 1) / 2 - 1) % mod;
            }
        }
        printf("%lld\n",ans%mod);
    }
    return 0;
}
