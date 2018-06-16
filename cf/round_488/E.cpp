#include <bits/stdc++.h>
using namespace std;
#define int long long
string to_string(string s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(const bool &b) {
    return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(const A &v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first)
            res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef local

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__);

#else

#define debug(...) 42;

#define cerr if (false) cout

#endif
template <typename T> inline bool ckmax(T &a, const T &b) {
    return a < b? a = b, true: false;
}

template <typename T> inline bool ckmin(T &a, const T&b) {
    return a > b? a = b, true: false;
}

#define pb push_back
#define SZ(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()

#define rall(x) (x).rbegin(), (x).rend()

#define rep(i, a, b) for (int i = (a), i##_end_ = b; i < i ##_end_; ++i)
#define per(i, a, b) for (int i = (b) - 1, i##_end_ = a; i >= i##_end_; --i)

#define FOR(i, n) for (int i = 1; i <= (n); ++i)

typedef long long ll;
typedef double db;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<db, db> pdb;
typedef vector<pair<int, int> > vp;

template <typename T> inline ll sqr(T x) {
    return 1ll * x * x;
}

const db PI = acos(-1), eps = 1e-9;
const ll mod = 1e9 + 7, OO = 0x3f3f3f3f3f3f3f3f;
const int oo = 0x3f3f3f3f;

ll powMod(ll a, ll b) {
    assert(b >= 0);
    ll res = 1;
    for (a %= mod; b; b >>= 1, a = a * a % mod) {
        if (b & 1) {
            res = res * a % mod;
        }
    }
    return res;
}

#define usingcin

#ifdef usingcin
#define scanf cnm
#define printf dsb
#define puts(s) cout << (s) << '\n';
#endif

#define cp_unique(a) a.resize(unique(a.begin(), a.end()) - a.begin())

#define endl '\n'

void solve();

signed main() {
#ifdef local
    freopen("test.in", "r", stdin);
#endif
#ifdef usingcin
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    solve();
    return 0;
}
#define inyt int
namespace fft
{
    typedef double db;

    struct cp
    {
        db x, y;
        cp() { x = y = 0; }
        cp(db x, db y) : x(x), y(y) {}
    };

    inline cp operator+(cp a, cp b) { return cp(a.x + b.x, a.y + b.y); }
    inline cp operator-(cp a, cp b) { return cp(a.x - b.x, a.y - b.y); }
    inline cp operator*(cp a, cp b) { return cp(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
    inline cp conj(cp a) { return cp(a.x, -a.y); }

    int base = 1;
    vector<cp> roots = {{0, 0}, {1, 0}};
    vector<int> rev = {0, 1};

    const db PI = acosl(-1.0);

    void ensure_base(int nbase)
    {
        if (nbase <= base) return;
        rev.resize(static_cast<unsigned long>(1 << nbase));
        for (int i = 0; i < (1 << nbase); i++)
            rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
        roots.resize(static_cast<unsigned long>(1 << nbase));
        while (base < nbase)
        {
            db angle = 2 * PI / (1 << (base + 1));
            for (int i = 1 << (base - 1); i < (1 << base); i++)
            {
                roots[i << 1] = roots[i];
                db angle_i = angle * (2 * i + 1 - (1 << base));
                roots[(i << 1) + 1] = cp(cos(angle_i), sin(angle_i));
            }
            base++;
        }
    }

    void fft(vector<cp>& a, int n = -1)
    {
        if (n == -1) n = a.size();
        assert((n & (n - 1)) == 0);
        int zeros = __builtin_ctz(n);
        ensure_base(zeros);
        int shift = base - zeros;
        for (int i = 0; i < n; i++)
            if (i < (rev[i] >> shift))
                swap(a[i], a[rev[i] >> shift]);
        for (int k = 1; k < n; k <<= 1)
            for (int i = 0; i < n; i += 2 * k)
                for (int j = 0; j < k; j++)
                {
                    cp z = a[i + j + k] * roots[j + k];
                    a[i + j + k] = a[i + j] - z;
                    a[i + j] = a[i + j] + z;
                }
    }

    vector<cp> fa, fb;

    vector<int> multiply(vector<int>& a, vector<int>& b)
    {
        int need = a.size() + b.size() - 1;
        int nbase = 0;
        while ((1 << nbase) < need) nbase++;
        ensure_base(nbase);
        int sz = 1 << nbase;
        if (sz > (int)fa.size())
            fa.resize(static_cast<unsigned long>(sz));
        for (int i = 0; i < sz; i++)
        {
            int x = (i < (int)a.size() ? a[i] : 0);
            int y = (i < (int)b.size() ? b[i] : 0);
            fa[i] = cp(x, y);
        }
        fft(fa, sz);
        cp r(0, -0.25 / sz);
        for (int i = 0; i <= (sz >> 1); i++)
        {
            int j = (sz - i) & (sz - 1);
            cp z = (fa[j] * fa[j] - conj(fa[i] * fa[i])) * r;
            if (i != j)
            {
                fa[j] = (fa[i] * fa[i] - conj(fa[j] * fa[j])) * r;
            }
            fa[i] = z;
        }
        fft(fa, sz);
        vector<int> res(static_cast<unsigned long>(need));
        for (int i = 0; i < need; i++)
        {
            res[i] = fa[i].x + 0.5;
        }
        return res;
    }
}; // namespace fft

const int N = 1 << 20;
int a[N], pre[N];

void solve()
{
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] < x)
            a[i] = 1;
        else
            a[i] = 0;
    }
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    vector<int> aa(2 * n + 2), bb(2 * n + 2);
    for (int i = 0; i <= n; i++) aa[n + pre[i]]++;
    for (int i = 0; i <= n; i++) bb[n - pre[i]]++;
    auto ans = fft::multiply(aa, bb);
    ans[n * 2] -= (n + 1);
    ans[n * 2] >>= 1;
    vector<int> real;
    for (int i = n * 2; i <= n * 3; i++) real.pb(ans[i]);
    for (auto& xx : real) cout << xx << ' ';
    return;
}
