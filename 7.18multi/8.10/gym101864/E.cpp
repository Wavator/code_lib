/*****************************************
Author: lizi
Email: lzy960601@outlook.com
*****************************************/

#include<bits/stdc++.h>

using namespace std;

const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;

#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))
#define fi first
#define se second
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int mod=1e9+7;
const int maxn=10000005;
int jc[maxn],ny[maxn];

int mi(int x,int y)
{
    int ret=1;
    while(y>0)
    {
        if(y&1)ret=1ll*ret*x%mod;
        x=1ll*x*x%mod;
        y>>=1;
    }
    return ret;
}

int C(int x,int y)//x>y
{return 1ll*jc[x]*(1ll*ny[x-y]*ny[y]%mod)%mod;}

int T,n,m,k;

int main()
{
    jc[0]=1;
    for(int i=1;i<=maxn-5;i++)jc[i]=1ll*jc[i-1]*i%mod;
    ny[maxn-5]=mi(jc[maxn-5],mod-2);
    for(int i=maxn-6;i>=0;i--)ny[i]=1ll*ny[i+1]*(i+1)%mod;
    scan(T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&k);
        if(k>n){puts("0");continue;}
        int ans=1ll*C(n,k)*mi(m,k)%mod;
        printf("%d\n",ans);
    }
    return 0;
}