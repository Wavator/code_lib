#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int cnt[N];

inline bool is_sub_task(int x, int y, int z) {
    static int a[3];
    a[0] = x, a[1] = y, a[2] = z;
    do {
        if ((a[0] & 1) && (a[1] & 2) && (a[2] & 4))
            return true;
    } while (next_permutation(a, a + 3));
    return false;
}

inline int two(int x) {
    return x * (x + 1) / 2;
}

inline int three(int x) {
    return (x * x * x + 3 * x * x + 2 * x) / 6;
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    for(int i = 1; i < N; ++i)
        for(int j = i; j < N; j += i)
            cnt[j]++;
    int T, a, b, c, ab, bc, ac, abc;
    for (scanf("%d", &T); T--; ) {
        scanf("%d%d%d", &a, &b, &c);
        ab = __gcd(a, b);
        bc = __gcd(b, c);
        ac = __gcd(a, c);
        abc = __gcd(ab, c);
        a = cnt[a], b = cnt[b], c = cnt[c], ab = cnt[ab], bc = cnt[bc], ac = cnt[ac], abc = cnt[abc];
        int ans = 0;
        static int d[8];
        d[4] = a - ac - ab + abc, d[2] = b - ab - bc + abc, d[1] = c - ac - bc + abc, d[3] = bc - abc, d[5] = ac - abc, d[6] = ab - abc, d[7] = abc;
        for (int i = 1; i < 8; ++i) {
            for (int j = i; j < 8; ++j) {
                for (int k = j; k < 8; ++k) {
                    if (is_sub_task(i, j, k)) {
                        if (i == j && j == k) {
                            ans += three(d[i]);
                        } else if (i == j) {
                            ans += two(d[i]) * d[k];
                        } else if (j == k) {
                            ans += two(d[j]) * d[i];
                        } else if (k == i) {
                            ans += two(d[i]) * d[j];
                        } else {
                            ans += d[i] * d[j] * d[k];
                        }
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}