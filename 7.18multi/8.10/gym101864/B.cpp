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

const int maxn=10000005;

struct BIT
{
    int s[maxn],maxnum;

    void init(int num)
    {
        for(int i=1;i<=maxnum;i++)s[i]=0;
        maxnum=num;
    }

    void add(int pos)
    {
        while(pos<=maxnum)
        {
            s[pos]++;
            pos+=lowbit(pos);
        }
    }

    int cal(int pos)
    {
        if(pos<=0)return 0;
        int ret=0;
        while(pos>0)
        {
            ret+=s[pos];
            pos-=lowbit(pos);
        }
        return ret;
    }
}al,ar,bl,br;

int T,lsh[maxn],ls[maxn],c,tp[maxn];
pii que[maxn],a[maxn],b[maxn];
int n,m,q,cnt;
LL ans;

int main()
{
    scan(T);
    for(int cas=1;cas<=T;cas++)
    {
        ans=0;
        scan(n);
        for(int i=1;i<=n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            lsh[++cnt]=x;lsh[++cnt]=y;
            a[i]=mp(x,y);
        }
        scan(m);
        for(int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            lsh[++cnt]=x;lsh[++cnt]=y;
            b[i]=mp(x,y);
        }
        scan(q);
        for(int i=1;i<=q;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&z,&x,&y);
            lsh[++cnt]=x;lsh[++cnt]=y;
            que[i]=mp(x,y);tp[i]=z;
        }
        sort(lsh+1,lsh+cnt+1);
        ls[c=1]=lsh[1];
        for(int i=2;i<=cnt;i++)
            if(lsh[i]!=lsh[i-1])ls[++c]=lsh[i];
        al.init(c);ar.init(c);bl.init(c);br.init(c);
        for(int i=1;i<=n;i++)
        {
            int x=lower_bound(ls+1,ls+c+1,a[i].fi)-ls;
            int y=lower_bound(ls+1,ls+c+1,a[i].se)-ls;
            al.add(c-x+1);ar.add(y);
        }
        for(int i=1;i<=m;i++)
        {
            int x=lower_bound(ls+1,ls+c+1,b[i].fi)-ls;
            int y=lower_bound(ls+1,ls+c+1,b[i].se)-ls;
            bl.add(c-x+1);br.add(y);
            ans+=1ll*(n-ar.cal(x-1)-al.cal(c-y));
        }
        pr(cas);printf("%lld\n",ans);
        for(int i=1;i<=q;i++)
        {
            int x=lower_bound(ls+1,ls+c+1,que[i].fi)-ls;
            int y=lower_bound(ls+1,ls+c+1,que[i].se)-ls;
            if(tp[i]==1)
            {
                al.add(c-x+1);ar.add(y);
                ans+=1ll*(m-br.cal(x-1)-bl.cal(c-y));
                n++;
            }else
            {
                bl.add(c-x+1);br.add(y);
                ans+=1ll*(n-ar.cal(x-1)-al.cal(c-y));
                m++;
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}