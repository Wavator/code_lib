#include <bits/stdc++.h>
using namespace std;
const int N=200010,mod=998244353;
int mi=1e9+10,ma=-1e9-10;
int tot,ans[N],is[N],l[N],r[N];
int ls[N<<3],cnt;
int lst[N<<4],des[N*16*20],nxt[N*16*20],sz;
inline void add(int x,int y){
    nxt[++sz]=lst[x],lst[x]=sz,des[sz]=y;
}
void fuck(int l,int r,int w,int L,int R,int id) {
    if (L <= l && r <= R) {
        add(w, id);
        return;
    }
    int mid = l + r >> 1;
    if (L <= mid)
        fuck(l, mid, w << 1, L, R, id);
    if (R > mid)
        fuck(mid + 1, r, w << 1 | 1, L, R, id);
}
void gao(int l,int r,int w,int ps) {
    if (lst[w]) {
        for (int u = lst[w]; u; u = nxt[u]) {
            if (!is[des[u]])ans[tot++]=des[u];
        }
        lst[w]=0;
    }
    if (l == r)
        return;
    int mid = l + r >> 1;
    if (ps <= mid)
        gao(l, mid, w << 1, ps);
    else
        gao(mid + 1, r, w << 1 | 1, ps);
}


inline int wa_bound(int x){
    int l = lower_bound(ls+1,ls+cnt+1,x)-ls;
    return ls[l]==x?l*2-1:l*2-2;
}
int main(){
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int T;
    scanf("%d",&T);
    for(int ks=1;ks<=T;ks++){
        printf("Case #%d:\n",ks);
        mi=(int)1e9+1,ma=-(int)1e9-1;
        cnt=0;
        memset(is,0,sizeof(is));
        memset(lst,0,sizeof(lst));
        sz=0;
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d%d",l+i,r+i);
            ls[++cnt]=l[i];
            ls[++cnt]=r[i];
            mi=min(mi,l[i]);
            ma=max(ma,r[i]);
        }
        sort(ls+1,ls+cnt+1);
        cnt=int(unique(ls+1,ls+cnt+1)-ls-1);
        cnt=cnt*2-1;
        for(int i=1;i<=n;i++){
            l[i]=wa_bound(l[i]);
            r[i]=wa_bound(r[i]);
            fuck(1,cnt,1,l[i],r[i],i);
        }
        int la=0;
        for(int q=1,x;q<=m;q++){
            scanf("%d",&x);
            x^=la;
            if(x<mi||x>ma){
                la=0;
                puts("0");
                continue;
            }
            x=wa_bound(x);
            tot=0;
            gao(1,cnt,1,x);
            printf("%d\n",tot);
            if(!tot)la=0;
            else{
                la=1;
                for(int i=0;i<tot;i++){
                    la=(int)((long long)la*ans[i]%mod);
                    is[ans[i]]=q;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            printf("%d%c", is[i]," \n"[i==n]);
            is[i] = 0;
        }
    }
}