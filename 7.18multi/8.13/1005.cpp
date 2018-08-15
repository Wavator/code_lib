#include<iostream>
#include<cstdio>
#include<climits>
#include<algorithm>
#include<cstring>
#define fo(a,b,c) for(int a = b; a < c; a++)
using namespace std;
const int maxn = 1000010;


int T;
int m,n,mod;

inline int add(int a, int b) {
    a += b;
    return a >= mod? a - mod: a;
}

inline int sub(int a, int b) {
    a -= b;
    return a < 0? a + mod: a;
}

inline int mul(long long a, int b) {
    a *= b;
    return a - a / mod*mod;
}

int p[maxn],mbs[maxn],f[maxn],ph[maxn];
bool vis[maxn];
//void exgcd(int a,int b,int& d,int& x,int& y)
//{
//    if(!b) { d = a; x = 1; y = 0; }
//    else{ exgcd(b, a%b, d, y, x); y -= x*(a/b); }
//}
int inv[maxn];
void init()
{
    mbs[1] = 1; ph[1] = 1;
    for(int i = 2; i < maxn; i++)
    {
        if (!vis[i]) {p[++p[0]] = i; mbs[i] = -1; ph[i] = i-1;}
        for (int j = 1;j <= p[0] && i * p[j] < maxn; j++)
        {
            vis[i*p[j]] = 1;
            if (i % p[j] == 0) {mbs[i*p[j]] = 0; ph[i*p[j]] = ph[i]*p[j]; break;}
            mbs[i*p[j]] = - mbs[i];
            ph[i*p[j]] = ph[i] * (p[j]-1);
        }
    }

}
int solve(int n, int m)
{

    int ret = 0;
    int s = min(n,m);
    inv[1]=1;
    for (int i=2;i<=s;++i) {
        inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    }
    for(int i = s; i > 0; i--)
    {
        f[i] = mul((n/i),(m/i));
        for(int j = 2*i; j <= s; j += i)
        {
            f[i]=sub(f[i],f[j]);
        }
        //ret = (ret+(ll)(((f[i]*i)%mod)*inv(ph[i]))%mod)%mod;
        ret = add(ret, mul(mul(f[i], i), inv[ph[i]]));
    }
    return ret;
}
int main()
{
    init();
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&mod);
        printf("%d\n", solve(n,m));
    }
    return 0;
}
