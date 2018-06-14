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

const int N = 1205;

void no() {
    puts("NO");
    exit(0);
}

char ans[N][N];

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr); cout.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;

    if (min(a, b) != 1 || (n == 2 || n == 3) && a == 1 && b == 1)
        no();

    puts("YES");

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            ans[i][j] = '0';

    if (b > 1) {


        rep(i, 0, b - 1)
        {

            rep(j, 0, n)
            {
                if (i == j)
                    continue;
                ans[i][j] = ans[j][i] = '1';
            }
        }


    }

    else if(a > 1)
    {

        rep(i, 0, n) {
            rep(j, 0, n) {
                if (i == j)
                    continue;
                ans[i][j] = '1';
            }
        }

        rep(i, 0, a - 1) {

            rep(j, 0, n) {
                ans[i][j] = ans[j][i] = '0';
            }

        }

    }

    else
    {

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                ans[i][j] = '0';

        for (int i = 1; i <= n; ++i)
            ans[i][i + 1] = ans[i + 1][i] = '1';

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j)
                putchar(ans[i][j]);
            puts("");
        }

        exit(0);

    }

    rep(i, 0, n) {

        rep(j, 0, n) {
            putchar(ans[i][j]);
        }

        putchar(10);

    }

    return 0;
}
