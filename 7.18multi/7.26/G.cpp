#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
const int mod = 1000000007;
inline int mult(int x, int y) {
    return static_cast<int>((long long)x * y % mod);
}
struct edge {
    int y;
    edge * next;
};
edge * li[N];
inline void insert(int u, int v) {
    static edge e[N<<1], *top = e;
    li[u] = & (*top++=(edge){v,li[u]});
    li[v] = & (*top++=(edge){u,li[v]});
}
int n, m, k, dd;
bool vis[N];
void dfs(int u, int fa, int d, int &remains) {
    if(vis[u]){if(d<dd)remains--;}
    int v;
    for(edge*t=li[u];t;t=t->next){
        v=t->y;
        if(v!=fa){
            dfs(v,u,d+1,remains);
        }
    }
}

int gao(int d) {
    dd=d;
    static int que[N];
    int hd=0,tl=0,u;
    fill(vis+1,vis+1+n,false);
    int ans=1;
    for(que[tl++]=1;hd^tl;hd++){
        u=que[hd];
        int t=m;
        dfs(u,0,0,t);
        ans=mult(ans,t);
        vis[u]=true;
        for(edge*x=li[u];x;x=x->next){
            if(!vis[x->y])que[tl++]=x->y;
        }
    }
    return ans;
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1, u, v; i < n; ++i) {
        scanf("%d%d", &u, &v);
        insert(u, v);
    }
    return !printf("%d\n",(gao(k)-gao(k+1)+mod)%mod);
}