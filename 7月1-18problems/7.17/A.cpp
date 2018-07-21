/*
 *      Author name: Wavator
 *      Mail: 11612908@mail.sustc.edu.cn
 * */
#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#define debug(...) fprintf(stderr, __VA_ARGS__), fprintf(stderr, "\n")
#else
#define debug(...) 42
#endif
#define rep(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define per(i, a, b) for (int (i) = (b) - 1; (i) >= (a); --(i))
#define REP(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
#define PER(i, a, b) for (int (i) = (b); i >= (a); --i)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vp;
const ll mod = (ll)1e9 + 7;
const db eps = 1e-9;
ll pow_mod(ll a, ll b = mod - 2) {
    ll res = 1;
    for (a %= mod; b; b >>= 1, a = a * a % mod) if (b & 1) res = res * a % mod;
    return res;
}
/*
 * head template
 */

int n;

//set<string > s;
//
//void dfs(int u, int f1, int f2, int tag, bitset<100> b) {
//    if (u == n) {
//        s.insert(b.to_string());
//        return;
//    }
//    if (f2) {
//        dfs(u + 1, 0, f1, 1, b);
//    } else if (f1) {
//        dfs(u + 1, 0, 1, 1, b);
//    } else {
//        dfs(u + 1, 0, 0, 0, b);
//        b[u] = 1;
//        dfs(u + 1, 1, 0, 1, b);
//    }
//}
ll ans[61], d[61];
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
//    for (n = 1; n <= 60; ++n) {
//        s.clear();
//        dfs(0, 0, 0, 0, bitset<100>{0});
//        cout << SZ(s) - 1<< endl;
//    }
    d[1] = 1;
    d[2] = 1;
    d[3] = 2;
    d[4] = 3;
    for (int i = 5; i < 61; ++i)
        d[i] = d[i - 1] + d[i - 3];
    ans[1] = 1;
    for (int i = 2; i < 61; ++i)
        ans[i] = ans[i - 1] + d[i - 1];

//#ifdef Wavator
//    for (int i = 1; i < 61; ++i) printf("%lld ", ans[i]);
//    puts("");
//#endif
    int x;
    while (~scanf("%d", &x)) printf("%lld\n", ans[x]);
    return 0;
}