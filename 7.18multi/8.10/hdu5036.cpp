#include <bits/stdc++.h>

using namespace std;
const int N = 1001;
bitset<N> a[N];

int main()
{
    int T;
    scanf("%d", &T);
    for (int ks = 1; ks <= T; ++ks) {
        int n;
        scanf("%d",&n);
        for (int i = 1; i <= n; ++i) {
            a[i].reset();
            a[i][i] = 1;
        }
        for (int i = 1, k, v; i <= n; ++i) {
            scanf("%d", &k);
            for (int j = 0; j < k; ++j) {
                scanf("%d", &v);
                a[v][i] = 1;
            }
        }

        for (int j = 1; j <= n; ++j) {
            for (int i = 1; i <= n; ++i) {
                if (a[i][j]) {
                    a[i] |= a[j];
                }
            }
        }

        double ans = 0;

        for (int i = 1; i <= n; ++i) ans += 1./a[i].count();

        printf("Case #%d: %.5f\n", ks, ans);
    }
    return 0;
}