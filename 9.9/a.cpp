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
const int mod = (int)1e9 + 7;

inline int sub(int a, int b) {
    a -= b;
    return a < 0? a + mod: a;
}

inline int mul(long long a, int b) {
    a *= b;
    return (int)(a < mod? a: a - a / mod * mod);
}

int power(int a, long long b) {
    int res = 1;
    for (; b; b >>= 1, a = mul(a, a)) {
        if (b & 1) {
            res = mul(res, a);
        }
    }
    return res;
}

int main() {
    int T;
    for (scanf("%d", &T); T--;) {
        int n, k;
        scanf("%d%d", &n, &k);
        int seed = power(2, k);
        int bases = sub(seed, 1);
        int ans = seed;
        int cpp = seed;
        int dqq = sub(cpp, 2);
        for (int i = 2; i <= n; i++) {
            ans = mul(ans, bases);
            if (i & 1) {
                ans = sub(ans, mul(cpp, dqq));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
