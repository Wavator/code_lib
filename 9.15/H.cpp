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

namespace cnm {

    const int N = 2e5 + 2;
    char s[N];
    int n;
    int result[N];

    int nxt[N * 2][26], pa[N * 2], wyc[N * 2];
    int lst, cnt;

    int cnt_cc[N * 2], A[N * 2];
    int des[N * 2];


    inline int idx(int c) {
        return c - 'A';
    }

    void add(int c) {
        int p = lst;
        int np = ++cnt;
        memset(nxt[cnt], 0, sizeof nxt[cnt]);
        wyc[np] = wyc[p] + 1;
        lst = np;
        while (p && !nxt[p][c])nxt[p][c] = np, p = pa[p];
        if (!p)pa[np] = 1;
        else {
            int q = nxt[p][c];
            if (wyc[q] == wyc[p] + 1)pa[np] = q;
            else {
                int nq = ++cnt;
                wyc[nq] = wyc[p] + 1;
                memcpy(nxt[nq], nxt[q], sizeof(nxt[q]));
                pa[nq] = pa[q];
                pa[np] = pa[q] = nq;
                while (nxt[p][c] == q)nxt[p][c] = nq, p = pa[p];
            }
        }
    }


    int main() {
        int L, R;
        while (~scanf("%s%d%d", s, &L, &R)) {
            n = strlen(s);
            lst = cnt = 1;
            pa[1] = wyc[1] = 0;
            memset(nxt[1], 0, sizeof nxt[1]);
            rep(i, 0, n) {
                add(idx(s[i]));
            }
            memset(cnt_cc, 0, sizeof cnt_cc);
            memset(des, 0, sizeof des);
            for (int i = 1; i <= cnt; i++)cnt_cc[wyc[i]]++;
            for (int i = 1; i <= n; i++)cnt_cc[i] += cnt_cc[i - 1];
            for (int i = cnt; i >= 1; i--)A[cnt_cc[wyc[i]]--] = i;
            int temp = 1;
            for (int i = 0; i < n; i++) {
                des[temp = nxt[temp][idx(s[i])]] = 1;
            }
            for (int i = cnt; i >= 1; i--) {
                int x = A[i];
                des[pa[x]] += des[x];
                result[wyc[x]] = max(result[wyc[x]], des[x]);
            }
            for (int i = wyc[lst]; i > 1; i--) {
                result[i - 1] = max(result[i - 1], result[i]);
            }
            ll res = 0;
//            debug(vector<int>(l, l + 20));
//            debug(vector<int>(fa, fa + 20));
//            debug(cnt);
            for (int i = 2; i <= cnt; ++i) {
                if (des[i] >= L && des[i] <= R) {
                    res += (wyc[i] - wyc[pa[i]]);
                }
            }
            printf("%lld\n", res);
        }
        return 0;
    }
}

int main() {
    return cnm::main();
}
