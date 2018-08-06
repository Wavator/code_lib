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
const int N = 100005;
char s[N];
int n;

int dp[N][15], x, y;

void dfs(int &l, int &r, int u, int mx) {
    if(u == 0)
        return;
    int pos = (mx <= x)? (mx): (mx <= y + 1? (y - (mx - x - 1)): mx - 2);
    if (s[u] == pos)
    {
        if(dp[u][mx] == dp[u - 1][mx] + 1)
            dfs(l, r, u - 1, mx);
        else
        {
            if (mx == 2 + y)
                r = u;
            if (mx == x + 1)
                l = u + 1;
            dfs(l, r, u, mx - 1);
        }
    }
    else {
        if (dp[u][mx] == dp[u - 1][mx])
        {
            dfs(l, r, u - 1, mx);
        }
        else
        {
            if (mx == 2 + y)
                r = u;
            if (mx == x + 1)
                l = u + 1;
            dfs(l, r, u, mx - 1);
        }
    }
}

int ans, l, r;
void fuck()
{
    memset(dp[0],0,sizeof(dp[0]));
    for(int i = 1; i <= n; i++) {
        for (int j = 0; j <= 11; j++) {
            int temp = 0;
            if (j <= x) temp = j;
            else if (j <= y + 1) temp = y - (j - x - 1);
            else temp = j - 2;
            if (s[i] == temp)
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j] + 1);
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
//    rep(i,0,n+1){
//        rep(j,0,12){
//            cerr<<dp[i][j]<<' ';
//        }
//        cerr<<endl;
//    }
    int l = 1,r = 1;
    dfs(l, r, n, 11);
    //cerr<<dp[n][11]<<' '<<l<<' '<<r<<endl;
    if (dp[n][11] > ans)
    {
        ans = dp[n][11];
        ::l = l;
        ::r = r;
    }
}

int main()
{
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int T;
    for(scanf("%d",&T); T--; )
    {
        scanf("%d",&n);
        scanf("%s",s + 1);
        rep(i,1,n+1)s[i]-='0';
        ans = 0;
        for (x = 0; x < 9; ++x)
        {
            for (y = x + 1; y < 10; ++y)
            {
                fuck();
            }
        }
        printf("%d %d %d\n", ans, l, r);
    }
    return 0;
}
