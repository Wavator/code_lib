#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
typedef long long ll;
ll ext_gcd(ll a, ll b, ll &x, ll &y) {
    ll d = a;
    if(b) {
        d = ext_gcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    else {
        x = 1;
        y = 0;
    }
    return d;
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    ll a, b;
    while (~scanf("%lld%lld", &a, &b)) {
        ll x, y;
        ll d = ext_gcd(a, b, x, y);
        if (d != 1) {
            puts("sorry");
        } else {
            while (x <= 0) {
                x += b;
                y -= a;
            }
            printf("%lld %lld\n", x, y);
        }
    }
    return 0;
}