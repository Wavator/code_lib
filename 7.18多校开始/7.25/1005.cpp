#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#define debug(...) fprintf(stderr, __VA_ARGS__),fprintf(stderr, "\n"),fflush(stderr)
#else
#define debug(...) 98
#endif
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const ll mod = (ll)1e9+7;
//#define scanf ______
#define gc getchar
//inline char gc() { static char buf[1<<20], *head = buf, *tail = buf;return (head == tail && (tail = (head = buf) + fread(buf, 1, 1 << 20, stdin), head == tail)? -1: *head++); }
template <typename T> inline bool read(T &x){ static bool f;static char c;for (c = gc(), f = false; !isdigit(c); c = gc()) { if (c == EOF)return false; else if (c == 45)f = true; }for (x=0;isdigit(c);c=gc())x = x * 10 + c - 48;if (f)x = -x;return true; }
template <typename A, typename B> inline bool read(A&a,B&b){return read(a)&&read(b);}
template <typename A, typename B, typename C> inline bool read(A&a,B&b,C&c){return read(a)&&read(b)&&read(c);}
ll pow_mod(ll a, ll b = mod - 2) { assert(b>=0);ll res=1;for(a%=mod;b;b>>=1,a=a*a%mod)if(b&1)res=res*a%mod;return res; }
/*
 * head
 */


void solve(const int &MOD) {
    vector<vector<bool> > ans(2000, vector<bool>(2000, 0));
    rep(i, 0, MOD) {
        rep(j, 0, MOD) {
            int now=j;
            rep(k, 0, MOD) {
                int x = i*MOD+j;
                int y = k*MOD+now;
                if(x < 2000 && y < 2000)ans[x][y] = 1;
                (now+=i)%=MOD;
            }
        }
    }
    int x=0;
    for (const auto &xx: ans) {
        for (const auto &yy: xx) {
            if (yy)x++;
        }
    }
    assert(x>=85000);
    //cerr << x << endl;
    puts("2000");
    for (const auto &row: ans) {
        for (const auto &c: row) {
            putchar(c+48);
        }
        putchar(10);
    }
    fflush(stdout);
    exit(0);
}
bool isp[200];
int main() {
#ifdef Wavator
    freopen("C:\\Users\\wavator\\Desktop\\1.txt", "w", stdout);
#endif
//    fill(isp+2,isp+200,1);
//    for(int i=2;i<200;++i){
//        if (isp[i]){
//            if(i>41)
//                solve(i);
//            for(int j=2*i;j<200;j+=i) isp[j]=0;
//        }
//    }
    solve(47);
    return 0;
}