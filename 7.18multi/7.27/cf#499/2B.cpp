#include <stdio.h>
int cnt[400];
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    int x;
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        cnt[x]++;
    }
    int ans;
    for (ans = m / n; ans >= 1; --ans) {
        int temp = 0;
        for (int i = 1; i <= 100; i++) {
            temp += cnt[i] / ans;
        }
        if (temp >= n)
            break;
    }
    return !printf("%d\n", ans);
}