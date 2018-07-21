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
const int N = 100000 + 10;
 
const ll mod = (ll)1e9 + 7;
 
ll a[N];
ll n;
void Main() {
    int ok = 0;
    read(n);
    ll ans1 = 0;
    ll ans2 = 0;
    ll pre = -1;
    rep(i, 0, n) {
        ll t;
        read(t);
        if (pre == -1)pre = t;
        else if (t >= pre) {
            ans1 += t - pre;
            if (t == pre && !ok)continue;
            if (!ok)ans2 += 2;
            ok = 1;
            pre = t;
        }
        else {
            ok = 0;
            pre = t;
        }
    }
    printf("%lld %lld\n", ans1,ans2);
 
 
}
 
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int T;
    for (read(T); T--; Main());
    return 0;
}