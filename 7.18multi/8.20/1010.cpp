#pragma optimize("unroll-loops")
#pragma optimize ("-O3")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma
#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#include "local_debug.h"
#else
#define debug(...)
#endif
#define pb push_back
#define rep(i,a,n) for(int i=(a);i<(n);++i)
#define per(i,a,n) for(int i=(n)-1;i>=(a);--i)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int mod = (int)998244353;
typedef long long LL;
auto get_contribution(int a[3]) -> pair<pair<int, int>, pair<int, int>> {
    rep (i, 0, 3) if (a[i] >= INT_MAX / 2) a[i] = INT_MAX;
    return minmax(make_pair(a[1], a[2]), make_pair(a[0], INT_MAX));
}
int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int la, lb; scanf("%d%d", &la, &lb);
        static int a[3], b[3];
        fill(a, a + 3, INT_MAX / 2);
        fill(b, b + 3, INT_MAX / 2);
        rep (i, 0, la) scanf("%d", a+i);
        rep (i, 0, lb) scanf("%d", b+i);
        a[0] += 2; a[1]++;
        b[0] += 2; b[1]++;
        if (a[1] > a[2])
            swap(a[1], a[2]);
        if (b[1] > b[2])
            swap(b[1], b[2]);
        auto va = get_contribution(a), vb = get_contribution(b);
        if (va < vb) {
            puts("1");
        } else if (va > vb) {
            puts("-1");
        } else puts("0");
    }
    return 0;
}
