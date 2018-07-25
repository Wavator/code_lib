#pragma GCC optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#define debug(...) fprintf(stderr, __VA_ARGS__), fprintf(stderr, "\n"), fflush(stderr)
#else
#define debug(...) 99
#endif
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
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
 
struct bit {
    vector<vector<ll> > tree;
    int n, m;
    void init(int n, int m) {
        this->n = n;
        this->m = m;
        tree.assign(n + 1, vector<ll>(m + 1, 0) );
    }
    void add(int x, int y, ll z) {
        int memo_y = y;
        while (x <= n) {
            y = memo_y;
            while (y <= m)
                tree[x][y] += z, y += y & -y;
            x += x & -x;
        }
    }
 
 
 
    void range_add(int xa, int ya, int xb, int yb, ll z) {
        add(xa, ya, z);
        add(xa, yb + 1, -z);
        add(xb + 1, ya, -z);
        add(xb + 1, yb + 1, z);
    }
    ll ask(int x, int y) {
        ll res = 0;
        int memo_y = y;
        while (x) {
            y = memo_y;
            while (y)
                res += tree[x][y], y -= y & -y;
            x -= x & -x;
        }
        return res;
    }
 
} ta, tb;
const int N = 1e6 + 10;
vector<vector<ll> > a;
ll mp[N];
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int n, m, q;
    read(n, m, q);
    ta.init(n + 2, m + 2);
    tb.init(n + 1, m + 2);
    a.assign(n + 2, vector<ll>(m + 2, 0));
    for (int i = 1; i <= n * m; ++i){
        mp[i] = i;
    }
    random_shuffle(mp+1,mp+n*m+1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            read(a[i][j]);
    while (q--){
        static int x1, y1, x2, y2, k;
        read(x1, y1);
        read(x2, y2);
        read(k);
        ll cnt = mp[k];
        ta.range_add(x1, y1, x2, y2, cnt);
        tb.range_add(x1, y1, x2, y2, 1);
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (mp[a[i][j]] * tb.ask(i, j) == ta.ask(i, j)) ans++;
    cout << 1ll * n * m - ans << endl;
    return 0;
}