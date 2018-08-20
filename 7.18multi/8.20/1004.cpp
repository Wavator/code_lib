#pragma optimize("-O3")
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
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int mod = (int)998244353;

void re(ll &a, ll &b)
{
    ll g = __gcd(abs(a), b);
    a /= g, b /= g;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--)
    {
        ll a, b, c, a_, b_, c_;
        scanf("%lld%lld%lld%lld%lld%lld", &a, &b, &c, &a_, &b_, &c_);
        ll x = a_ * (c - b) + b_ * (a - c) + c_ * (b - a);
        ll y = a + b + c;
        re(x, y);
        if (y == 1) printf("%lld\n", x);
        else {
            printf("%lld/%lld\n", x, y);
        }
    }
    return 0;
}
