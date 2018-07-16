#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
const int M = 500005;
class DSU {
public:
    static const int N = ::N, M = ::M<<1;
    int fa[N],rk[N],tp ;
    pair<int*,int> st [M] ; // query_count
    inline int find(int x){
        for(;x^fa [x];)
            x=fa[x];
        return x;
    }
    void init(int n){
        tp=0;
        for(int i=1; i<=n; ++i)
            fa[i]=i,rk[i]=1 ;
    }
    inline bool join(int u,int v) {
        int fu=find(u),fv=find(v);
        if(fu==fv)
            return 0;
        if(rk[fu]<rk[fv])
            swap(fu,fv);
        st[++tp]=make_pair(fa+fv,fa[fv]);
        fa[fv]=fu;
        st[++tp]=make_pair(rk+fu,rk [fu]);
        ++rk[fu];
        return true;
    }
    inline bool same(int u,int v){
        return find(u)==find(v);
    }
    inline void roolback() { // roll back 1 op
        *st[tp].first= st[tp].second ;
        -- tp ;
        *st[tp].first= st[tp].second ;
        -- tp ;
    }
};
DSU dsu;

vector <pair<int, int> > a[M << 2];


void gao(int L, int R, int l, int r, int rt, const pair<int, int> & add) {
    if (l >= L && r <= R) {
        a[rt].push_back(add);
        return;
    }
    int mid = l + r >> 1;
    if (L <= mid)
        gao(L, R, l, mid, rt << 1, add);
    if (R > mid)
        gao(L, R, mid + 1, r, rt << 1 | 1, add);
}
map <pair<int, int>, int > qtime;
bool ask[M];
pair<int, int> q[M];
void lizi_nb(int l, int r, int rt) {
    int joined = 0;
    for (const pair<int, int> &p: a[rt]) {
        if(dsu.join(p.first, p.second))
            joined++;
    }
    if (l == r) {
        if(ask[l]) {
            if (dsu.same(q[l].first, q[l].second))
                puts("Y");
            else
                puts("N");
        }
        for (; joined--;)
            dsu.roolback();
        return;
    }
    int mid = l + r >> 1;
    lizi_nb(l, mid, rt << 1);
    lizi_nb(mid + 1, r, rt << 1 | 1);
    for (; joined--;)
        dsu.roolback();
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    dsu.init(n);
    for (int i = 1; i <= m; ++i) {
        static int op, u, v;
        scanf("%d%d%d", &op, &u, &v);
        if (u > v)
            swap(u, v);
        if (op == 0)
            qtime.insert({{u, v}, i});
        else if (op == 1) {
            gao(qtime[{u, v}], i, 1, m, 1, {u, v});
            qtime.erase({u, v});
        } else {
            q[i] = {u, v};
            ask[i] = 1;
        }
    }
    for (map<pair<int, int>, int>::const_iterator it = qtime.begin(); it != qtime.end(); ++it){
        gao(it->second, m, 1, m, 1, it->first);
    }
    lizi_nb(1, m, 1);
    return 0;
}