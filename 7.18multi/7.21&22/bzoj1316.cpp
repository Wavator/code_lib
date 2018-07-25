/**************************************************************
    Problem: 1316
    User: Wavator
    Language: C++
    Result: Accepted
    Time:1708 ms
    Memory:3212 kb
****************************************************************/
 
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
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef vector<int> vi;typedef pair<int,int> pii;
inline char gc() { static char buf[1<<20],*h=buf,*t=buf;return (h==t&&(t=(h=buf)+fread(buf,1,1<<20,stdin),h==t)?-1:*h++);}
template <typename T> inline bool read(T &x){static int f;static char c;for(c=gc(),f=1;!isdigit(c);c=gc()){if(c==-1)return false;else if(c==45)f=-1;}for(x=c-48;isdigit(c=gc());x=x*10+c-48);return x*=f,true; }
/*
 * head template
 */
 
const int maxn = 10010, maxq = 101;
 
struct edge {
    int y, w;
    edge *next;
};
 
edge* li[maxn];
 
inline void add_edge(int u, int v, int w) {
    //cerr << u << ' ' << v << ' ' << w << endl;
    static edge e[maxn<<1];
    static edge * top = e;
    li[u] = &(*top++ = (edge){v, w, li[u]});
    li[v] = &(*top++ = (edge){u, w, li[v]});
}
 
int sz[maxn], best[maxn], tot, root;
 
bool vis[maxn];
 
void get_root(int u, int fa) {
    sz[u] = 1;
    best[u] = 0;
    for (edge * t = li[u]; t; t = t->next) {
        int v = t->y;
        if (v != fa && !vis[v]) {
            get_root(v, u);
            sz[u] += sz[v];
            best[u] = max(best[u], sz[v]);
        }
    }
    best[u] = max(best[u], tot - best[u]);
    if (root == 0 || best[u] < best[root]) root = u;
}
 
int n;
 
int Q[maxq], q;
bool solved[maxq];
set<int> s;
 
void solve(int u, int fa, int len, bool f = false) {
    if (f) s.insert(len);
    else rep(i, 0, q) if (s.count(Q[i] - len)) solved[i] = true;// cerr << i << ' ' << len << ' ' << Q[i] << ' ' << u << endl;
    for (edge * t = li[u]; t; t = t->next) {
        int v = t->y;
        if (!vis[v] && v != fa) {
            solve(v, u, len + t->w, f);
        }
    }
}
 
 
void gao(int u) {
 
    vis[u] = true;
    s.clear();
 
    for (edge * t = li[u]; t; t = t->next) {
        int v = t->y;
        if (!vis[v]) {
            solve(v, u, t->w);
            solve(v, u, t->w, true);
        }
    }
 
    rep(i, 0, q) if (s.count(Q[i])) solved[i] = true;
 
 
    for (edge * t = li[u]; t; t = t->next){
 
        int v = t->y;
 
        if (!vis[v]) {
 
            tot = sz[v];
 
            root = 0;
 
            get_root(v, 0);
 
            gao(root);
 
        }
 
    }
 
}
 
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    read(n);
    read(q);
    rep(i, 1, n) {
        static int u, v, w;
        read(u), read(v), read(w);
        add_edge(u, v, w);
    }
    rep(i, 0, q) read(Q[i]);
    rep(i, 0, q) if (!Q[i]) solved[i] = true;
    tot = n;
    get_root(1, 0);
    gao(root);
    rep(i, 0, q) puts(solved[i]? "Yes": "No");
    return 0;
}