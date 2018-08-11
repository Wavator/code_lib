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

const int maxn=100005;

struct Seg {
#define common int o,int l,int r
#define root 1,1,n
#define ls o<<1
#define rs ls|1
#define mid ((l+r)>>1)
#define lson ls,l,mid
#define rson rs,mid+1,r
    LL mx[maxn<<2];
    int T,n,q;
    inline void build(common) {
        if(l==r) {
            mx[o]=0ll;
            return;
        }
        build(lson),build(rson);
        mx[o]=max(mx[ls],mx[rs]);
    }
    inline void modify(common,int p,LL d) {
        if(l==r) {
            mx[o]=d;
            return;
        }
        if(p<=mid)
            modify(lson,p,d);
        else
            modify(rson,p,d);
        mx[o]=max(mx[ls],mx[rs]);
    }
    inline LL query(common,int ql,int qr) {
        if(ql<=l&&r<=qr)
            return mx[o];
        LL res=0;
        if(ql<=mid)
            res=max(res,query(lson,ql,qr));
        if(qr>mid)
            res=max(res,query(rson,ql,qr));
        return res;
    }
}seg;

bool big[maxn];
vi g[maxn];
LL ans[maxn],sum[maxn],val[maxn];
int T,n,dep[maxn],maxd,sz[maxn];

void add(int u,int lb)
{
    if(lb>0)sum[dep[u]]-=val[u];else sum[dep[u]]+=val[u];
    //printf("%d %d %lld\n",u,lb,sum[dep[u]]);
    seg.modify(1,1,maxd,dep[u],sum[dep[u]]);
    for(auto p : g[u])
    {
        if(!big[p])
            add(p,lb);
    }
}

void DFS(int v,int p,bool k)
{
    int bn=-1;
    for(auto u : g[v])
    {
        if(u!=p)
        {
            if(bn==-1 || sz[u]>sz[bn])bn=u;
        }
    }
    for(auto u : g[v])
    {
        if(u!=p && u!=bn)
            DFS(u,v,false);
    }
    if(bn!=-1)
    {
        DFS(bn,v,true);
        big[bn]=true;
    }
    add(v,1);
    ans[v]=seg.query(1,1,maxd,1,maxd);
    if(bn!=-1)big[bn]=false;
    if(!k)add(v,-1);
}

void precal(int u,int f)
{
    dep[u]=dep[f]+1;
    sum[dep[u]]+=val[u];
    maxd=max(maxd,dep[u]);
    sz[u]=1;
    for(int p : g[u])
    {
        precal(p,u);
        sz[u]+=sz[p];
    }
}

int main()
{
    scan(T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)g[i].clear(),sz[i]=0,sum[i]=0,big[i]=false;
        dep[0]=0;maxd=0;
        for(int i=1;i<=n;i++)scanf("%lld",&val[i]);
        for(int i=2;i<=n;i++)
        {
            int x;scan(x);
            g[x].pb(i);
        }
        precal(1,0);
        seg.build(1,1,maxd);
        for(int i=1;i<=maxd;i++)seg.modify(1,1,maxd,i,sum[i]);
        DFS(1,0,false);
        for(int i=2;i<=n;i++)printf("%lld\n",ans[i]);
    }
    return 0;
}