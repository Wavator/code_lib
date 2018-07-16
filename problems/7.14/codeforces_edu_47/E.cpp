#include <bits/stdc++.h>
#pragma optimize("-O3")
using namespace std;
template <typename A, typename B> inline ostream& operator << (ostream&os, const pair<A, B> &v) {
    return os << v.first << ' ' << v.second;
}
template <typename T> inline ostream& operator << (ostream&os, const vector<T> &v) {
    for (auto it = v.begin(); it != v.end(); os << (*it++)) if (it != v.cbegin()) os << '\n';
    return os;
}
#ifdef Wavator
#define debug(...) cerr << #__VA_ARGS__ << " = \n[ ", _debug(__VA_ARGS__), cerr << "]" << endl
#else
#define debug(...) 98
#define cerr if (false) cout
#endif
void _debug(){}
template <typename H, typename...T>
void _debug(H head, T...tail) {
    cerr << head << " ";
    _debug(tail...);
}
#define rep(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll absi = 998244353;
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    ll n;
    scanf("%lld", &n);
    vl a(n + 1, 0), two(n + 1);
    rep(i, 1, n + 1) scanf("%lld", &a[i]);
    two[0] = 1ll;
    rep(i, 1, n + 1) {
        two[i] = two[i - 1] * 2ll;
        if (two[i] >= absi) two[i] -= absi;
    }
    ll ans = 0;
    rep(i, 1, n) {
        ll d = a[i] * (n - i + 2);
        d %= absi;
        d *= two[n - i - 1];
        d %= absi;
        ans += d;
        ans %= absi;
    }
    ans += a[n];
    cout << (ans % absi) << endl;
    return 0;
}