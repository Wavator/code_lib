#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
typedef bitset<N> bs;

vector<int> s[N << 2];

void change(const int &L, const int &R, int x, int l, int r, int rt) {
    if (l >= L && r <= R) {
        s[rt].push_back(x);
        return;
    }
    int mid = l + r >> 1;
    if (L <= mid)
        change(L, R, x, l, mid, rt << 1);
    if (R > mid)
        change(L, R, x, mid + 1, r, rt << 1 | 1);
}

bs ans;

void query(int l, int r, int rt, bs now) {
    for (const int &x: s[rt]) now |= now << x;
    if (l == r) {
        ans |= now;
        return;
    }
    int mid = l + r >> 1;
    query(l, mid, rt << 1, now);
    query(mid + 1, r, rt << 1 | 1, now);
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    ans.reset();
    unsigned n,q;
    scanf("%u%u",&n,&q);
    for(int l,r,x;q--;){
        scanf("%d%d%d",&l,&r,&x);
        change(l,r,x,1,n,1);
    }
    query(1,n,1,bs(1));
    for(unsigned i=n+1;i<N;++i)ans.reset(i);
    printf("%d\n",(int)ans.count()-1);
    for(unsigned i=1;i<=n;++i)if(ans.test(i)){
            printf("%d ",i);
        }
    puts("");
    return 0;
}
