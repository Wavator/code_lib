#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int N = 100100;
int ans[N];
bool vis[N];
pair<int, int> a[N];
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int T;
    for (scanf("%d", &T); T--; ) {
        memset(vis, 0, sizeof(vis));
        memset(ans, 0, sizeof(ans));
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; ++i)
            scanf("%d%d", &a[i].fi, &a[i].se);
        sort(a, a + m);
        int ptr = 0;
        int head = a[0].fi, pos = a[0].fi;
        for (ptr = 0; ptr < m;) {
            int temp = 1;
            if (pos < a[ptr].fi) pos = a[ptr].fi;
            for (; pos <= a[ptr].second; pos++) {
                while (vis[temp])
                    temp++;
                ans[pos] = temp;
                vis[temp] = 1;
            }
            ptr++;
            for (; head < a[ptr].first; head++)
                vis[ans[head]] = 0;
        }
        for (int i = 1; i < n; i++)
            printf("%d ", ans[i]? ans[i]: 1);
        printf("%d\n",ans[n]? ans[n]: 1);
    }
}