#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#define debug(...) fprintf(stderr, __VA_ARGS__);
#else
#define debug(...) 42;
#endif
#define pb push_back
#define mp make_pair
#define SZ(x) (int)(x).size()

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<vector<int> > a(4, vector<int>(n));
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < n; ++j)
            scanf("%d", &a[i][j]);
    }
    vector<pair<int, pair<int, int> > > ans;
    for (int i = 0; i < n; ++i) {
        if (a[0][i] && a[0][i] == a[1][i]) {
            ans.pb(mp(a[0][i], mp(0, i)));
            a[1][i] = 0;
            k--;
        }
        if (a[2][i] && a[2][i] == a[3][i]) {
            ans.pb(mp(a[2][i], mp(3, i)));
            k--;
            a[2][i] = 0;
        }
    }
    if (k == 2 * n)
        return !printf("-1");
    int tot = n << 1;
    while (k) {
#ifdef Wavator
        assert(SZ(ans) <= 20);
#else
        assert(SZ(ans) <= 20000);
#endif
        for (int i = 0; i < tot; ++i) {
            int x = i / n + 1;
            if (x == 1) {
                int y = i % n;
                if (a[x][y]) {
                    if (a[x][y] == a[0][y]) {
                        ans.pb(mp(a[x][y], mp(0, y)));
                        a[x][y] = 0;
                        k--;
                    } else {
                        int nowx, nowy;
                        if (y != 0) {
                            nowy = y - 1;
                            nowx = x;
                        } else {
                            nowy = y;
                            nowx = x + 1;
                        }
                        debug("pos1: %d %d %d %d\n", x, y, nowx, nowy);
                        if (a[nowx][nowy] == 0) {
                            ans.push_back(mp(a[x][y], mp(nowx, nowy)));
                            swap(a[x][y], a[nowx][nowy]);
                        }
                    }
                }
            } else {
                int y = (tot - i - 1) % n;
                if (a[x][y]) {
                    if (a[x][y] == a[3][y]) {
                        ans.pb(mp(a[x][y], mp(3, y)));
                        a[x][y] = 0;
                        k--;
                    }else {
                        int nowx, nowy;
                        if (y == n - 1) {
                            nowx = x - 1;
                            nowy = y;
                        } else {
                            nowx = x;
                            nowy = y + 1;
                        }
                        debug("pos2: %d %d %d %d\n", x, y, nowx, nowy);
                        if (a[nowx][nowy] == 0) {
                            ans.push_back(mp(a[x][y], mp(nowx, nowy)));
                            swap(a[x][y], a[nowx][nowy]);
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", SZ(ans));
    for (auto &ele: ans) {
        printf("%d %d %d\n", ele.first, ele.second.first + 1, ele.second.second + 1);
    }
    return 0;
}