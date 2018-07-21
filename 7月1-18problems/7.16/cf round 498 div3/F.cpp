#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#define debug(...) fprintf(stderr, __VA_ARGS__), fprintf(stderr, "\n")
#else
#define debug(...) 98
#define cerr if(false)cout
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
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int oo = 0x3f3f3f3f;
const int N = 22;
int n, m;
ll a[N][N];

const int dx[2][2] = {{-1, 0}, {1, 0}};
const int dy[2][2] = {{0, -1}, {0, 1}};
map<ll, int> mp[2];

inline bool check(int x, int y) {
    return x > 0 && x <= n && y > 0 && y <= m;
}

void dfs(int x, int y, ll now, const int & f) {
    static int tx, ty;
    now ^= a[x][y];
    rep(i, 0, 2) {
        tx = x + dx[f][i], ty = y + dy[f][i];
        if (check(tx, ty))
            dfs(tx, ty, now, f);
    }
    if (x == 1 && y == 1 && !f) mp[f][now]++;
    if (x == n && y == m && f) mp[f][now]++;
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    ll k;
    scanf("%d%d%lld", &n, &m, &k);
    REP(i, 1, n) REP(j, 1, m) scanf("%lld", &a[i][j]);
    ll ans = 0;
    int len = n + m;
    len >>= 1;
    REP(i, 1, n) {
        int j = len - i + 1;
        if (!check(i, j)) continue;
        rep(r, 0, 2) mp[r].clear();
        rep(r, 0, 2) dfs(i, j, 0, r);
        ll now = k ^ a[i][j];
        for (const auto &xx: mp[0]) {
            ans += 1ll * xx.second * mp[1][now ^ xx.first];
        }
    }
    return !printf("%lld\n", ans);
}