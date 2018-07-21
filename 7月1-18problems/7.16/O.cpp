#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#define debug(...) fprintf(stderr, __VA_ARGS__), fprintf(stderr, "\n")
#else
#define debug(...) 98
#define cerr if (false) cout
#endif

#define rep(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define per(i, a, b) for (int (i) = (b) - 1; (i) >= (a); --(i))
#define REP(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int oo = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;
const ull hash_base = 19260817;
const int N = 30005, M = 250;
ull hash_pow[M];

ull H[N][M];
ull hash_val[N];
char str[N];
int n, l, s;

inline bool ck_prime(int val) {
    for (int i = 2; i * i <= val; ++i) {
        if (val % i == 0)
            return false;
    }
    return true;
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    //cout << ck_prime(hash_base) << endl;
    scanf("%d%d%d", &n, &l, &s);
    hash_pow[0] = 1;
    rep(i, 1, M) hash_pow[i] = hash_pow[i - 1] * hash_base;
    rep(i, 0, n) {
        scanf("%s", str + 1);
        H[i][l] = 0;
        rep(j, 1, l + 1)
            H[i][j] = H[i][j - 1] * hash_base + str[j];
    }
    ll ans = 0;
    rep(len, 1, l + 1) {
        rep(j, 0, n) {
            hash_val[j] = H[j][l] - H[j][len] * hash_pow[l - len] + H[j][len - 1] * hash_pow[l - len + 1];
        }
        sort(hash_val, hash_val + n);
        //rep(i, 0, n) debug("%lld ", hash_val[i]);
        int cnt = 0;
        rep(j, 0, n - 1) {
            if (hash_val[j] == hash_val[j + 1]) {
                cnt++;
            } else {
                cnt = 0;
            }
            ans += cnt;
        }
    }
    cout << ans << '\n';
    return 0;
}s