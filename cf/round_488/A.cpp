#include <bits/stdc++.h>
using namespace std;

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

const db PI = acos(-1), eps = 1e-8;
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

int main() {
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

inline db cal(pair<db,db> p1, pair<db,db> p2, pair<db,db> p0) {
    return (p1.first - p0.first) * (p2.second - p0.second) - (p2.first - p0.first) * (p1.second - p0.second);
}

bool ck(pair<db,db> s1, pair<db,db> e1, pair<db,db> s2, pair<db,db> e2) {
    return (max(s1.first, e1.first) >= min(s2.first, e2.first)) &&
           (max(s2.first, e2.first) >= min(s1.first, e1.first)) &&
           (max(s1.second, e1.second) >= min(s2.second, e2.second)) &&
           (max(s2.second, e2.second) >= min(s1.second, e1.second)) &&
           (cal(s1, s2, e1) * cal(s1, e1, e2) > 0) &&
           (cal(s2, s1, e2) * cal(s2, e2, e1) > 0);
}

pair<db,db> geti(vector<pair<db,db> > a, vector<pair<db,db>> b) {
    return make_pair((a[2].first - a[1].first) * (a[2].first - a[1].first) + (a[2].second - a[1].second) * (a[2].second - a[1].second), (b[2].first - b[1].first) * (b[2].first - b[1].first) + (b[2].second - b[1].second) * (b[2].second - b[1].second));
};

void solve() {
    vector<pair<db,db>> a(6), b(6);
    for (int i = 1; i < 5; ++i)
        cin >> a[i].first >> a[i].second;

    for (int i = 1; i < 5; ++i)
        cin >> b[i].first >> b[i].second;

    a[5].first = a[1].first;
    a[5].second = a[1].second;
    b[5].first = b[1].first;
    b[5].second = b[1].second;

    auto ans = geti(a, b);

    for(int i=1;i<5;++i)for(int j=1;j<5;++j)if(ck(a[i], a[i + 1], b[j], b[j + 1])) {
                cout << "YES" << endl;
                return;
            }

    for(int i=1;i<5;++i){
        double sum = 0;
        for(int j=1;j<5;++j){
            auto aa = a[i], bb = b[j], cc = b[j + 1];
            sum += fabs((bb.first-aa.first)*(cc.second-aa.second)-(cc.first-aa.first)*(bb.second-aa.second)) / 2;
        }
        if (fabs(sum - ans.second) < eps){
            cout << "YES" << endl;
            return;
        }
    }
    for(int i=1;i<5;++i){
        double sum=0;
        for(int j=1;j<5;++j){
            auto aa = b[i], bb = a[j], cc = a[j + 1];
            sum += fabs((bb.first-aa.first)*(cc.second-aa.second)-(cc.first-aa.first)*(bb.second-aa.second)) / 2;
        }
        if (fabs(sum - ans.first) < eps){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
    return;
}
