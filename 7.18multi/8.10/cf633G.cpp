#include <bits/stdc++.h>
using namespace std;
const int M = 1001;
typedef bitset<M> bs;
const int N = 100005;
struct edge {
    int y, next;
} e[N << 1];
int li[N];
inline void ade(int u, int v) {
    static int top = 0;
    e[++top] = edge{v, li[u]};
    li[u] = top;
    e[++top] = edge{u, li[v]};
    li[v] = top;
}

int dfn[N], fin[N], pos[N], clk;

void dfs(int u,int fa){
    dfn[u]=fin[u]=++clk;
    pos[clk]=u;
    for(int i=li[u],v;i;i=e[i].next){
        v=e[i].y;
        if(v!=fa)dfs(v,u);
    }
    fin[u]=clk;
}
int n, m;
int v[N];
bs a[N << 2];

int lz[N << 2];

inline void add(bs&o, int x){
    x%=m;
    o=o<<x|o>>(m-x);
}

inline void push_up(int rt){
    a[rt]=a[rt<<1]|a[rt<<1|1];
}

inline void push_down(int rt) {
    if(lz[rt]){
        lz[rt<<1]+=lz[rt];
        lz[rt<<1|1]+=lz[rt];
        add(a[rt<<1],lz[rt]);
        add(a[rt<<1|1],lz[rt]);
        lz[rt]=0;
    }
}

void build(int l, int r, int rt){
    if(l==r){
        a[rt][v[pos[l]]]=1;
        return;
    }
    int mid=l+r>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    push_up(rt);
}

void change(int L, int R, int v, int l, int r, int rt){
    if(l>=L&&r<=R){
        lz[rt]+=v;
        add(a[rt],v);
        return;
    }
    int mid=l+r>>1;
    push_down(rt);
    if(L<=mid)
        change(L,R,v,l,mid,rt<<1);
    if(R>mid)
        change(L,R,v,mid+1,r,rt<<1|1);
    push_up(rt);
}

bs query(int L, int R, int l, int r, int rt){
    if (l >= L && r <= R)
        return a[rt];
    int mid=l+r>>1;
    push_down(rt);
    if(L>mid)
        return query(L,R,mid+1,r,rt<<1|1);
    if(R<=mid)
        return query(L,R,l,mid,rt<<1);
    return query(L,R,l,mid,rt<<1)|query(L,R,mid+1,r,rt<<1|1);
}

bs p;

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    scanf("%d%d",&n,&m);
    p.set();
    p[0]=p[1]=0;
    for(unsigned i=2;i<=m;++i)if(p[i]){
            for(unsigned j=2*i;j<=m;j+=i)p[j]=0;
        }
    for(unsigned i=(unsigned)m;i<M;++i)p[i]=0;
    for(int i=1;i<=n;++i)scanf("%d",v+i),v[i]%=m;
    for(int i=1,u,v;i<n;++i){
        scanf("%d%d",&u,&v);
        ade(u,v);
    }
    dfs(1,0);
    build(1,n,1);
    int q;
    for(scanf("%d", &q); q--; )
    {
        static int op,x,y;
        scanf("%d",&op);
        if(op==1){
            scanf("%d%d",&x,&y);
            change(dfn[x],fin[x],y%m,1,n,1);
        }else{
            scanf("%d",&x);
            printf("%d\n",(int)(p&query(dfn[x],fin[x],1,n,1)).count());
        }
    }
    return 0;
}