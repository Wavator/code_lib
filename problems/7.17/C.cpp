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
const int mod = (int)1e9 + 7;
const db eps = 1e-9;
int pow_mod(int a, int b = mod - 2) {
    int res = 1;
    for (a %= mod; b; b >>= 1, a = (ll)a * a % mod) if (b & 1) res = (ll)res * a % mod;
    return res;
}
/*
 * head template
 */
const int N = 1000001;

int fact[N], finv[N];

inline int C(int n, int m) {
    if (m > n) return 0;
    return (ll)((ll)fact[n] * finv[m] % mod) * finv[n - m] % mod;
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    fact[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = (ll)fact[i - 1] * i % mod;
    }
    finv[N - 1] = pow_mod(fact[N - 1]);
    for (int i = N - 2; ~i; --i) {
        finv[i] = (ll)finv[i + 1] * (i + 1) % mod;
    }
    int T;
    for (scanf("%d", &T); T--; ) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        if (m == 1) {
            printf("%d\n", n);
            continue;
        }
        int c = (ll)C(n - m * k - 1, m - 1) * n % mod;
        c = (ll) c * pow_mod(m) % mod;
        printf("%d\n", c);
    }
    return 0;
}