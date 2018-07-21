#include <cstdio>
typedef long long ll;
ll phi(ll n) {
    ll res = n;
    for (int i = 2; i * i <= n; ++i) if (n % i == 0) {
        res -= res / i;
        while (n % i == 0) n /= i;
    }
    return n == 1? res: res - res / n;
}
int main() {
    ll x; while (~scanf("%lld", &x) && printf("%lld\n", phi(phi(x))));
}