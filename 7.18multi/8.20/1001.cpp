#pragma optimize("unroll-loops")
#pragma optimize ("-O3")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma
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
const int mod = (int)998244353;
const int N = 82;
#define int long long
ll dp[N][N][N*N];
signed main() {
    int t;
    for (scanf("%lld", &t); t--; )
    {
        int n, m, mod;
        scanf("%lld%lld%lld", &n, &m, &mod);
        dp[1][1][1] = n * m;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                for (int k = 1; k <= i * j; ++k)
                {
                    if (i == 1 && j == 1)
                        break;
                    if (k <= i * j)
                        dp[i][j][k] += dp[i][j][k - 1] * (i * j - k + 1) % mod;
                    if (i > 1)
                    {
                        dp[i][j][k] += dp[i - 1][j][k - 1] * (n - i + 1) * j % mod;
                    }
                    if (j > 1)
                    {
                        dp[i][j][k] += dp[i][j - 1][k - 1] * (m - j + 1) * i % mod;
                    }
                    dp[i][j][k] %= mod;
                }
            }
        }
        printf("%lld\n", dp[n][m][n * m]);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                for (int k = 1; k <= n * m; ++k)
                {
                    dp[i][j][k] = 0;
                }
            }
        }
    }
    return 0;
}
