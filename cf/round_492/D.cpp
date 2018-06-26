#include <bits/stdc++.h>
using namespace std;
int a[1 << 18];
int main() {
    int n, r;
    scanf("%d%d", &n, &r);
    int k = 1 << n;
    long long sum = 0;
    for (int i = 0; i < k; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    printf("%.8f\n", 1.0 * sum / k);
    for (int i = 0; i < r; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        sum -= a[x];
        a[x] = y;
        sum += a[x];
        printf("%.8f\n", 1.0 * sum / k);
    }
    return 0;
}
