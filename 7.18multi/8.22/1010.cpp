#pragma optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#include "local_debug.h"
#else
#define debug(...)
#endif
#define pb push_back
#define rep(i,a,n) for(int i=(a),i##_end_=n;i<i##_end_;++i)
#define per(i,a,n) for(int i=(n)-1;i>=(a);--i)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
ll a[10], mx[300], mi[300];
int main()
{
    int T;
    for (scanf("%d", &T); T--; )
    {
        int n, m, K;
        scanf("%d%d%d",&n, &m, &K);
        rep(i, 0, 1 << K)
        {
            mx[i] = -(ll)1e15;
            mi[i] = 0;
        }
        rep(i, 0, n)
        {
            rep(j, 0, K + 1)
            {
                scanf("%lld",&a[j]);
            }
            rep(j, 0, 1 << K)
            {
                ll ret = 0;
                rep(k, 0, K)
                {
                    if((1 << k) & j)
                    {
                        ret += a[k + 1];
                    }
                    else
                    {
                        ret -= a[k + 1];
                    }
                }
                mi[j] = min(mi[j], ret - a[0]);
                mx[j] = max(mx[j], ret + a[0]);
            }
        }
        ll ans = 0;
        rep(i, 0, m)
        {
            rep(j, 0, K + 1)
            {
                scanf("%lld",&a[j]);
            }
            rep(j, 0, 1 << K)
            {
                ll ret = 0;
                rep(k, 0, K)
                {
                    if((1 << k) & j)
                    {
                        ret += a[k + 1];
                    }
                    else
                    {
                        ret -= a[k + 1];
                    }
                }
                ans = max(ans, a[0] + ret + mx[((1 << K) - 1) ^ j]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}