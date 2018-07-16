#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) 42
#endif
typedef long long ll;
const int N = 200010;
int a[N];
int pos[N], cnt[N];

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    int blk = (int)(sqrt((double)n + 0.5));
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = n - 1; ~i; --i) {
        int to = i + a[i];
        if (to >= n) {
            pos[i] = -1;
            cnt[i] = 1;
        } else if (to / blk == i / blk) {
            pos[i] = pos[to];
            cnt[i] = cnt[to] + 1;
        } else {
            pos[i] = to;
            cnt[i] = 1;
        }
        debug("i, a[i], pos[i], cnt[i] = %d %d %d %d\n", i, a[i], pos[i], cnt[i]);
    }
    int Q;
    for (scanf("%d", &Q); Q--; ) {
        static int op, x, y;
        scanf("%d", &op);
        if (op & 1) {
            scanf("%d", &x);
            int res = 0;
            for (; ~x; x = pos[x])
                res += cnt[x];
            printf("%d\n", res);
        } else {
            scanf("%d%d", &x, &y);
            a[x] = y;
            for (int i = x; i >= x / blk * blk; --i) {
                int to = i + a[i];
                if (to >= n) {
                    pos[i] = -1;
                    cnt[i] = 1;
                } else if (to / blk == i / blk) {
                    pos[i] = pos[to];
                    cnt[i] = cnt[to] + 1;
                } else {
                    pos[i] = to;
                    cnt[i] = 1;
                }
            }
        }
    }
    return 0;
}