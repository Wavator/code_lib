#include <bits/stdc++.h>
using namespace std;
int dp[1 << 22], C[22];
int main() {
    int M, N;
    scanf("%d%d", &M, &N);
    for ( ;N--; ) {
        int x, y, b;
        scanf("%d%d%d", &x, &y, &b);
        C[x] += b;
        C[y] -= b;
    }
    for (int m = 1; m < (1<<M); ++m) {
        int sum = 0;
        for (int i = 0; i < M; ++i)
            if ((m>>i)&1)
                sum += C[i],
                        dp[m] = max(dp[m], dp[m&~(1<<i)]);
        if (sum == 0) ++dp[m];
    }
    cout << (M - dp[(1 << M) - 1]) << endl;
    return 0;
}
