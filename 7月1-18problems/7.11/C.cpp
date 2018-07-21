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
static const int N = 200010;

static int mx[N << 2];

void build(int l, int r, int rt) {
    if (l == r) {
        scanf("%d", &mx[rt]);
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, rt << 1); build(mid + 1, r, rt << 1 | 1);
    mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
}

int query_max(const int &L, const int &R, int l, int r, int rt) {
    if (l >= L && r <= R) return mx[rt];
    int mid = l + r >> 1;
    if (L > mid) return query_max(L, R, mid + 1 ,r, rt << 1 | 1);
    if (R <= mid) return query_max(L, R, l, mid, rt << 1);
    return max(query_max(L, R, l, mid, rt << 1), query_max(L, R, mid + 1, r, rt << 1 | 1));
}


void change(const int &pos, const int &val, int l, int r, int rt) {
    if (l == r) {
        mx[rt] = val;
        return;
    }
    int mid = l + r >> 1;
    pos > mid? change(pos, val, mid + 1, r, rt << 1 | 1): change(pos, val, l, mid, rt << 1);
    mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        build(1, n, 1);
        while (m--) {
            static char op[6];
            static int x, y;
            scanf("%s%d%d", op, &x, &y);
            getchar();
            if (op[0] == 'Q') {
                printf("%d\n", query_max(x, y, 1, n, 1));
            } else {
                change(x, y, 1, n, 1);
            }
        }
    }
    return 0;
}
