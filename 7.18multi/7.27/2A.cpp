#include <stdio.h>
char s[128], a[128];
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int n, k;
    scanf("%d%d%s", &n, &k, &s[0]);
    for (int i = 0; i < n; i++)
        a[ s[i] ]++;
    int ans = 0, pre = 0, cnt = 0;
    for (int i = 'a'; i <= 'z'; i++) {
        if (i - pre > 1 && a[i] > 0) {
            ans += i - 96;
            pre = i;
            cnt++;
        }
        if (cnt >= k)
            break;
    }
    if (cnt < k) puts("-1");
    else printf("%d\n", ans);
    return 0;
}