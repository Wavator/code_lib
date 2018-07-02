#include <bits/stdc++.h>
using namespace std;
const int N = 1000000 + 5000;
typedef long long ll;
const ll mod = 998244353ll;
ll pow_mod(ll a, ll b) {
    assert(b >= 0); ll res = 1;
    for (a %= mod; b; b >>= 1, a = a * a % mod) if (b & 1)res = res * a % mod;
    return res;
}
ll fact[N], inv[N];
inline ll C(ll n, ll m) {
    return ((fact[n] * inv[m] ) % mod) * inv[n - m] % mod;
}
ll n;
ll power_3(ll a) {
    return pow_mod(3, a);
}
int main() {
    fact[0] = fact[1] = 1;
    for (ll i = 1; i < N; ++i)
        fact[i] = fact[i - 1] * i % mod;
    inv[N - 1] = pow_mod(fact[N - 1], mod - 2);
    for(int i = N - 2;~i;--i)
        inv[i] = inv[i + 1] * (i + 1) % mod;
    cin >> n;
    ll ans = 0;
    ll p = 1;
    for (int i = 1; i <= n; ++i) {
        ll x = p*C(n, i)*power_3(i) % mod * power_3(n*(n-i)) % mod;
        ans += x;
        ans %= mod;
        ans += x;
        ans %= mod;
        ans = (ans - p * C(n, i) * 3ll % mod * power_3(n*(n-i)))%mod;
        p *= -1;
    }
    p=1;
    for (int i = 1; i <= n; ++i) {
        ans = (ans + p * C(n, i) * 3ll * pow_mod(power_3(n - i) - 1, n)) % mod;
        p *= -1;
    }
    ans += mod;
    ans %= mod;
    cout << ans << endl;
    return 0;
}