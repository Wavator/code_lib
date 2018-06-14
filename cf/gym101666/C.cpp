#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll tmp[100], a[52 * 500000];


int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    int cnt = 0;
    int m = 0;
    for (int i = 0; i < n; ++i) {
        ll x;
        scanf("%lld", &x);
        tmp[++cnt] = x;
        for (int j = 1; j < cnt; ++j) {
            tmp[j] = __gcd(tmp[j], x);
        }
        sort(tmp + 1, tmp + 1 + cnt);
        cnt = unique(tmp + 1, tmp + cnt + 1) - tmp - 1;
        for (int j = 1; j <= cnt; ++j)
            a[m++] = tmp[j];
    }

    sort(a, a + m);
    cnt = unique(a, a + m) - a;
    cout << cnt << endl;
    return 0;
}
