#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream&operator<<(ostream&os, const pair<A, B> &v) {
    return os << "[" << v.first << ' ' << v.second << "]";
}
template <typename T>
ostream&operator<<(ostream&os, const vector<T> &x) {
    os << "[";
    for (auto it = x.begin(); it != x.end(); os<<it++)if(it != x.cbegin()) os<<' ';
    return os << "]";
}
void write() {}
template <typename H, typename...T>
void write(H head, T...tail) {
    cerr << head << (char) ((sizeof...(tail))? ' ': '\n');
    write(tail...);
}

#ifdef Wavator
#define debug(...) cerr << #__VA_ARGS__ << ":\n", write(__VA_ARGS__), cerr << '\n';
#else
#define debug(...) 98;
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
const int N = 100010;
struct B {
    int a[N];
    void init() {
        memset(a,0,4*N);
    }
    inline void add(int pos) {
        for(;pos<N;pos+=pos&-pos) a[pos]++;
    }
    inline int query(int pos) {
        int res = 0;
        for (; pos; pos -= pos & -pos) res += a[pos];
        return res;
    }
};

B bit;

int a[N], c[N], d[N];

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int T;
    for (scanf("%d", &T); T--; ) {
        int n;
        scanf("%d", &n);
        rep(i, 0, n) scanf("%d", &a[i]);
        bit.init();
        rep(i, 0, n) {
            c[i] = bit.query(a[i]);
            bit.add(a[i]);
        }
        bit.init();
        per(i, 0, n) {
            d[i] = bit.query(a[i]);
            bit.add(a[i]);
        }
        ll ans = 0;
        rep(i, 0, n) {
            ans += 1ll * c[i] * (n - i - 1 - d[i]);
            ans += 1ll * d[i] * (i - c[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}