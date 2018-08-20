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
inline int add(int a, int b) {
    a += b;
    return a < mod? a: a - mod;
}
inline int sub(int a, int b) {
    a -= b;
    return a < 0? a + mod: a;
}
inline int mul(ll a, int b) {
    a *= b;
    return a < mod? a: a - a / mod * mod;
}
inline int pow_mod(int a, ll b) {
    int res = 1;
    for(; b; b>>=1,a=mul(a,a))if(b&1)res=mul(res,a);
    return res;
}
inline int inv(int a) {
    a %= mod;
    if (a < 0) a += mod;
    int b = mod, u = 0, v = 1;
    for(;a ;) {
        int t = b / a;
        b -= t * a;swap(a, b);
        u -= t * v;swap(u, v);
    }
    if (b != 1)
        return -1;
    if (u < 0) u += mod;
    return u;
}

int main() {
    int T;
    for (scanf("%d", &T); T--;)
    {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        int ans = sub(add(pow_mod(2,b),mul(pow_mod(2ll,c),(b+d+1))), b + 1);
        printf("%d\n",mul(ans, pow_mod(2, a)));
    }
    return 0;
}
