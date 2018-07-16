#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#define debug(...) cerr << #__VA_ARGS__ << " = " << __VA_ARGS__ << " "
#else
#define debug(...) 42
#endif
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define SZ(x) ((int)(x).size())
#define pb push_back
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef vector <int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const db eps = 1e-9, PI = acos(-1);
const int oo = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7, OO = 1ll << 62;
ll pow_mod(ll a, ll b, ll mod = ::mod) {
    assert(b >= 0); ll res = 1;
    for (a %= mod; b; b >>= 1, a = a * a % mod) if (b & 1) res = res * a % mod;
    return res;
}

inline char gc() {
    static char buf[1<<20], *head = buf, *tail = buf;
    return (head == tail && (tail = (head = buf) + fread_unlocked(buf, 1, 1 << 20, stdin), head == tail)? -1: *head++);
}

#ifdef Wavator
#define gc getchar
#endif

template <typename T> inline bool read(T &x) {
    static bool f;
    static char c;
    for (c = gc(), f = false; !isdigit(c); c = gc()) {
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
const int N = 100005 << 2;

ll a[N];int mi[N], ma[N], tag[N];

inline void push_up(int rt) {
    a[rt] = a[rt << 1] + a[rt << 1 | 1];
    mi[rt] = min(mi[rt << 1], mi[rt << 1 | 1]);
    ma[rt] = max(ma[rt << 1], ma[rt << 1 | 1]);
}

inline void push_down(int rt, ll le, ll ri) {
    if (tag[rt]) {
        a[rt << 1] += le * tag[rt];
        a[rt << 1 | 1] += ri * tag[rt];

        mi[rt << 1 | 1] += tag[rt];
        mi[rt << 1] += tag[rt];

        ma[rt << 1 | 1] += tag[rt];
        ma[rt << 1] += tag[rt];

        tag[rt << 1 | 1] += tag[rt];
        tag[rt << 1] += tag[rt];

        tag[rt] = 0;
    }
}

inline void build(int l, int r, int rt) {
    if (l == r) {
        read(mi[rt]);
        a[rt] = ma[rt] = mi[rt];
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
    push_up(rt);
}

inline void add(int L, int R, int l, int r, int rt, ll val) {
    if (l >= L && r <= R) {
        a[rt] += 1ll * (r - l + 1) * val;
        mi[rt] += val;
        ma[rt] += val;
        tag[rt] += val;
        return;
    }
    int mid = l + r >> 1;
    push_down(rt, mid - l + 1, r - mid);
    if (L <= mid)
        add(L, R, l, mid, rt << 1, val);
    if (R > mid)
        add(L, R, mid + 1, r, rt << 1 | 1, val);
    push_up(rt);
}


inline void D(int L, int R, int l, int r, int rt, ll val) {
    if (l >= L && r <= R) {
        static ll x, y;
        if (ma[rt] >= 0)
            x = ma[rt] / val;
        else
            x = ma[rt] / val - (ma[rt] % val != 0);
        if (mi[rt] >= 0)
            y = mi[rt] / val;
        else
            y = mi[rt] / val - (mi[rt] % val != 0);

        debug(L), debug(R), debug(l), debug(r), debug(val);
        debug(endl);
        debug(ma[rt]), debug(x);
        debug(endl);
        debug(mi[rt]), debug(y);
        debug(endl);


        if (ma[rt] - x == mi[rt] - y) {

            val = x - ma[rt];

            debug(val);

            a[rt] += 1ll * (r - l + 1) * val;
            ::mi[rt] += val;
            ::ma[rt] += val;
            tag[rt] += val;

            return;
        }
    }
    int mid = l + r >> 1;
    push_down(rt, mid - l + 1, r - mid);
    if (L <= mid)
        D(L, R, l, mid, rt << 1, val);
    if (R > mid)
        D(L, R, mid + 1, r, rt << 1 | 1, val);
    push_up(rt);
}

inline int query_min(int L, int R, int l, int r, int rt) {
    if (l >= L && r <= R)
        return mi[rt];
    int mid = l + r >> 1;
    push_down(rt, mid - l + 1, r - mid);
    if (L > mid)
        return query_min(L, R, mid + 1, r, rt << 1 | 1);
    else if (R <= mid)
        return query_min(L, R, l, mid, rt << 1);
    return min(query_min(L, R, mid + 1, r, rt << 1 | 1), query_min(L, R, l, mid, rt << 1));
}

inline ll query_sum(int L, int R, int l, int r, int rt) {
    if (l >= L && r <= R)
        return a[rt];
    int mid = l + r >> 1;
    push_down(rt, mid - l + 1, r - mid);
    if (L > mid)
        return query_sum(L, R, mid + 1, r, rt << 1 | 1);
    else if (R <= mid)
        return query_sum(L, R, l, mid, rt << 1);
    return query_sum(L, R, l, mid, rt << 1) + query_sum(L, R, mid + 1, r, rt << 1 | 1);
}

int main() {
    int n, m;
    read(n);
    read(m);
    build(1, n, 1);

    while (m--) {
        static int op, l, r, c;
        read(op);
        read(l);
        read(r);
        l++;
        r++;
        if (op < 3) {
            read(c);
            if(op & 1)
                add(l, r, 1, n, 1, c);
            else
                D(l, r, 1, n, 1, c);
        } else {
            if(op & 1)
                printf("%d\n", query_min(l, r, 1, n, 1));
            else
                printf("%lld\n", query_sum(l, r, 1, n, 1));
        }
    }
    return 0;
}