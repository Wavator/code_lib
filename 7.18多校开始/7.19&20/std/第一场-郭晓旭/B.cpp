#include <bits/stdc++.h>

int mod;

void update(int& x, int a)
{
    x += a;
    if (x >= mod) {
        x -= mod;
    }
}

int main()
{
    int n;
    while (scanf("%d%d", &n, &mod) == 2) {
        std::vector<int> dp(n + 1);
        dp[0] = 1;
        int sum = 0;
        for (int i = 1; i <= n; ++ i) {
            dp[i] = dp[i - 2] * (i - 1LL) % mod;
            sum = sum * (i - 1LL) % mod;
            if (i >= 3) {
                update(sum, (i - 1LL) * (i - 2) / 2 % mod * dp[i - 3] % mod);
            }
            update(dp[i], sum);
        }
        printf("%d\n", dp[n]);
    }
}
