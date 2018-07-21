#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream&operator<<(ostream&os, const pair<A, B> &v) {
    return os << "[" << v.first << ' ' << v.second << "]";
}
template <typename T>
ostream&operator<<(ostream&os, const vector<T> &x) {
    os << "[";
    for (auto it = x.begin(); it != x.end(); os<< *it++)if(it != x.cbegin()) os<<' ';
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
const int N = 100005 * 2;

int fa[N], c[N], _[N >> 1];
ll s[N];
int cnt;

void init(int n) {
    rep(i, 1, n + 1) {
        fa[i] = i;
        s[i] = i;
        _[i] = i;
        c[i] = 1;
    }
    cnt = n;
}

int find(int u) {
    return u == fa[u]? u: fa[u] = find(fa[u]);
}
void merge(int u, int v) {
    u = find(_[u]);
    v = find(_[v]);

    if (u == v)
        return;

    fa[u] = v;

    c[v] += c[u];

    s[v] += s[u];

}
inline void move(int x, int y) {

    if (find(_[x]) == find(_[y])) return;

    int f = find(_[x]);

    s[f] -= x;

    c[f] --;

    _[x] = ++cnt;
    s[_[x]] = x;
    c[_[x]] = 1;
    fa[_[x]] = _[x];

    merge(x, y);

}



int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        init(n);
        static int op, x, y;
        rep(i, 0, m) {
            scanf("%d", &op);
            if (op == 1) {
                scanf("%d%d", &x, &y);
                merge(x, y);
            } else if (op == 2) {
                scanf("%d%d", &x, &y);
                move(x, y);
            } else {
                scanf("%d", &x);
                x = find(_[x]);
                printf("%d %lld\n", c[x], s[x]);
            }
        }
    }
    return 0;
}