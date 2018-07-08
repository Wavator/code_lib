#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = (ll)1e9 + 7;
//(n*(n+1)*(2n+1)*(3*n*n+3*n-1))/30

static ll pow_mod(ll a, ll b) {
    ll res = 1;
    for (a %= mod; b; b >>= 1, a = a * a % mod) {
        if (b & 1) {
            res = res * a % mod;
        }
    }
    return res;
}
static const ll inv = pow_mod(30, mod - 2);
inline ll sum(ll n) {
    return ((((n * (n + 1) % mod) * (2ll * n + 1) % mod) * ((3ll * n * n + 3 * n - 1) % mod)) % mod) * inv % mod;
}

ll power(ll x) {
    x *= x;
    x %= mod;
    x *= x;
    return x % mod;
}

ll fact[10];

int cnt;

ll dfs(int idx, ll n) {
    ll res = 0;
    for (int i = idx; i < cnt; ++i) {
        res += power(fact[i]) * sum(n / fact[i]) % mod;
        if (res >= mod)
            res -= mod;
        res -= (power(fact[i]) * dfs(i + 1, n / fact[i])) % mod;
        res += mod;
        if (res >= mod)
            res -= mod;
    }
    return res;
}


int main() {
    int T;
    for (scanf("%d",&T);T--;) {
        ll n;
        scanf("%lld",&n);
        ll m = n;
        cnt = 0;
        for (ll i=2;i * i <= n;++i) {
            if (n % i == 0) {
                fact[cnt++] = i;
                while (n % i == 0) {
                    n /= i;
                }
            }
        }
        if (n != 1)
            fact[cnt++] = n;
        //for(int i = 0;i < cnt; ++i) cerr << fact[i] << ' ';cerr<<endl;
        ll ans = sum(m) - dfs(0, m);
        ans += mod;
        if (ans >= mod)
            ans -= mod;
        printf("%lld\n", ans);
    }
    return 0;
}