#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 12888;
int dp[N], x[N], y[N];
int main() {
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &x[i], &y[i]);
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            for (int j = m; j >= x[i]; --j) {
                dp[j] = max(dp[j], dp[j - x[i]] + y[i]);
            }
        }
        printf("%d\n", dp[m]);
    }
    return 0;
}