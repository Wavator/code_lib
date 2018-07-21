#pragma GCC optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#define debug(...) fprintf(stderr, __VA_ARGS__), fprintf(stderr, "\n")
#else
#define debug(...) 99
#endif
#define forn(i, n) for(int i = 0; i < (n); ++i)
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, a, b) for(int i = (a); i <= (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int mod = static_cast<const int>(1e9 + 7);

inline void add(int &x, int y) {
    x += y;
    if (x >= mod) x -= mod;
}

const int maxn = 100005, maxm = 12;
int tdp[maxn][maxm][maxm], dp[maxn][maxm], a[maxn];

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int N, M, K;
    while (~scanf("%d%d%d", &N, &M, &K)) {
        for (int i = 1; i <= N; ++i)
            for (int j = 0; j <= M; ++j) {
                for (int k = 0; k <= K; ++k)
                    tdp[i][j][k] = 0;
            }
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j <= M; ++j)
                dp[i][j] = 0;
        }
        REP(i, 1, N) scanf("%d", &a[i]);
        tdp[1][0][a[1]] = 1;
        for (int i = 1; i <= M; ++i) dp[i][i] = 1;
        dp[1][0] = 1;
        REP(i, 2, N) {
            for (int j = 0; j <= min(i - 1, M); ++j) {
                tdp[i][j][a[i]] = dp[i - 1][j];
                if (j) {
                    for (int k = 1; k <= K; ++k) {
                        if (k != a[i]) {
                            tdp[i][j][k] = tdp[i - 1][j - 1][k];
                        }
                    }
                }
                for (int k = 1; k <= K; ++k) {
                    add(dp[i][j], tdp[i][j][k]);
                    debug("dp[%d][%d] = %d", i, j, dp[i][j]);
                }
            }
        }
        printf("%d\n", dp[N][M]);
    }
    return 0;
}
