#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

void update(int& x, int a)
{
    x += a;
    if (x >= MOD) {
        x -= MOD;
    }
}

int main()
{
    int n, m, l;
    while (scanf("%d%d%d", &n, &m, &l) == 3) {
        std::vector<int> s(n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &s[i]);
        }
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(l + 1));
        dp[0][0] = 1;
        for (int i = 0; i < n; ++ i) {
            std::vector<std::vector<int> > new_dp(m + 1, std::vector<int>(l + 1));
            for (int rmv = 0; rmv <= m; ++ rmv) {
                for (int pre = 0; pre <= l; ++ pre) {
                    if (rmv < m && pre != s[i]) {
                        update(new_dp[rmv + 1][pre], dp[rmv][pre]);
                    }
                    update(new_dp[rmv][s[i]], dp[rmv][pre]);
                }
            }
            dp.swap(new_dp);
        }
        int result = 0;
        for (int pre = 0; pre <= l; ++ pre) {
            update(result, dp[m][pre]);
        }
        printf("%d\n", result);
    }
}
