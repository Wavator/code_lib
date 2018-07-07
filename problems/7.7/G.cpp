#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 50;
typedef long long ll;
ll a[N << 2];
inline void push_up(int rt) {
    a[rt] = a[rt << 1] + a[rt << 1 | 1];
}
void build(int l, int r, int rt) {
    if (l == r) {
        scanf("%lld",&a[rt]);
        return;
    }
    int mid = l + r >> 1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    push_up(rt);
}

void change(const int &L, const int &R, int l, int r, int rt) {
    if (l == r) {
        a[rt]=(ll)sqrt(a[rt]);
        return;
    }
    if(l>=L&&r<=R && a[rt] == r - l + 1)
        return;
    int mid=(l+r)>>1;
    if(L<=mid)
        change(L,R,l,mid,rt<<1);
    if(R>mid)
        change(L,R,mid+1,r,rt<<1|1);
    push_up(rt);
}

ll query(const int &L, const int &R, int l, int r, int rt) {
    if (l >= L && r <= R)
        return a[rt];
    int mid = l + r >> 1;
    if (L > mid)
        return query(L, R, mid + 1, r, rt << 1 | 1);
    if (R <= mid)
        return query(L, R, l, mid, rt << 1);
    return query(L, R, l, mid, rt << 1) + query(L, R, mid + 1, r, rt << 1 | 1);
}

int main() {
    int cs = 1;
    int n;
    while (~scanf("%d", &n)) {
        printf("Case #%d:\n",cs++);
        build(1,n,1);
        int m;
        for (scanf("%d",&m); m--;) {
            static int op, x, y;
            scanf("%d%d%d",&op,&x,&y);
            if (x > y)
                swap(x,y);
            if (op) {
                printf("%lld\n", query(x,y,1,n,1));
            } else {
                change(x,y,1,n,1);
            }
        }
        puts("");
    }
    return 0;
}