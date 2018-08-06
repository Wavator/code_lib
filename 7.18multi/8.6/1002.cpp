#include <bits/stdc++.h>
#pragma optimize("-O3")
using namespace std;
namespace Quick_in {
    const int LEN=(1<<21)+1; char ibuf[LEN],*iH,*iT;int f,c;
#define gc() (iH==iT?(iT=(iH=ibuf)+fread(ibuf,1,LEN,stdin),(iH==iT?EOF:*iH++)):*iH++)
    inline char nc(){
        while((c=gc())<=32)if(c==-1)return -1;
        return (char)c;
    }
    template<class T> inline void sc(T&x) {
        for (f=1,c=gc();c<'0'||c>'9';c=gc()) if (c=='-') f=-1;
        for (x=0;c<='9'&&c>='0';c=gc()) x=x*10+(c&15); x*=f;
    }
    template<class T> inline bool read(T&x) {
        for (f=1,c=gc();c<'0'||c>'9';c=gc()){ if(c==-1)return 0;if(c=='-') f=-1; }
        for(x=c-48;;x=x*10+(c&15)){ if(!isdigit(c=gc()))break;}x*=f; return 1;
    }
    inline int gline(char*s) {
        int l=-1;
        for (c=gc();c<=32;c=gc())if(c==-1)return c;
        for (;c>32||c==' ';c=gc()){
            s[++l]=c;
        }
        s[l+1]=0;
        return l;
    }
    inline int gs(char *s) {
        int l=-1;
        for (c=gc();c<=32;c=gc())if(c==-1)return c;
        for (;c>32;c=gc()){
            s[++l]=c;
        }
        s[l+1]=0;
        return l;
    }
    template <typename A, typename B> inline void sc(A&x,B&y){sc(x),sc(y);};
    template <typename A, typename B> inline bool read(A&x,B&y){return read(x)&&read(y);};
}
namespace Quick_out {
    static const int BUFFER_MAX_SIZE = 1<<18;
    char buf[BUFFER_MAX_SIZE], *ph = buf, *pt = buf + BUFFER_MAX_SIZE;
    char tmp[100];
    const double dx[15] = {5e-1,5e-2,5e-3,5e-4,5e-5,5e-6,5e-7,5e-8,5e-9,5e-10,5e-11,5e-12,5e-13,5e-14,5e-15};
    inline void my_flush() {
        fwrite(buf, sizeof(char), ph - buf, stdout);
        ph = buf;
    }
    inline void pc(char c) {
        *(ph++) = c;
        if (ph == pt) my_flush();
    }
    inline void ps(const char *s) {
        for (int i = 0; s[i]; ++i) pc(s[i]);
    }
    inline void ps(const string&s) {
        ps(s.c_str());
    }
    template<class T>
    inline void pi(T x, char ec = '\n') {
        if (x < 0) pc('-'), x = -x;
        int len = 0;
        if (!x) tmp[len++] = '0';
        for(;x;) tmp[len++] = x % 10 + '0', x /= 10;
        for(;len;)  pc(tmp[--len]);
        pc(ec);
    }
    inline void pd(double x, int fix = 8, char bc = '\n') {
        x += dx[fix];
        if (x < 0) pc('-'), x = -x;
        pi((long long)x, '.');
        x -= (long long)x;
        for(;fix--;) {
            x *= 10;
            pc('0' + (int)x);
            x -= (int)x;
        }
        pc(bc);
    }
    struct Quick_{~Quick_(){my_flush();}}ooo;
}
using Quick_in::sc;
using Quick_in::read;
using Quick_in::gline;
using Quick_in::gs;
using Quick_in::nc;
using Quick_out::pi;
using Quick_out::pc;
using Quick_out::ps;
using Quick_out::pd;
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
const db eps = 1e-7;
ll pow_mod(ll a, ll b) {
    assert(b >= 0);ll res=1;
    for (a %= mod; b; b >>= 1, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}

int mx,mi;
unordered_map<int,int>mp;
int b[10];
int fuck(int x,int y,int z){
    int t = 0;
    while(z>0){
        b[t] = z%10;
        t++;
        z/=10;
    }
    swap(b[x-1],b[y-1]);
    if(b[t-1]==0)
        return 0;
    int ret = 0;
    for(int i = t-1;i >= 0;i--){
        ret *= 10;
        ret += b[i];
    }
    return ret;
}
void bfs(int n,int k){
    queue<pair<int, int> >q;
    mp.clear();
    pair<int, int> now,next;
    now.first = n;
    now.second = 0;
    q.push(now);
    int ret = 0;
    while(!q.empty()){
        now = q.front();
        q.pop();
        ret ++;
        if(now.second>k)
            break;
        mi = min(mi,now.first);
        mx = max(mx,now.first);
        next.second = now.second+1;
        int t = 0,z = now.first;
        for(;z;){
            t++;
            z/=10;
        }
        for(int i = 1;i <= t;i++)
            for(int j = i+1;j <= t;j++){
                next.first = fuck(i,j,now.first);
                if(next.first>=mi&&next.first<=mx)
                    continue;
                if(next.first!=0&&mp[next.first]!=1){
                    mp[next.first] = 1;
                    q.push(next);
                }
            }
    }
    return ;
}
int a[20];
int main()
{
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int T,n,k;
    for (sc(T); T--;){
        sc(n, k);
        if(k>8){
            memset(a,0,sizeof(a));
            while(n){
                a[n%10]++;
                n/=10;
            }
            int x=-1;
            for(int i = 1;i <= 9;i++)
                if(a[i]>0){
                    a[i]--;
                    x = i;
                    break;
                }
            printf("%d",x);
            for(int i = 0;i <= 9;i++)
                for(int j = 0;j < a[i];j++)
                    printf("%d",i);
            a[x]++;
            printf(" ");
            for(int i = 9;i >= 0;i--)
                for(int j = 0;j < a[i];j++)
                    printf("%d",i);
            printf("\n");
            continue;
        }
        mx = INT_MIN;
        mi = INT_MAX;
        bfs(n,k);
        printf("%d %d\n",mi,mx);
    }
    return 0;
}
