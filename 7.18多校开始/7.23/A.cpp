#include <stdio.h>
int main() {
    int T, n;
    for (scanf("%d", &T); T--; printf("%lld\n", n % 3 == 0? 1ll * n / 3 * n / 3 * n / 3: (n % 4? -1: 1ll * n / 4 * n / 4 * n / 2))) scanf("%d", &n);
    return 0;
}