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
const int N = 2005;
int a[N], b[N], pos[N];
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int n, k;
    scanf("%d%d", &n, &k);
    rep(i, 0, n) scanf("%d", &a[i]), b[i + 1] = a[i];
    sort(a, a + n);
    reverse(a, a + n);
    int sum = 0;
    rep(i, 0, k) sum += a[i];
    unordered_multiset<int> s;
    rep(i, 0, k) s.insert(a[i]);
    int m = 1;
    REP(i, 1, n) {
        if (SZ(s) == 1) break;
        auto it = s.find(b[i]);
        if (it != s.end()) {
            pos[m++] = i;
            s.erase(it);
        }
    }
    printf("%d\n", sum);
    rep(i, 0, m - 1) printf("%d ", pos[i + 1] - pos[i]);
    printf("%d\n", n - pos[m - 1]);
    return 0;
}