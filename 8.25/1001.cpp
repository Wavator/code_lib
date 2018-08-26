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
void solve() {
    int n;
    scanf("%d",&n);
    priority_queue<pii> q;
    ll ans = 0;
    ll tans = 0;
    while(n--)
    {
        ll x;
        scanf("%lld",&x);
        if(!q.empty() && x + q.top().fi > 0)
        {
            auto tp = q.top();
            q.pop();
            ans += x + tp.fi;
            tans -= tp.se;
            q.emplace(-x, 0);
        }
        q.emplace(-x, -2);
    }
    printf("%lld %lld\n",ans,tans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        solve();
    }
    return 0;
}
