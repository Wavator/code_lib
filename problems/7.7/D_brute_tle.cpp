#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int N = 1000002;
bool is_prime[N];
int prime[N], prime_cnt;
ll k;
inline ll count(ll x) {
    ll res = 1;
    for (int i = 0; i < prime_cnt; ++i) {
        if (prime[i] * prime[i] > x)
            break;
        if (x % prime[i])
            continue;
        int y = 0;
        while (x % prime[i] == 0) {
            y++;
            x /= prime[i];
        }
        res = res * (k * y + 1) % mod;
    }
    if (x != 1)
        res = res * (k + 1) % mod;
    return res;
}

int main() {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < N; ++i) {
        if (is_prime[i]) {
            prime[prime_cnt++] = i;
            for (int j = i * 2; j < N; j += i)
                is_prime[j] = false;
        }
    }
    int T;
    for (scanf("%d", &T); T--; ) {
        ll l, r;
        scanf("%lld%lld%lld", &l, &r, &k);
        ll ans = 0;
        for (ll i = l; i <= r; ++i) {
            ans += count(i);
            if (ans >= mod)
                ans -= mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}