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
const int N = 100100;

int lz[N<<2], a[N<<2];

inline void push_up(int rt) {
    a[rt] = a[rt << 1] + a[rt << 1 | 1];
}

inline void push_down(int rt, int le, int ri) {
    if (!lz[rt])
        return;
    lz[rt << 1] = lz[rt << 1 | 1] = lz[rt];
    a[rt << 1] = le * lz[rt];
    a[rt << 1 | 1] = ri * lz[rt];
    lz[rt] = 0;
}

void build(int l, int r, int rt) {
    lz[rt] = 0;
    if (l == r) {
        a[rt]=1;
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
    push_up(rt);
}

void change(const int &L, const int &R, const int &val, int l, int r, int rt) {
    if (l >= L && r <= R) {
        a[rt] = val * (r - l + 1);
        lz[rt] = val;
        return;
    }
    int mid = l + r >> 1;
    push_down(rt, mid - l + 1, r - mid);
    if (L <= mid)
        change(L, R, val, l, mid, rt << 1);
    if (R > mid)
        change(L, R, val, mid + 1, r, rt << 1 | 1);
    push_up(rt);
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int T;
    scanf("%d", &T);
    rep(kase, 0, T) {
        int n, m;
        scanf("%d%d", &n, &m);
        build(1, n, 1);
        rep(i, 0, m) {
            static int l, r, val;
            scanf("%d%d%d", &l, &r, &val);
            change(l, r, val, 1, n, 1);
        }
        printf("Case %d: The total value of the hook is %d.\n", kase + 1, a[1]);
    }
    return 0;
}