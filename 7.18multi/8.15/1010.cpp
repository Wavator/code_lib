#pragma optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#include "local_debug.h"
#else
#define debug(...)
#endif
#define pb push_back
#define rep(i,a,n) for(int i=(a);i<(n);++i)
#define per(i,a,n) for(int i=(n)-1;i>=(a);--i)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
const int N = 200005;
int stk[N], top;
int bas[22];
inline int Q(int x) {
    int res = 0;
    per(i,0,21)
        if(res+bas[i]<=top&&stk[res+bas[i]]>x)
            res+=bas[i];
    return res;
}
int h[N],q[N],mx[N],cnt[N],p[N],ans[N];
vi pos[N];
int main() {
    bas[0]=1;
    rep(i,1,22)bas[i]=bas[i-1]<<1;
    int T;
    for(scanf("%d",&T);T--;){
        int n, m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i){
            scanf("%d",h+i);
            pos[i].clear();
        }
        for(int i=1;i<=m;++i) {
            scanf("%d%d",p+i, q+i);
            pos[p[i]].push_back(i);
        }
        mx[0] = -1; cnt[0] = 0;
        for(int i=1;i<=n;++i) {
            if(h[i] > mx[i - 1]) {
                mx[i] = h[i];
                cnt[i] = cnt[i - 1] + 1;
            } else {
                mx[i] = mx[i - 1];
                cnt[i] = cnt[i - 1];
            }
        }
        top = 0;
        for(int i = n; i; i--)
        {
            for(const int&v:pos[i]) {
                int x = v;
                if(q[x] > mx[i - 1])
                    ans[x] = cnt[i - 1] + Q(q[x]) + 1;
                else
                    ans[x] = cnt[i - 1] + Q(mx[i - 1]);
            }
            while(top && stk[top] <= h[i])
                top--;
            stk[++top] = h[i];
        }
        for(int i = 1; i <= m; i++) printf("%d\n", ans[i]);
    }
    return 0;
}