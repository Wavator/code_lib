#include <bits/stdc++.h>
using namespace std;

#pragma optimize("-O3")

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

#ifdef Wavator

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__);

#else

#define debug(...) 42;

#define cerr if (false) cout

#endif

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b) - 1; i >= a; --i)

#define pb push_back

typedef long long ll;
typedef double db;
typedef vector <int> vi;
typedef vector <ll> vl;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define my_sort_unique(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))

#define my_unique(a) a.resize(distance(a.begin(), unique(a.begin(), a.end())))

#define fi first

#define se second

const int N = 3e5 + 17;

string s[N];

map<int, int> mp;

inline int cal(const string &in) {
    int l = 0;
    for (auto &c: in) {
        if (c == '(')
            l++;
        else
            l--;
    }
    return l;
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr); cout.tie(nullptr);
    int n;
    while (cin >> n) {
        mp.clear();
        for (int i = 1; i <= n; ++i)    cin >> s[i];

        for (int i = 1; i <= n; ++i) {
            int t = cal(s[i]);
            if (t > 0)
                for (int j = 0; j < t; ++j)
                    s[i].pb(')');
            else
                for (int j = 0; j + t < 0; ++j)
                    s[i] = '(' + s[i];

            bool ok = 1;

            int res = 0;
            for (const auto &c: s[i]) {
                if (c == '(')
                    res++;
                else
                    res--;
                if ((~res) == 0)
                {
                    ok = 0;
                    break;
                }
            }

            if (ok)
                mp[t]++;

        }

        ll ans = 0;

        for (auto&it: mp) {

            if (it.first > 0)
                break;

            ans += 1ll * it.second * mp[-it.first];

        }

        cout << ans << endl;


    }
    return 0;
}
