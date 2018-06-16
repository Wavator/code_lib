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

struct P
{
    int x, y;
    bool operator < (const P &o) const {
        if (x == o.x)
            return y < o.y;
        return x < o.x;
    }
};
vector<vector<int> > ans(12, vector<int>(12, 0));
int n, m;
bool go() {
    bool f=true;
    int res=0;
    for(int i=0;i<n;i++) {
        if(!f) break;
        for(int j=0;j<m;j++) {
            if((res!=0)&&(ans[i][j]!=0)&&(ans[i][j]!=res)) {
                f = false;
                break;
            }
            if(!res)
                res = ans[i][j];
        }
    }
    if (f) {
        cout << res << endl;
        return 1;
    }
    return 0;
}

bool gogo() {
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        int res=0;
        for(int j=0;j<m;j++)
        {
            if(ans[i][j]!=0&&ans[i][j]!=res)
            {
                cnt++;
                res=ans[i][j];
            }
        }
        if (cnt >= 2)return false;
    }
    return true;
}

bool gogogo() {
    for(int i=0;i<m;i++) {
        int cnt=0;
        int res=0;
        for(int j=0;j<n;j++) {
            if(ans[j][i] && ans[j][i] != res) {
                cnt++;
                res=ans[j][i];
            }
        }
        if(cnt >= 2) {
            return false;
        }
    }
    return true;
}

void solve() {
    cin >> n >> m;
    vector<P> absi(n), vec(m);
    for(int i=0;i<n;i++) {
        cin >> absi[i].x >> absi[i].y;
    }
    for(int i=0;i<m;i++) {
        cin >> vec[i].x >> vec[i].y;
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            auto p = absi[i], q = vec[j];
            int now=0;
            if(p.x<p.y)
                swap(p.x,p.y);
            if(q.x<q.y)
                swap(q.x,q.y);
            if(p.x==q.x&&p.y==q.y)
                now=0;
            else if(p.y==q.x||p.y==q.y)
                now=p.y;
            else if(p.x==q.x||p.x==q.y)
                now=p.x;
            ans[i][j]=now;
        }

    if(go())
        return;
    if(gogo() && gogogo())
        cout<<0<<endl;
    else
        cout<<-1<<endl;
    return;
}
