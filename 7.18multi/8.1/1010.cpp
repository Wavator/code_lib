#pragma optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, a, n) for(int i=(a);i<(n);++i)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
#ifdef Wavator
#define debug(fmt, ...) fprintf(stderr, "func[%s] line %d: %s = " fmt "\n", \
                __func__, __LINE__, #__VA_ARGS__, __VA_ARGS__), fflush(stderr)
#define err(x) cerr << "func[" << __func__ << "] line " << __LINE__ << ": " \
                    << #x << " = " << x << endl << flush
#else
#define debug(...) 99
#define err(x) 99
#endif
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
const ll mod = (ll)1e9 + 7;
ll pow_mod(ll a, ll b) {
    assert(b >= 0);ll res=1;
    for (a %= mod; b; b >>= 1, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}
const int N = 16;
int matrix[N][N];

inline void left_rotate(int row, int column) {
    static int t[4][4];
    row <<= 2; column <<= 2;
    rep(i, 0, 4) rep(j, 0, 4) t[i][j] = matrix[row + 3 - j][i + column];
    rep(i, 0, 4) rep(j, 0, 4) matrix[i + row][j + column] = t[i][j];
}

vector<int> r_set, c_set;

inline bool check(int row, int column) {
    row <<= 2, column <<= 2;
    rep(i, row, row + 4) {
        rep(j, column, column + 4) {
            if (r_set[i] & matrix[i][j]) return false;
            if (c_set[j] & matrix[i][j]) return false;
        }
    }
    return true;
}

inline void push(int r, int c) {
    r <<= 2, c <<= 2;
    rep(i, r, r + 4) {
        rep(j, c, c + 4) {
            r_set[i] |= matrix[i][j];
            c_set[j] |= matrix[i][j];
        }
    }
}

int ans;
void dfs(int r, int c, int step) {
    if (ans <= step) return;
    if (r == 4) {
        ans = step;
        return;
    }
    if (c == 4) {
        dfs(r + 1, 0, step);
        return;
    }
    vi a, b;
    if (check(r, c)) {
        a = r_set;
        b = c_set;
        push(r, c);
        dfs(r, c + 1, step);
        r_set = a;
        c_set = b;
    }
    left_rotate(r, c);
    if (check(r, c)) {
        a = r_set;
        b = c_set;
        push(r, c);
        dfs(r, c + 1, step + 1);
        r_set = a;
        c_set = b;
    }
    left_rotate(r, c);
    if (check(r, c)) {
        a = r_set;
        b = c_set;
        push(r, c);
        dfs(r, c + 1, step + 2);
        r_set = a;
        c_set = b;
    }
    left_rotate(r, c);
    if (check(r, c)) {
        a = r_set;
        b = c_set;
        push(r, c);
        dfs(r, c + 1, step + 3);
        r_set = a;
        c_set = b;
    }
    left_rotate(r, c);
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int T;
    for (scanf("%d", &T); T--; ) {
        static char temp[17];
        rep(i, 0, 16) {
            scanf("%s", temp);
            rep(j, 0, 16) {
                static int x;
                x = (isdigit(temp[j])? temp[j] - 48: temp[j] - 'A' + 10);
                matrix[i][j] = (1 << x);
            }
        }
        r_set.assign(16, 0);
        c_set.assign(16, 0);
        ans = INT_MAX;
        dfs(0, 0, 0);
        printf("%d\n", ans);
    }
    return 0;
}