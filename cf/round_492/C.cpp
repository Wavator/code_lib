#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static inline ll dist(ll u, ll v) {
    return u * u + v * v;
}
const int N = 100010;
const ll M = dist(1500000, 0);

ll x[N], y[N];
int idx[N], ans[N], n;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lld%lld", x + i, y + i);
    iota(idx, idx + n, 0);
    while(true) {
        random_shuffle(idx,idx + n);
        ll nowx = 0, nowy = 0;
        for (int i = 0; i < n; i++){
            ll r = idx[i];
            if (dist(nowx + x[r], nowy + y[r]) < dist(nowx - x[r], nowy - y[r])) {
                ans[r] = 1;
                nowx += x[r];
                nowy += y[r];
            }
            else {
                ans[r] = -1;
                nowx -= x[r];
                nowy -= y[r];
            }
        }
        if (dist(nowx, nowy) > M)
            continue;
        for (int i = 0; i < n; ++i)
            printf("%d ", ans[i]);
        puts("");
        break;
    }
    return 0;
}
