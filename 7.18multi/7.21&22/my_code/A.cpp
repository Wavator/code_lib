#pragma GCC optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#define debug(...) fprintf(stderr, __VA_ARGS__), fprintf(stderr, "\n"), fflush(stderr)
#else
#define debug(...) 99
#endif
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;typedef unsigned long long ull;typedef double db;
template <typename T> using pqmin = priority_queue<T, vector<T>, greater<T> >;
template <typename T> using pqmax = priority_queue<T>;
typedef vector<int> vi;typedef pair<int,int> pii;
inline char gc() { static char buf[1<<20],*h=buf,*t=buf;return (h==t&&(t=(h=buf)+fread(buf,1,1<<20,stdin),h==t)?-1:*h++);}
template <typename T> inline bool read(T &x){static int f;static char c;for(c=gc(),f=1;!isdigit(c);c=gc()){if(c==-1)return false;else if(c==45)f=-1;}for(x=c-48;isdigit(c=gc());x=x*10+c-48);return x*=f,true; }
template <typename A, typename B> inline bool read(A&x, B&y) {return read(x) && read(y);}
template <typename A, typename B, typename C> inline bool read(A&x,B&y,C&z){return read(x)&&read(y)&&read(z);}
/*
 *
 */
const int N = 100005;
 
const ll mod = (ll)1e9 + 7;
 
ll dp[2][N];
ll ans[N];
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int q, k;
    read(q);
    read(k);
    dp[0][0]  = 1;
    for (int i = 1; i < N; ++i) {
        rep(j, 0, 2) {
            dp[0][i] += dp[j][i - 1];
            dp[0][i] %= mod;
        }
        if (i >= k) {
            dp[1][i] = dp[0][i - k];
        } else {
            dp[1][i] = 0;
        }
        //if (i < 10)debug("%lld ", dp[i]);
    }
    ans[0] = 1;
    rep(i, 1, N) {
        ans[i] = (ans[i - 1] + dp[0][i] + dp[1][i]) % mod;
    }
    while (q--) {
        int l, r;
        read(l);
        read(r);
        ll x = ans[r] - ans[l - 1];
        //debug("%lld %lld", dp[l - 1], dp[r]);
        printf("%lld\n", (x + mod) % mod);
    }
    return 0;
}