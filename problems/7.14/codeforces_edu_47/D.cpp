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
    int n, m;
    scanf("%d%d", &n, &m);
    if (n > m + 1) return !printf("Impossible");
    vector<pii> ret;
    int now = 0;
    for (int i = 1; i < n && now < m; ++i){
        for (int j = i + 1; j <= n; ++j) {
            if (__gcd(i, j) > 1) continue;
            ret.emplace_back(i, j);
            if (++now >= m) break;
        }
    }
    if (now < m) return !printf("Impossible");
    puts("Possible");
    for (const auto &p: ret) printf("%d %d\n", p.first, p.second);
    return 0;
}