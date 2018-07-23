#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
vector<pair<pair<int,int>, int>> v;
int main() {
    int T;
    for (scanf("%d", &T); T--; ) {
        int n;
        scanf("%d", &n);
        v.resize(3u*n);
        for (int i = 0; i < 3 * n; ++i) {
            scanf("%d%d", &v[i].fi.fi, &v[i].fi.se);
            v[i].se = i+1;
        }
        sort(v.begin(), v.end());
        bool f = 0;
        for (int i = 1; i <= 3 * n; ++i) {
            int j = i - 1;
            if (!f) printf("%d", v[j].se), f = 1;
            else printf(" %d", v[j].se);
            if (i % 3 == 0) {
                puts("");
                f = 0;
            }
        }
    }
    return 0;
}