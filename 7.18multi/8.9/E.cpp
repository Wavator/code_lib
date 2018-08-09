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
const db eps = 1e-7;
ll pow_mod(ll a, ll b) {
    assert(b >= 0);ll res=1;
    for (a %= mod; b; b >>= 1, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
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
    struct Quick_{~Quick_(){my_flush();}}oooOoooOO;
}
vector<pii> e;

ll C[1000], D[1000];
int ans[1000002];

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    C[3]=D[4]=1;
    rep(i,4,305)C[i]=C[i-1]*i/(i-3);
    rep(i,5,305)D[i]=D[i-1]*i/(i-4);
    int k;
    cin >> k;
    per(sz,4,76){
        if(k<D[sz])continue;
        if(1ll*(75-sz+1)*D[sz]<k)continue;
        int kk=k-D[sz];
        fill(ans,ans+kk+1,0);
        queue<pii> q;
        while(!q.empty())q.pop();
        q.emplace(kk,75);
        ans[kk]=75;
        while (!q.empty())
        {
            if(ans[0])
                break;
            pii p=q.front();
            q.pop();
            rep(j,3,sz){
                ll nxt=p.first-C[j];
                if(nxt<0||ans[nxt]||p.second==sz+1)continue;
                ans[nxt]=p.second-1;
                q.emplace(nxt,p.second-1);
            }
        }
        if(!ans[0])continue;
        rep(i,2,sz+1){
            rep(j,1,i){
                e.emplace_back(i,j);
            }
        }
        for(int i=75;i>sz;--i){
            e.emplace_back(i,1);
            e.emplace_back(i,2);
        }
        int now=0,cur=ans[0];
        while(now!=kk){
            rep(j,3,sz){
                if(now+C[j]>kk)break;
                if(ans[now+C[j]]==cur+1){
                    rep(p,3,j+1)e.emplace_back(cur+1,p);
                    now+=C[j];
                    cur++;
                }
            }
        }
        Quick_out::pi(75,' ');
        Quick_out::pi(SZ(e));
        for(auto&x:e){
            Quick_out::pi(x.fi,' ');
            Quick_out::pi(x.se);
        }
        return 0;
    }
    return 0;
}