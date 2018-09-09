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

map<pii, int> ths, res;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        ths.clear();
        res.clear();
        int n, qns = 0;
        scanf("%d", &n);
        rep(i, 0, n) {
            int t;
            scanf("%d", &t);
            rep(j, 0, t) {
                int x, y;
                scanf("%d%d",&x, &y);
                if (ths.count({x,y})&& ths[{x,y}] == i) continue;
                if (ths.count({x,y})) {
                    if (ths[{x,y}] == i - 1) {
                        res[{x, y}]++;
                    }
                    else {
                        res[{x,y}] = 1;
                    }
                    qns = max(res[{x,y}], qns);
                } else {
                    res[{x, y}
                    ] = 1, qns = max(qns, 1);
                }
                ths[{x,y}] = i;
            }
        }
        printf("%d\n", qns);
    }
    return 0;
}
