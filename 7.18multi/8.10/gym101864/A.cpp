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

int T;
LL x,l,n;

LL gcd(LL x,LL y)
{
    if(x==0)return y;
    if(y==0)return x;
    return gcd(y,x%y);
}

LL cal(LL s,LL lb)
{
    if(lb&1)return 0ll;
    LL sum=0,bs=1,cnt=0;
    while(sum+bs<=s)
    {
        LL ma=2ll*(bs-1);
        if(lb<=ma)cnt++;
        sum+=bs;bs*=2ll;
    }
    s-=sum;lb>>=1;
    if(lb<s)cnt++;
    return cnt;
}

int main()
{
    scan(T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%lld%lld%lld",&x,&l,&n);
        pr(cas);
        LL u,v=n-l+1;
        if(x<l)u=cal(n,x-1)-cal(l-1,x-1);
        else u=cal(n,x-1)+max(0ll,x-l);
        LL t=gcd(u,v);
        printf("%lld/%lld\n",u/t,v/t);
    }
    return 0;
}