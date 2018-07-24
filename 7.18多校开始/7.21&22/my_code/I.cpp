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
 
bool vis[N][2];
vector<pii> data;
 
 
bitset<N> ok[4];
int n, m;
bool spj() {
    return (ok[0][n/2+1]||ok[2][n/2+1]||ok[1][n/2+1]||ok[3][n/2+1]);
}
 
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
 
    read(n, m);
 
    for(int i=0;i<4;i++)
    {
        for(int j=1;j<=n/2;j++) ok[i].flip(j);
        if(n&1) ok[i].flip(n/2+1);
    }
    for(int i=0, x, y;i<m;i++) {
        read(x, y);
        ok[0][x]=0;
        ok[2][n+1-x]=0;
        ok[1][y]=0;
        ok[3][n+1-y]=0;
    }
    int ans=0;
    for(int i=0;i<4;i++) {
        if(n%2&&ok[i][n/2+1])
            ans--;
        ans+=ok[i].count();
    }
    if(n%2&&spj())
        ans++;
    printf("%d\n",ans);
    return 0;
}