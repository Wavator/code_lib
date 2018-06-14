#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
vector<int> seg[N*4];
bitset<N> st,res;
void change(int L,int R,int l,int r,int rt,int x) {
    if (l>=L && r<=R) {
        seg[rt].push_back(x);
        return;
    }
    int mid=(l+r)>>1;
    if (L<=mid)
        change(L,R,l,mid,rt<<1,x);
    if (R > mid)
        change(L,R,mid+1,r,rt<<1|1,x);
}

void query(int l,int r,int rt,bitset<N>now) {
    for (int &x:seg[rt])
        now|=(now<<x);
    if (l==r)
        return(void)(res|=now);
    int mid=(l+r)>>1;
    query(l,mid,rt<<1,now);
    query(mid+1,r,rt<<1|1,now);
}

int main() {
    int n,q;
    scanf("%d%d", &n, &q);
    for (;q--;) {
        int l,r,x;
        scanf("%d%d%d",&l,&r,&x);
        change(l,r,1,n,1,x);
    }
    st[0]=1;
    query(1,n,1,st);
    int ans=0;
    for (int i=1;i<=n;++i)
        ans+=res[i];
    printf("%d\n",ans);
    for (int i=1;i<=n;++i)
        if (res[i])
            printf("%d ", i);
    puts("");
    return 0;
}
