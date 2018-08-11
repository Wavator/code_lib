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

const int maxn=200005;
int ls[maxn],lsh[maxn],c,pp[maxn];
int a[maxn][2];
int T,n,m;
int gin[maxn],gout[maxn];

bool check(int len)
{
    int lb=1,cnt=0,p2=0;
    for(int i=1;i<=c;i++)
    {
        cnt-=gout[i-1];
        p2=len+ls[i];
        while(lb<=c && ls[lb]<=p2)
        {
            cnt+=gin[lb];
            lb++;
        }
        if(cnt>=m)return true;
    }
    return false;
}

int main()
{
    scan(T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i][0],&a[i][1]);
            lsh[2*i-1]=a[i][0];
            lsh[2*i]=a[i][1];
        }
        lsh[2*n+1]=0,lsh[2*n+2]=1e9+7;
        sort(lsh+1,lsh+2*n+3);
        ls[c=1]=lsh[1];
        for(int i=2;i<=2*n+2;i++)
            if(lsh[i]!=lsh[i-1])ls[++c]=lsh[i];
        for(int i=1;i<=c;i++)gin[i]=gout[i]=0;
        for(int i=1;i<=n;i++)
        {
            a[i][0]=lower_bound(ls+1,ls+c+1,a[i][0])-ls;
            a[i][1]=lower_bound(ls+1,ls+c+1,a[i][1])-ls;
            gin[a[i][0]]++;
            gout[a[i][1]]++;
        }
        int l=0,r=1e9+7;
        //check(1);
        while(r-l>1)
        {
            int mid=(l+r)>>1;
            if(check(mid))r=mid;else l=mid;
        }
        while(r>=0 && check(r))r--;
        pr(cas);
        printf("%d\n",r+1);
    }
    return 0;
}