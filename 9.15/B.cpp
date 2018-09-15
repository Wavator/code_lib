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
#define int long long
template <size_t N, int INF = 1ll<<61>
struct seg_tree {
    int mx[N << 2], mi[N << 2];

    inline void push_up(int rt) {
        mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]   );
        mi[rt] = min(mi[rt << 1], mi[rt << 1 | 1]   );
    }

    void build() {
        for (int i = 0; i < (N << 2); ++i) {
            mx[i] = -INF;
            mi[i] = INF;
        }
    }

    void change_min(int pos, int v, int l, int r, int rt) {
        if (l == r) {
            mi[rt] = v;
            return;
        }
        int mid = l + r >> 1;
        if (pos <= mid) {
            change_min(pos, v, l, mid, rt << 1);
        } else {
            change_min(pos, v, mid + 1, r, rt << 1 | 1);
        }
        push_up(rt);
    }

    void change_max(int pos, int v, int l, int r, int rt) {
        if (l == r) {
            mx[rt] = v;
            return;
        }
        int mid = l + r >> 1;
        if (pos <= mid) {
            change_max(pos, v, l, mid, rt << 1);
        } else {
            change_max(pos, v, mid + 1, r, rt << 1 | 1);
        }
        push_up(rt);
    }

    int query_max(int L, int R, int l, int r, int rt) {
        if (l >= L && r <= R) {
            return mx[rt];
        }
        int mid = l + r >> 1;
        if (L > mid) {
            return query_max(L, R, mid + 1, r, rt << 1 | 1);
        } else if (R <= mid) {
            return query_max(L, R, l, mid, rt << 1);
        } else {
            return max(query_max(L, R, l, mid, rt << 1), query_max(L, R, mid + 1, r, rt << 1 | 1));
        }
    }

    int query_min(int L, int R, int l, int r, int rt) {
        if (l >= L && r <= R) {
            return mi[rt];
        }
        int mid = l + r >> 1;
        if (L > mid) {
            return query_min(L, R, mid + 1, r, rt << 1 | 1);
        } else if (R <= mid) {
            return query_min(L, R, l, mid, rt << 1);
        } else {
            return min(query_min(L, R, l, mid, rt << 1), query_min(L, R, mid + 1, r, rt << 1 | 1));
        }
    }


    void show() {
        //debug(vector<ll>(mx, mx + 20));
    }
};
constexpr int N = 1005;
seg_tree<N> tree;


signed main() {
    int T;
    scanf("%lld", &T);
    while (T--) {
        int n, m, K;
        scanf("%lld%lld%lld", &n, &m, &K);
        vector<long long> a(n);
        for (auto &x:a)scanf("%lld", &x);
        tree.build();
        static char op[22];
        scanf("%s", op);
        rep(i, 0, n) {
            tree.show();
            if (op[0] == '-') {
                tree.change_max(i + 1, K - a[i], 1, n, 1);
//                debug(K - a[i]);
                tree.change_min(i + 1, K - a[i], 1, n, 1);
            } else if (op[0] == '+') {
                tree.change_max(i + 1, K + a[i], 1, n, 1);
//                debug(K - a[i]);
                tree.change_min(i + 1, K + a[i], 1, n, 1);
            } else if (op[0] == '*') {
                tree.change_max(i + 1, K * a[i], 1, n, 1);
//                debug(K - a[i]);
                tree.change_min(i + 1, K * a[i], 1, n, 1);
            } else {
                tree.change_max(i + 1, K / a[i], 1, n, 1);
//                debug(K - a[i]);
                tree.change_min(i + 1, K / a[i], 1, n, 1);
            }
            tree.show();
        }
        rep(j, 1, m) {
            per(k, 0, n) {
                if (k >= j) {
                    auto L = tree.query_max(1, k, 1, n, 1);
                    auto R = tree.query_min(1, k, 1, n, 1);
                    //cerr << op[j] << endl;
                    if (op[j] == '+') {
                        tree.change_max(k + 1, L + a[k], 1, n, 1);
                        tree.change_min(k + 1, R + a[k], 1, n, 1);
                    } else if (op[j] == '-') {
                        tree.change_max(k + 1, L - a[k], 1, n, 1);
                        tree.change_min(k + 1, R - a[k], 1, n, 1);
                    } else if (op[j] == '*') {
                        tree.change_max(k + 1, max(L * a[k], R * a[k]), 1, n, 1);
                        tree.change_min(k + 1, min(L * a[k], R * a[k]), 1, n, 1);
                    } else {
                        tree.change_max(k + 1, max(L / a[k], R / a[k]), 1, n, 1);
                        tree.change_min(k + 1, min(L / a[k], R / a[k]), 1, n, 1);
                    }
                } else {
                    tree.change_max(k + 1, -(1ll << 61), 1, n, 1);
                    tree.change_min(k + 1, 1ll << 61, 1, n, 1);
                }
            }
        }
        //assert(tree.query_max(1, n, 1, n, 1) == tree.mx[1]);
        printf("%lld\n", tree.query_max(1, n, 1, n, 1));
    }
    return 0;
}
