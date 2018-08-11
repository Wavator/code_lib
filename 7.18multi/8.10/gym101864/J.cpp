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

int len;

struct segtree
{
    struct node
    {
        int ls,rs,lg,rg,mid,mi,tag;
        void cle(){ls=rs=lg=rg=mid=mi=0;tag=1e9+7;}
        bool one(){return lg==rg;}
        bool judge(int x,int y){return lg==x && rg==y;}
    }tr[200005];
    int k;

    void pushup(int x)
    {
        int ls=tr[x].ls,rs=tr[x].rs;
        if(ls+rs<=0)return;
        tr[x].mi=min(tr[ls].mi,tr[rs].mi);
    }

    void pushdown(int x)
    {
        int ls=tr[x].ls,rs=tr[x].rs;
        if(ls+rs<=0 || tr[x].tag==1e9+7)return;
        int tag=tr[x].tag;
        tr[x].tag=1e9+7;
        tr[ls].tag=min(tag,tr[ls].tag);
        tr[rs].tag=min(tag,tr[rs].tag);
        tr[ls].mi=min(tr[ls].mi, tag);
        tr[rs].mi=min(tr[rs].mi, tag);
        pushup(x);
    }

    void mt(int x,int y)
    {
        tr[k].cle();
        tr[k].lg=x;tr[k].rg=y;
        if(x==y)
        {
            tr[k].mid=x;
            tr[k].mi=len;
            return;
        }
        int mid=(x+y)>>1,t=k;
        tr[k].mid=mid;
        k++;tr[t].ls=k;mt(x,mid);
        k++;tr[t].rs=k;mt(mid+1,y);
        pushup(t);
    }

    void init(int n){k=1;mt(1,n);}

    void add(int now,int x,int y,int nu)
    {
        if(tr[now].judge(x,y))
        {
            tr[now].tag=min(tr[now].tag,nu);
            tr[now].mi=min(tr[now].mi,nu);
            return;
        }
        pushdown(now);
        int mid=tr[now].mid;
        if(x<=mid)add(tr[now].ls,x,min(mid,y),nu);
        if(y>mid)add(tr[now].rs,max(x,mid+1),y,nu);
        pushup(now);
    }

    int query(int now,int x,int y)
    {
        if(tr[now].judge(x,y))return tr[now].mi;
        int mid=tr[now].mid;
        pushdown(now);
        if(y<=mid)return query(tr[now].ls,x,y);
        if(x>mid)return query(tr[now].rs,x,y);
        int u=query(tr[now].ls,x,mid);
        int v=query(tr[now].rs,mid+1,y);
        return min(u,v);
    }
}seg;


char s[200020],t[100010];
int n,p[200020],pos,mx,T,pt[100010];
inline void manacher() {
    n=strlen(t+1);
    s[0]='&';
    for(int i=1;i<=n;i++) {
        s[i*2-1]='#';
        s[i*2]=t[i];
    }
    n=n*2+1;
    s[n]='#';mx=0;
    for(int i=1;i<=n;i++) {
        if(mx>i)
            p[i]=min(mx-i,p[2*pos-i]);
        else
            p[i]=1;
        while(i-p[i]>0&&i+p[i]<=n&&s[i+p[i]]==s[i-p[i]])
            p[i]++;
        if(i+p[i]>mx) {
            mx=i+p[i];
            pos=i;
        }
    }
}
int main() {
    scan(T);
    while(T--) {
        int k;
        scan(k);
        scanf("%s",t+1);
        manacher();
        len=strlen(t+1);
        seg.init(len);
        for(int i=1;i<=n;++i)
        {
            int le=(p[i]*2-1)>>1;
            if(le<k)continue;
            int l=(i-p[i]+2)>>1,r=(i+p[i]-1)>>1;
            if(r-l+1>k)
            {
                int s=r-l+1-k;
                s>>=1;
                l+=s;r-=s;
            }
            //printf("%d %d\n",l,r);
            seg.add(1,1,l,r-1);
        }
        LL ans=0;
        for(int i=1;i<=len;i++)ans+=1ll*(seg.query(1,i,i)-i+1);
        printf("%lld\n",ans);
    }
}