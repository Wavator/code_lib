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
    int n;
    while (scanf("%d",&n) && n) {
        int tans = n;
        int tn = n;

        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                tans -= tans / i;
                while (n % i == 0) n /= i;
            }
        }

        if (n > 1)
            tans -= tans / n;

        int ans = tn - tans - 1;

        printf("%d\n", ans);
    }
    return 0;
}