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
const ll mod = (ll)1e9 + 7;
ll pow_mod(ll a, ll b) {
    assert(b >= 0);ll res=1;
    for (a %= mod; b; b >>= 1, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}

struct my_set
{
    map<int,int> s;
    int ans;
    void init(int n, int k)
    {
        ans=1;
        s.clear();
        s[k+1]=n;
        s[n]=k+1;
    }
    void remove(int k)
    {
        bool f = s.find(k - 1) != s.end();
        bool g = s.find(k + 1) != s.end();
        if (f && g)
        {
            int l = s[k - 1];
            int r = s[k + 1];
            s.erase(k-1);
            s.erase(k+1);
            s.erase(l);
            s.erase(r);
            s[l]=r;
            s[r]=l;
            --ans;
        } else if (f) {
            int l=s[k-1];
            s.erase(k-1);
            s[l]=k;
            s[k]=l;
        } else if (g) {
            int r=s[k+1];
            s.erase(k+1);
            s[r]=k;
            s[k]=r;
        } else {
            s[k]=k;
            ++ans;
        }
    }

    void add(int k) {
        if(s.count(k)){
            int y=s[k];
            if(y<k){
                s[y]=k-1;
                s[k-1]=y;
            }
            else if(y>k){
                s[y]=k+1;
                s[k+1]=y;
            }
            else {
                ans--;
            }
            s.erase(k);
        } else {
            auto it = s.lower_bound(k);
            --it;
            assert(it->first<k);
            int l=it->first,r=it->second;
            s.erase(l);
            s.erase(r);
            s[l]=k-1;
            s[r]=k+1;
            s[k-1]=l;
            s[k+1]=r;
            ++ans;
        }
    }
}s;

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int T;
    scanf("%d",&T);
    for(int ks=1;ks<=T;++ks){
        int n,k,q;
        scanf("%d%d%d",&n,&k,&q);
        printf("Case %d:\n",ks);
        s.init(n,k);
        while(q--){
            int x,y;
            scanf("%d%d",&x,&y);
            s.remove(x);
            s.add(y);
            printf("%d\n",s.ans);
        }
    }
    return 0;
}