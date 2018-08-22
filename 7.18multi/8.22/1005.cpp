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
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;
const int N = 100000 + 20;

int a[N], ans[N], cnt[N];
vi e[N];


vi dfs(int u)
{
    vvi sons(1, vi());
    ans[u] = -1;
    for (int i = 1; i * i <= a[u]; ++i)
    {
        if (a[u] % i == 0)
        {
            sons.back().push_back(i);
            if (i * i != a[u])
                sons.back().push_back(a[u] / i);
        }
    }
    for (const auto &v: e[u])
    {
        sons.push_back(dfs(v));
    }
    for (const auto &x: sons)
    {
        for (const auto &v: x)
        {
            cnt[v]++;
        }
    }
    vi res;
    for (const auto &oo: sons)
        res.insert(res.end(), all(oo));
    sort(all(res));
    res.resize(static_cast<unsigned int>(unique(all(res)) - res.begin()));
    for (const auto &x: res)
    {
        if (cnt[x] > 1)
        {
            ans[u] = x;
        }
        cnt[x] = 0;
    }
    return res;
}


int main() {
    int n, x;
    scanf("%d", &n);
    rep(i, 1, n)
    {
        scanf("%d", &x);
        --x;
        e[x].push_back(i);
    }
    rep(i, 0, n)
    {
        scanf("%d", &a[i]);
    }
    dfs(0);
    rep(i, 0, n) printf("%d\n", ans[i]);
    return 0;
}
