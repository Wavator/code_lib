//while (clock()<=4.9*CLOCKS_PER_SEC)
#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
const int N = 100005;
ll a[N];
ll pre[N], E[N << 2], lzy[N << 2];

void build(int o, int l, int r) {
    lzy[o] = 0;
    if(l == r) {
        E[o] = pre[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(o << 1, l, mid);
    build(o << 1 | 1, mid + 1, r);
    E[o] = E[o << 1] + E[o << 1 | 1];
}

ll ask(int o, int l, int r, int L, int R) {
    //debug(o, l, r, L, R);
    if(L <= l && R >= r) {
        return E[o];
    }
    if(lzy[o]) {
        int mid = (l + r) >> 1, ls = o << 1, rs = ls | 1;
        E[ls] += lzy[o] * (mid - l + 1);
        lzy[ls] += lzy[o];
        E[rs] += lzy[o] * (r - mid);
        lzy[rs] += lzy[o];
        lzy[o] = 0;
    }
    int mid = (l + r) >> 1;
    ll res = 0;
    if(L <= mid) {
        res += ask(o << 1, l, mid, L, R);
    }
    if(R > mid) {
        res += ask(o << 1 | 1, mid + 1, r, L, R);
    }
    return res;
}
void update(int o, int l, int r, int L, int R, ll v) {
    if (L <= l && R >= r) {
        lzy[o] += v;
        E[o] += v * (r - l + 1);
        return;
    }
    if (lzy[o]) {
        int mid = (l + r) >> 1, ls = o << 1, rs = ls | 1;
        E[ls] += lzy[o] * (mid - l + 1);
        lzy[ls] += lzy[o];
        E[rs] += lzy[o] * (r - mid);
        lzy[rs] += lzy[o];
        lzy[o] = 0;
    }
    int mid = (l + r) >> 1;
    if (L <= mid) {
        update(o << 1, l, mid, L, R, v);
    }
    if (R > mid) {
        update(o << 1 | 1, mid + 1, r, L, R, v);
    }
    E[o] = E[o << 1] + E[o << 1 | 1];
}
int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + a[i];
    build(1, 1, n);
    debug("build");
    while(q--) {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        debug(op,x,y);
        if (op == 1) {
            ll ans = ask(1, 1, n, x, y);
            printf("%lld\n", x <= 1? ans: ans - ask(1, 1, n, x - 1, x - 1) * (y - x + 1));
        } else {
            update(1, 1, n, x, n, y - a[x]);
            a[x] = y;
        }
    }
    return 0;
}