#include <bits/stdc++.h>

using namespace std;

#pragma optimize("-O3")

#pragma optimize("-unroll-loops")

#define pb push_back

#ifdef Wavator

#define dbg(...) fprintf(stderr, __VA_ARGS__)
#define de(x) cerr << #x << " = " << x << endl;

#else

#define dbg(...) 98;

#define cerr if (false) cout

#define de(x) 98;

#endif

#define all(x) (x).begin(), (x).end()

#define CIN cin.sync_with_stdio(false), cin.tie(nullptr);
#define COUT cout.sync_with_stdio(false), cout.tie(nullptr);


#define rep(i, a, b) for (int (i) = (a); (i) < (b); ++(i))

#define szz(x) int((x).size())

#define sc(x) static_cast<(x)>

#define Fi first
#define Se second

typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<db> vb;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unsigned int uint;

template <typename T> inline bool read(T &x) {
    char c = getchar();
    bool f = false;
    for (x = 0; !isdigit(c); c = getchar()) {
        if (c == EOF)
            return false;
        if (c == '-') {
            f = true;
        }
    }
    for (; isdigit(c); c = getchar()) {
        x = x * 10 + c - '0';
    }
    if (f) {
        x = -x;
    }
    return true;
}

template <typename A, typename B> inline bool read(A &x, B&y) {
    return read(x) && read(y);
}

template <typename A, typename B, typename C> inline bool read(A &x, B &y, C &z) {
    return read(x) && read(y) && read(z);
}

template <typename A, typename B, typename C, typename D> inline bool read(A &a, B &b, C &c, D &d) {
    return read(a) && read(b) && read(c) && read(d);
}

template <typename T> inline void read(vector<T> &now, const uint &sz) {
    now.resize(sz);
    for (auto &v: now)  read(v);
}

template <typename T> inline bool cma(T &a, const T &b) {
    return a < b ? a = b, true : false;
}

template <typename T> inline bool cmi(T &a, const T &b) {
    return a > b ? a = b, true : false;
}

const db eps = 1e-9, PI = acos(-1);
const ll INF = 0x3f3f3f3f3f3f3f3f, mod = 1000000007;
const int inf = 0x3f3f3f3f;

ll powMod(ll a, ll b) {
    ll res = 1;
    for (a %= mod; b; b >>= 1, a = a * a % mod)     if (b & 1)
            res = res * a % mod;
    return res;
}
const int NN = 100005;

bool ck(const string &s) {
    for (int i = 0; i < s.size() / 2; ++i)
        if (s[i] != s[s.size() - i - 1])
            return 0;
    return 1;
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    CIN;
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = n - i; j >= 0; --j)
            if (!ck(s.substr(i, j)))
                ans = max(ans, j);
    }
    cout << ans << endl;
    return 0;
}
