#pragma optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i,a,n) for(int i=(a);i<(n);++i)
#define per(i,a,n) for(int i=(n)-1;i>=(a);--i)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
#ifdef Wavator
#define debug(fmt, ...) fprintf(stderr, "func[%s] line %d: %s = " fmt "\n", \
                __func__, __LINE__, #__VA_ARGS__, __VA_ARGS__), fflush(stderr)
#define err(x) cerr << "func[" << __func__ << "] line " << __LINE__ << ": " \
                    << #x << " = " << x << endl << flush
#else
#define debug(...) 99
#define err(x) 99
#endif
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int mod = (int)1e9+7;
const int N = 1005;
struct edge {
    int y, next;
} e[N << 1];
int li[N], ecnt;
inline void add_edge(int u, int v) {
    e[++ecnt] = edge{v, li[u]};
    li[u] = ecnt;
}
#define add_edges(u,v) add_edge(u,v),add_edge(v,u)
int B, stk[N],top;
int ans[N], tot, rt[N];
void dfs(int u, int fa)
{
    int des = top;
    for (int i = li[u], v; i; i = e[i].next) {
        v = e[i].y;
        if (v != fa) {
            dfs(v, u);
            if (top - des >= B) {
                rt[++tot]=u;
                while (top > des)ans[stk[--top]]=tot;
            }
        }
    }
    stk[top++]=u;
}

int main() {
    int n;
    scanf("%d%d",&n,&B);
    int u,v;
    rep(i,1,n){
        scanf("%d%d",&u,&v);
        add_edges(u,v);
    }
    dfs(1,0);
    while(top)ans[stk[--top]]=tot;
    printf("%d\n",tot);
    for(int i=1;i<=n;++i)printf("%d%c",ans[i]," \n"[i==n]);
    for(int i=1;i<=tot;++i)printf("%d%c",rt[i]," \n"[i==n]);
    return 0;
}
