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
const int mod = (int)1e9 + 7;
inline int add(int a, int b)
{
    a += b;
    return a >= mod? a - mod: a;
}

inline int sub(int a, int b)
{
    a -= b;
    return a < 0? a + mod: a;
}

inline int mul(ll a, int b)
{
    a *= b;
    return a >= mod? a % mod: a;
}

inline int power(int a, ll b)
{
    int res = 1;
    for (; b; b >>= 1, a = mul(a, a))
        if (b & 1)
            res = mul(res, a);
    return res;
}
const int bs = 2000;
const int N = 100005, K = 50;
int C[N+100][K+20],k;
struct node
{
    int a[K], v[bs + 10], l, r;
    void init(int l, int r)
    {
        this->l = l;
        this->r = r;
    }
    void hen(int x, int y)
    {
        if (x < l)
        {
            x=l-x-1;
            rep(i,0,k)
            {
                a[i] = add(a[i], mul(C[x + i][i], y));
            }
        }
        else
        {
            for(int i=x;i<=r;++i)
            {
                v[i - l] = add(v[i - l], mul(C[i - x + k - 1][k - 1], y));
            }
        }
    }
    int hao(int x) const
    {
        x -= l;
        int res = v[x];
        for(int i=1;i<=k;++i){
            res=add(res,mul(C[x + k - i][k - i], a[i - 1]));
        }
        return res;
    }
}gao[N / bs + 10];

signed main() {
    //C[0][0] = 1;
    for(int i=0;i < N;++i) {
        C[i][0] = 1;
        for(int j = 1; j <= min(i, K - 1); ++j)
            C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
        //cerr << i << endl;
    }
    int n, m;
    scanf("%d%d%d", &n, &m, &k);
    int tot, i;
    int l = 0;
    for (i = tot = 1; l < n; i = l + 1)
    {
        l = min(n, tot * bs);
        gao[tot++].init(i, l);
    }
    //debug(tot);
    while (m--)
    {
        static int op, x, y;
        scanf("%d", &op);
        if (op)
        {
            scanf("%d", &x);
            int belong = (x - 1) / bs + 1;
            //debug(belong);
            printf("%d\n", gao[belong].hao(x));
        }
        else
        {
            scanf("%d%d",&x,&y);
            int belong = (x - 1) / bs + 1;
            //debug(belong);
            while (belong < tot)
            {
                gao[belong].hen(x, y);
                belong++;
            }
        }
    }
    return 0;
}
