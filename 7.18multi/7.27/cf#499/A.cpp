#include <bits/stdc++.h>
using namespace std;
typedef double db;
int a[1000], b[1000];
int n, m;
inline bool ck(db mid) {
    db s = mid;
    db y = (s + m) / a[0];
    s -= y;
    if(s < 0) return false;
    for(int i = 1; i < n; i++) {
        y = (s+m)/b[i];
        s -= y;
        if(s < 0)
            return false;
        y = (s + m)/a[i];
        s -= y;
        if(s < 0)
            return false;
    }
    y = (s + m) / b[0];
    s -= y;
    return s >= 0;
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    db l = 0, r = 2e9;
    for (int t = 0; t <= 100; ++t) {
        db mid=(l + r) / 2;
        if(ck(mid))
            r = mid;
        else
            l = mid;
    }
    if(l > 1e9){
        puts("-1");
        return 0;
    }
    printf("%.9f\n", l);
    return 0;
}