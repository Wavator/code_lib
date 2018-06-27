#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll pow_mod(ll a,ll b) {
    assert(b >= 0);
    ll res = 1;
    for (a %= mod; b; b >>= 1, a = a * a % mod) {
        if (b & 1) {
            res = res * a % mod;
        }
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<ll> fact(n + 1, 0), inv(n + 1, 0), a(n + 1, 0), dp(n + 2, 0);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    fact[0]=inv[0]=1;
    for (int i = 1; i <= n; ++i)
        fact[i] = fact[i - 1] * i % mod;
    for (int i = 1; i <= n; ++i)
        inv[i] = pow_mod(fact[i], mod - 2);
    dp[n+1] = 1;
    for(ll i = n; i; i--) {
        if(a[i] <= n - i && a[i] > 0) {
            for(ll j = i + a[i] + 1;j <= n + 1; j++) {
                ll res = ((fact[j - i - 1] * inv[a[i]]) % mod ) * inv[j - i - 1 - a[i]] % mod;
                (dp[i]+=res*dp[j])%=mod;
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += dp[i];
        if (ans >= mod)
            ans -= mod;
    }
    cout << ans << '\n';
    return 0;
}