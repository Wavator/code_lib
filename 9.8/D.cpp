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
vector<pii> e[N], re[N];
int n, m, k, T, s, t;
bool vis[N];
int dis[N];
struct node {
    int v, v1, v2;

    bool operator<(const node &rhs) const {
        if (v1 == rhs.v1) return v2 > rhs.v2;
        return v1 > rhs.v1;
    }
};

inline int A_st() {
    int cnt = 0;
    if(s == t) k++;
    if(dis[s] > T) {
        return T + 1;
    }
    priority_queue<node> pq;
    pq.push((node) {s, dis[s], 0});
    while(!pq.empty()) {
        node cur = pq.top(); pq.pop();
        if(cur.v == t) cnt++;
        if(cnt == k) {
            return cur.v2;
        }
        for(auto&eg: re[cur.v]) {
            node nxt; nxt.v = eg.first;
            nxt.v2 = cur.v2 + eg.second;
            nxt.v1 = nxt.v2 + dis[nxt.v];
            pq.push(nxt);
        }
    }
    return T + 1;
}

int main() {
    while (read(n, m)) {
        sc(s, t);
        sc(k, T);
        for (int i = 0; i <= n; ++i) {
            e[i].clear();
            re[i].clear();
            vis[i] = 0;
            dis[i] = 0x3f3f3f3f;
        }
        rep(i, 0, m) {
            int u, v, w;
            sc(u, v);
            sc(w);
            re[u].emplace_back(v, w);
            e[v].emplace_back(u, w);
        }
        priority_queue<pii> q;
        q.emplace(dis[t] = 0, t);
        while (!q.empty()) {
            int u = q.top().second;
            q.pop();
            if (vis[u]) {
                continue;
            }
            vis[u] = 1;
            for (auto &eg:e[u]) {
                int v = eg.first, w = eg.second;
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    q.emplace(-dis[v], v);
                }
            }
        }
        int t = A_st(); //cerr << dis[1] << ' ' << dis[2] << endl;debug(t);
        puts(t <= T ? "yareyaredawa" : "Whitesnake!");
    }
    return 0;
}
