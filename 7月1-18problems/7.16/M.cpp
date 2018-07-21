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
const ull mod[2] = {1000000000000000007ull, 1000000000000000009ull};
const ull bas[2] = {131, 151};
const int N = 600005;
ull powers[2][N];
set<pair<ull, ull> > st;
inline pair<ull, ull> get_hash(const string &s) {
    int n = SZ(s);
    static ull res[2];
    res[0] = res[1] = 0;
    rep(i, 0, n) {
        ull c = s[i] - 'a' + 1;
        rep(j, 0, 2) {
            res[j] += powers[j][i] * c % mod[j];
            res[j] %= mod[j];
        }
    }
    return make_pair(res[0], res[1]);
}

inline bool gao(const string &s) {
    int n = s.size();
    pair<ull, ull> pre = get_hash(s);
    //static ull b[2];
    rep(i, 0, n) {
        ull c = s[i] - 'a' + 1;
        for (ull j = 1; j <= 3; ++j) {
            if (j != c) {
                static ull a[2];
                a[0] = pre.fi, a[1] = pre.se;
                rep(k, 0, 2) {
                    a[k] = (a[k] - c * powers[k][i] % mod[k] +  j * powers[k][i] % mod[k] + mod[k]) % mod[k];
                }
                if(st.count({a[0], a[1]})) return true;
            }
        }
    }
    return false;
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    rep(i, 0, 2) powers[i][0] = 1;
    rep(i, 1, N) rep(j, 0, 2) powers[j][i] = powers[j][i - 1] * bas[j] % mod[j];
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    string s;
    rep(i, 0, n) {
        cin >> s;
        st.insert(get_hash(s));
    }
    rep(i, 0, m) {
        cin >> s;
        puts(gao(s)? "YES": "NO");
    }
    return 0;
}