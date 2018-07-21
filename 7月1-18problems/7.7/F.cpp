#include <bits/stdc++.h>
using namespace std;
const int N = 505;

int tdp[N][N], dp[N]; // tdp(i, j) from [i, j], the maximum amount of truth. dp(i): first i position.

int main() {
    int n;
    while (~scanf("%d",&n)) {
        memset(tdp,0,sizeof(tdp));
        memset(dp,0,sizeof(dp));
        for (int i = 0, a, b; i < n; ++i) {
            scanf("%d%d", &a, &b);
            if (n - a - b > tdp[a + 1][n - b])
                tdp[a + 1][n - b]++; 
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                dp[i] = max(dp[i], dp[j - 1] + tdp[j][i]);
            }
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}