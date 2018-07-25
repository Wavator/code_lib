#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#define debug(...) fprintf(stderr, __VA_ARGS__), fprintf(stderr, "\n")
#else
#define debug(...) 99
#endif
#define forn(i, n) for(int i = 0; i < (n); ++i)
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, a, b) for(int i = (a); i <= (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll mod = (ll) 1e9 + 7;
const int maxn = 200100;
int n,q;
int cnt = 0;
struct Node{
    int l,r,sum;
}p[maxn * 40];
 
int la[1000000 + 10];
 
int a[maxn];
int rtt[maxn];
 
int build(int l,int r){
    int nc = ++cnt;
    p[nc].sum = 0;
    p[nc].l = p[nc].r = 0;
    if (l == r) return nc;
    int m = l + r >> 1;
    p[nc].l = build(l,m);
    p[nc].r = build(m+1,r);
    return nc;
}
 
int update(int pos,int c,int v,int l,int r){
    int nc = ++cnt;
    p[nc] = p[c];
    p[nc].sum += v;
    if (l == r) return nc;
    int m = l+r>>1;
    if (m >= pos){
        p[nc].l = update(pos,p[c].l,v,l,m);
    }
    else {
        p[nc].r = update(pos,p[c].r,v,m+1,r);
    }
    return nc;
}
 
int query(int pos,int c,int l,int r){
    if (l == r) return p[c].sum;
    int m = l + r >> 1;
    if (m >= pos){
        return p[p[c].r ].sum + query(pos,p[c].l,l,m);
 
    }
    else return query(pos,p[c].r,m+1,r);
}
class print_writer {
public:
    template<class T>
    inline void print(T x) {
        static int a[30], cnt;
        if (x == 0) {
            pc(48);
        } else {
            if (x < 0) pc(45), x = -x;
            for (cnt = 0; x; x /= 10) a[++cnt] = x % 10 + 48;
            for(;cnt;)
                pc((char)a[cnt--]);
        }
    }
    inline void print(const char * s) {
        static int i;
        for (i = 0; s[i]; ++i) pc(s[i]);
    }
    inline void print(char c) {
        pc(c);
    }
    inline void print(const string &s) {
        for (const auto&c : s) pc(c);
    }
    template <typename T> inline void println(const T&x) {
        print(x), pc(10);
    }
    template <typename T> inline void prints(const T &x) {
        print(x), pc(' ');
    }
    inline void flush() {
        fwrite(obuf, 1, OUT_LEN, stdout), oh = obuf;
        fflush(stdout);
    }
    ~print_writer() {
        fwrite(obuf, 1, oh - obuf, stdout);
    }
private:
    static const int OUT_LEN = 1<<20;
    char obuf[OUT_LEN], *oh = obuf;
    inline void pc(char c) {
        if (oh == obuf + OUT_LEN)
            fwrite(obuf, 1, OUT_LEN, stdout), oh = obuf;
        *oh++ = c;
    }
 
}out;
inline char gc() {
    static char buf[1<<20], *head = buf, *tail = buf;
    return (head == tail && (tail = (head = buf) + fread(buf, 1, 1 << 20, stdin), head == tail)? -1: *head++);
}
template <typename T> inline bool read(T &x) {
    static bool f;
    static char c;
    for (c = gc(), f = false; !isdigit(c); c =gc()) {
        if (c == EOF)
            return false;
        else if (c == 45)
            f = true;
    }
    for (x = 0; isdigit(c); c = gc())
        x = x * 10 + c - 48;
    if (f)
        x = -x;
    return true;
}
void solve() {
    memset(la,-1,sizeof la);
    cnt = 0;
    //memset(rtt, 0, sizeof(rtt));
    for (int i = 1; i <= n; ++i){
        read(a[i]);
    }
    for (int i = n + 1; i <= 2 * n; ++i)
        a[i] = a[i - n];
    n *= 2;
    rtt[0] = build(1,n);
 
    for (int i = 1 ; i <= n; ++i){
        int v = a[i];
        if (la[v] == -1){
            rtt[i] = update(i,rtt[i-1],1,1,n);
        }
        else{
            int t = update(la[v],rtt[i-1],-1,1,n);
            rtt[i] = update(i,t,1,1,n);
        }
        la[v] = i;
    }
 
    while(q--){
        int x,y,l,r;
        read(l);
        read(r);
        x = r;
        y = l + n / 2;
        out.println(query(x,rtt[y],1,n));
    }
}
 
int main(){
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    while (read(n) && read(q)) solve();
    return 0;
}