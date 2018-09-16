//while (clock()<=4.9*CLOCKS_PER_SEC)
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
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
int a[35];

inline int cal(int x) {
    int cnt = 0;
    while (x) {
        ++cnt;
        x >>= 1;
    }
    return cnt;
}

int main() {
    int T;
    for (scanf("%d", &T); T--;) {
        int n;
        scanf("%d", &n);
        rep(i, 0, n) {
            int x;
            scanf("%d", &x);
            ++a[cal(x)];
        }
        printf("%d\n", *max_element(a,a+35));
        memset(a, 0, sizeof(a));
    }
    return 0;
}
