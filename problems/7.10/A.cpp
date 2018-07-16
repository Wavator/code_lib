#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
typedef long long ll;
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    ll a, b;
    while (~scanf("%lld%lld", &a, &b)) {
        if (a < b)
            swap(a, b);
        a = (a - b) * (1 + sqrt(5)) / 2;
        puts(a ^ b? "1": "0");
    }
    return 0;
}