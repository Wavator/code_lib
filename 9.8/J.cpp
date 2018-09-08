//while (clock()<=4.9*CLOCKS_PER_SEC)
#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#ifndef Wavator
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#define unordered_map __gnu_pbds::cc_hash_table
#endif
using namespace std;
#ifdef Wavator
#include "local_debug.h"
#else
#define debug(...)
#endif
#define pb push_back
#define rep(i,a,n) for(int i=(a);i<(n);++i)
#define per(i,a,n) for(int i=(n)-1;i>=(a);--i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
constexpr db PI = acos(-1), eps = 1e-8;
constexpr ll mod = (ll)1e9 + 7;
ll pow_mod(ll a, ll b) {
    assert(b >= 0);
    ll res = 1;
    for (a %= mod; b; b >>= 1, a = a * a % mod) {
        if (b & 1) {
            res = res * a % mod;
        }
    }
    return res;
}
namespace Quick_in {
    const int LEN = (1 << 21) + 1;
    char ibuf[LEN], *iH, *iT;
    int f, c;
#define gc() (iH==iT?(iT=(iH=ibuf)+fread(ibuf,1,LEN,stdin),(iH==iT?EOF:*iH++)):*iH++)

    inline char nc() {
        while ((c = gc()) <= 32)if (c == -1)return -1;
        return (char) c;
    }

    template<class T>
    inline void sc(T &x) {
        for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
        for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15);
        x *= f;
    }

    template<class T>
    inline bool read(T &x) {
        for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) {
            if (c == -1)return 0;
            if (c == '-') f = -1;
        }
        for (x = c - 48;; x = x * 10 + (c & 15)) { if (!isdigit(c = gc()))break; }
        x *= f;
        return 1;
    }

    inline int gline(char *s) {
        int l = -1;
        for (c = gc(); c <= 32; c = gc())if (c == -1)return c;
        for (; c > 32 || c == ' '; c = gc()) {
            s[++l] = c;
        }
        s[++l] = 0;
        return l;
    }

    inline int gs(char *s) {
        int l = -1;
        for (c = gc(); c <= 32; c = gc())if (c == -1)return c;
        for (; c > 32; c = gc()) {
            s[++l] = c;
        }
        s[++l] = 0;
        return l;
    }

    template<typename A, typename B>
    inline void sc(A &x, B &y) { sc(x), sc(y); };

    template<typename A, typename B>
    inline bool read(A &x, B &y) { return read(x) && read(y); };
}

using Quick_in::sc;
using Quick_in::read;
using Quick_in::gline;
using Quick_in::gs;
using Quick_in::nc;

namespace Quick_out {
    static const int BUFFER_MAX_SIZE = 1 << 18;
    char buf[BUFFER_MAX_SIZE], *ph = buf, *pt = buf + BUFFER_MAX_SIZE;
    char tmp[100];
    const double dx[15] = {5e-1, 5e-2, 5e-3, 5e-4, 5e-5, 5e-6, 5e-7, 5e-8, 5e-9, 5e-10, 5e-11, 5e-12, 5e-13, 5e-14,
                           5e-15};

    inline void my_flush() {
        fwrite(buf, sizeof(char), ph - buf, stdout);
        ph = buf;
    }

    inline void oc(char c) {
        *(ph++) = c;
        if (ph == pt) my_flush();
    }

    inline void os(const char *s) {
        for (int i = 0; s[i]; ++i) oc(s[i]);
    }

    inline void os(const string &s) {
        os(s.c_str());
    }

    template<class T>
    inline void oi(T x, char ec = '\n') {
        if (x < 0) oc('-'), x = -x;
        int len = 0;
        if (!x) tmp[len++] = '0';
        for (; x;) tmp[len++] = x % 10 + '0', x /= 10;
        for (; len;) oc(tmp[--len]);
        oc(ec);
    }

    inline void od(double x, int fix = 8, char bc = '\n') {
        x += dx[fix];
        if (x < 0) oc('-'), x = -x;
        oi((long long) x, '.');
        x -= (long long) x;
        for (; fix--;) {
            x *= 10;
            oc('0' + (int) x);
            x -= (int) x;
        }
        oc(bc);
    }

    struct Quick_ {
        ~Quick_() { my_flush(); }
    } oooOoooOO;
}

using Quick_out::oi;
using Quick_out::oc;
using Quick_out::os;
using Quick_out::od;
const int N = 100005;

struct bit {
    ll a[N];
    int n;
    void init(int n) {
        this->n=n;
        for(int i=0;i<=n;++i)a[i]=0;
    }
    void add(int p,ll x) {
        for(;p<=n;p+=p&-p)a[p]+=x;
    }
    ll q(int p){
        ll s=0;
        for(;p;p-=p&-p)s+=a[p];
        return s;
    }
}fenwick;
vector<int> G[N],mp[N],large;
int dep[N];
int dfn[N], fin[N];
int clk;
int n, m;
const int block = 1000;
ll s[N];

void dfs(int now, int deep) {
    dfn[now] = ++clk;
    mp[deep].push_back(dfn[now]);
    for (auto &nex: G[now]) {
        dep[nex] = dep[now] + 1;
        dfs(nex, deep + 1);
    }
    fin[now] = clk;
}

int main() {
    while (read(n, m)) {
        memset(s, 0, sizeof(s));
        fenwick.init(n);
        for(int i = 0; i <= n; i++) mp[i].clear();
        large.clear();
        for(int i = 1; i <= n; i++)
            G[i].clear();
        int u, v;
        for(int i = 1; i < n; i++)
        {
            sc(u, v);
            G[u].push_back(v);
        }
        memset(dep, 0, sizeof(dep));
        clk = 0;
        dfs(1, 0);
        for(int i = 0; i <= n; i++) {
            if (mp[i].size() > block) {
                large.push_back(i);
            }
        }
        while(m--) {
            int op;
            sc(op);
            if(op == 1) {
                int l, y;
                sc(l, y);
                if(mp[l].size() <= block) {
                    for(auto&x: mp[l]) {
                        fenwick.add(x, y);
                    }
                }
                else s[l] += y;
            }
            else {
                int x;
                sc(x);
                int l = dfn[x], r = fin[x];
                ll ans = fenwick.q(r) - fenwick.q(l - 1);
                for(auto&wcy:large) {
                    ans += (upper_bound(mp[wcy].begin(), mp[wcy].end(), r) - lower_bound(mp[wcy].begin(), mp[wcy].end(), l)) * s[wcy];
                }
                oi(ans);
            }
        }
    }
    return 0;
}