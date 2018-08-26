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
const int N = 1000000+100;
typedef pair<ll,ll> la;
ll mod;
ll B;
la operator * (const la &a, const la &b) {
    return make_pair((a.first * b.first + a.second * b.second % mod * B)%mod, (a.first * b.second + a.second * b.first)%mod);
}
void operator *= (la &a, const la &b)
{
    la c = a * b;
    a.first = c.first;
    a.second = c.second;
}
la pow_mod(la a, ll b) {
    la res(1,0);
    for(;b;b>>=1,a*=a){
        if(b&1){
            res*=a;
        }
    }
    return res;
}
vector<pii> fact;

void factorize()
{
    fact.clear();
    for (int i = 2; i * i <= B; ++i)
    {
        if (B % i == 0)
        {
            int cnt = 0;
            while (B % i == 0)
            {
                B /= i;
                ++cnt;
            }
            fact.push_back(make_pair(i, cnt));
        }
    }
    if (B > 1)
    {
        fact.push_back(make_pair((int)B, 1));
    }
}

signed main() {
    int T;
    for (scanf("%d", &T); T--; )
    {
        ll a, n;
        scanf("%lld%lld%lld%lld", &a, &B, &n, &mod);
        factorize();
        B = 1;
        ll wa = 1;
        for (const auto &p: fact)
        {
            if (p.second & 1)
            {
                B *= p.first;
            }
            for (int j = 0; j < p.second / 2; ++j)
            {
                wa *= p.first;
            }
        }
        la curr(a, wa);
        printf("1 %lld %lld\n", pow_mod(curr, n).second, B);
    }
    return 0;
}
