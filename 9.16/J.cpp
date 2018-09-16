//while (clock()<=4.9*CLOCKS_PER_SEC)
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#include "local_debug.h"
#else
#define debug(...)
#endif
#define pb push_back
#define rep(i,a,n) for(int i=(a);i<(n);++i)
#define per(i,a,n) for(int i=(n)-1;i>=(a);--i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
constexpr db PI = acos(-1), eps = 1e-8;
constexpr ll mod = (ll)1e9 + 7;
ll pow_mod(ll a, ll b) {
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
    int T;
    for (scanf("%d", &T); T--;) {
        ll a, b, c, d, v, t;
        scanf("%lld%lld%lld%lld%lld%lld", &a, &b, &c, &d, &v, &t);
        ll ans;
        ll mi = min(a, c);
        ans = (t / a + 1) * b + (t / c + 1) * d - 1;
        if (mi > v) {
            ll k, temp;
            if (mi == c) {
                swap(a, c);
                swap(b, d);
            }
            ll cnt = 0;
            for (int i = 1; i <= a; i++) {
                ll p = i * (c - a) % a;
                if (p <= v) cnt++;
                if (a - p <= v) cnt++;
            }
            k = t / (a * c);
            temp = cnt * k;
            for (int i = k * a + 1; i * c <= t; i++) {
                ll p = i * (c - a) % a;
                if (p <= v) temp++;
                if (a - p <= v && i * c + a - p <= t) temp++;
            }
            ans -= t / a + t / c - temp;
        }
        printf("%lld\n", ans);

    }
    return 0;
}
