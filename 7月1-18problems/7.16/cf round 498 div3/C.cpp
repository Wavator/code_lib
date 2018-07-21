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
const int N = 200005;
int a[N];
ll s1[N], s2[N];
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    REP(i, 1, n) scanf("%d", &a[i]);
    REP(i, 1, n) {
        s1[i] = s1[i - 1] + a[i];
    }
    PER(i, 1, n) {
        s2[i] = s2[i + 1] + a[i];
    }
    int l = 1, r = n;
    ll ans = 0;
    while (l < r) {
        if (s1[l] == s2[r]) {
            ans = max(ans, s1[l]);
            l++;
        }
        else if (s1[l] > s2[r])
            r--;
        else
            l++;
    }
    return !printf("%lld\n", ans);
}