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
const int N = 100105;

struct Node {
    int p, val, id;
};
ll ans[N];
void solve(){
    int n, k;
    cin >> n >> k;
    vector<Node> in(n);
    vector<Node> vector1;
    for (int i = 0; i < n; ++i)
        in[i].id=i;
    for (int i=0;i<n;++i)
        cin >> in[i].p;
    for (int i=0;i<n;++i)
        cin >> in[i].val;
    for(auto&v:in)
        vector1.pb(v);
    sort(in.begin(),in.end(),[&](const Node &a,const Node &b) {
        return a.p > b.p;
    });
    sort(vector1.begin(),vector1.end(),[&](const Node &a, const Node &b) {
        return a.val > b.val;
    });
    queue<Node> que;
    for(int i = 0;i < k;i ++)
        que.push(vector1[i]);
    int p = k;
    for(int i = 0;i < n;i ++) {
        queue<Node> now;
        long long sum = 0;
        while(!que.empty()) {
            auto t = que.front();
            que.pop();
            if(t.p < in[i].p) {
                now.push(t);
                sum += t.val;
            }
        }
        while(p < n && now.size() < k) {
            if(vector1[p].p < in[i].p) {
                now.push(vector1[p]);
                sum += vector1[p].val;
            }
            p++;
        }
        que = now;
        ans[in[i].id] = sum + in[i].val;
    }
    for(int i = 0;i < n;i ++)
        cout << ans[i] << ' ';

}
