#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = (ll)1e9+7;
function<int(ll)> solve = [&] (ll y){
    if(!y)
        return 0;
    ll p = y % mod;
    ll res = p * (p + 1) / 2 + 2ll*solve(y / 2);
    return (int)(res % mod);
};
ll cnt(ll x) {
    return x? x + cnt(x / 2): 0;
}
void gao(ll n) {
    ll l = 0,r = 7e17;
    while(r - l > 1) {
        ll mid = l + r >> 1;
        if(cnt(mid) < n)
            l = mid;
        else r = mid;
    }
    ll xx = cnt(l) + 1;
    r %= mod;
    ll ans = solve(l);
    ans++;
    ll delta = (n - xx) * (r);
    delta %= mod;
    ans += delta;
    ans %= mod;
    printf("%lld\n", ans);
}

int main() {
    int T;
    for (scanf("%d", &T); T--; ) {
        ll n;
        scanf("%lld",&n);
        gao(n);
    }
    return 0;
}
