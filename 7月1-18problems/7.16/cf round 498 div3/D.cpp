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

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    function<int(char, char, char, char)> gao = [&](char a, char b, char c, char d) {
        vi q{a, b, c, d};
        sort(all(q));
        if (q[0] == q[1]&&q[2]==q[3]) {
            return 0;
        }
        else if (q[0] == q[1] || q[1] == q[2] || q[2] == q[3]) {
            if (a == b && !(a == c || a == d))return 2;
            else return 1;
        }
        else return 2;
    };
    int n;
    string a, b;
    cin >> n >> a >> b;
    int ans = 0;
    rep(i, 0, n) {
        if (i >= n / 2)break;
        int tmp = gao(a[i], a[n - i - 1], b[i], b[n - i - 1]);
        if (tmp == 1)
            ans++;
        else if (tmp == 2) ans += 2;
    }
    if (n & 1) {
        if (a[n / 2] ^ b[n / 2])
            ans++;
    }
    return !printf("%d\n", ans);
}