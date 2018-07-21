#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
inline ostream& operator << (ostream&os, const pair<A, B> &v) {
    return os << v.first << ' ' << v.second;
}
template <typename T>
inline ostream& operator << (ostream&os, const vector<T> &v) {
    for (auto it = v.begin(); it != v.end(); os << (*it++)) if (it != v.cbegin()) os << ' ';
    return os;
}
#ifdef Wavator
#define debug(...) cerr << #__VA_ARGS__ << " = \n[ ", _debug(__VA_ARGS__), cerr << "]" << endl;
#else
#define debug(...) 98;
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
typedef pair<int, pii> pip;
typedef pair<pii, int> piii;

inline int query(ll x, ll y) {
    printf("%lld %lld\n", x, y);
    fflush(stdout);
    int res;
    return scanf("%d", &res), res;
}

int main() {
    //srand((unsigned)time(0));
    ll N;
    scanf("%lld", &N);
    for (ll prex = 0, prey = 0, dx = 1, dy = 1;;) {
        int res = query(prex + dx, prey + dy);
        if (res == 0)
            break;
        else if (res == 1) {
            prex += dx;
            ll delta = N - prex;
            if (delta >= 2ll * dx)
                dx *= 2;
            else {
                dx = N - prex;
            }
        } else if (res == 2) {
            prey += dy;
            ll delta = N - prey;
            if (delta >= 2ll * dy)
                dy *= 2;
            else {
                dy = N - prey;
            }
        } else {
            dx /= 2;
            dy /= 2;
        }
        if (dx == 0)
            dx = 1;
        if (dy == 0)
            dy = 1;
    }
    return 0;
}