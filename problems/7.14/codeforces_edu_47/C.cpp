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

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    ll n, m;
    scanf("%lld%lld", &n, &m);
    ll sum = 0;
    rep(i, 0, m) {
        ll x,d;
        scanf("%lld%lld", &x, &d);
        sum += x * n;
        if (d >= 0){
            sum += n * (n - 1) / 2 * d;
        }else {
            sum += ((n & 1)? (n / 2) * (n / 2 + 1) * d: ((n - 1) / 2) * ((n - 1) / 2 + 1) * d + n / 2 * d);
        }
    }
    printf("%.15f\n", 1.0*sum / n);
    return 0;
}