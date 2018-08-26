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
const int N = 1000000+100;
int X[N],Y[N],V[N],lsh[N << 1],tags[N],res[N];

struct bit
{
    int a[N], n;
    void init(int n) {
        this->n = n;
        for(int i=0;i<=n;i++)a[i]=0;
    }
    void change(int pos,int y) {
        for(;pos<=n;pos+=pos&(-pos))a[pos]=max(a[pos],y);
    }
    int ask(int pos) {
        int ret=0;
        for(;pos;pos-=pos&(-pos))ret=max(ret,a[pos]);
        return ret;
    }
}bt;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        int tot=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d", X + i, Y + i, V + i);
            lsh[++tot]=X[i];lsh[++tot]=Y[i];
        }
        sort(lsh+1,lsh+tot+1);
        tot=(int)(unique(lsh+1,lsh+tot+1)-lsh-1);
        bt.init(tot);
        for(int i=1;i<=n;i++)
        {
            X[i]=(int)(lower_bound(lsh+1,lsh+tot+1,X[i])-lsh-1+1);
            Y[i]=(int)(lower_bound(lsh+1,lsh+tot+1,Y[i])-lsh-1+1);
        }
        for(int i=1;i<=n;i++)tags[i]=i;
        sort(tags+1,tags+n+1,[](const int &x, const int &y)->bool {
            return X[x] < X[y];
        });
        int le = 1;
        int ri = 1;
        while (le <= n)
        {
            while(ri<n&&X[tags[ri+1]]==X[tags[le]])
            {
                ri++;
            }
            for(int i=le;i<=ri;i++)
                res[i]=bt.ask(Y[tags[i]]-1)+V[tags[i]];
            for(int i=le;i<=ri;i++)
                bt.change(Y[tags[i]],res[i]);
            le = ri + 1;
        }
        printf("%d\n", bt.ask(tot));
    }
    return 0;
}

