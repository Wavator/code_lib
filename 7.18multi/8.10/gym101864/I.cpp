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

set<LL> er;
LL sum,gd;
int T,n;

LL gcd(LL x, LL y)
{
    if(x==0)return y;
    if(y==0)return x;
    return gcd(y,x%y);
}

int main()
{
    LL tmp=1;er.insert(tmp);
    for(int i=1;i<=60;i++)
    {
        tmp*=2ll;
        er.insert(tmp);
    }
    scan(T);
    for(int cas=1;cas<=T;cas++)
    {
        scan(n); gd=sum=0;
        for(int i=1;i<=n;i++)
        {
            LL x;
            scanf("%lld",&x);
            sum+=x;gd=gcd(gd,x);
        }
        sum/=gd;
        pr(cas);
        if(er.find(sum)!=er.end())puts("YES");else puts("NO 1");
    }
    return 0;
}