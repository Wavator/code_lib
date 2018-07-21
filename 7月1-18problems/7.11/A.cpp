#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <fstream>
#include <sstream>
#include <cstring>
#include <utility>
#include <complex>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <algorithm>
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

static const int N = 50000 + 10;

static int mx[N << 2], mi[N << 2];

inline void push_up(int rt) {
    mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
    mi[rt] = min(mi[rt << 1], mi[rt << 1 | 1]);
}

void build(int l, int r, int rt) {
    if (l == r) {
        scanf("%d", &mx[rt]);
        mi[rt] = mx[rt];
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
    push_up(rt);
}

int query_max(const int &L, const int &R, int l, int r, int rt) {
    if (l >= L && r <= R)
        return mx[rt];
    int mid = l + r >> 1;
    if (L > mid)
        return query_max(L, R, mid + 1 ,r, rt << 1 | 1);
    if (R <= mid)
        return query_max(L, R, l, mid, rt << 1);
    return max(query_max(L, R, l, mid, rt << 1), query_max(L, R, mid + 1, r, rt << 1 | 1));
}

int query_min(const int &L, const int &R, int l, int r, int rt) {
    if (l >= L && r <= R)
        return mi[rt];
    int mid = l + r >> 1;
    if (L > mid)
        return query_min(L, R, mid + 1, r, rt << 1 | 1);
    if (R <= mid)
        return query_min(L, R, l, mid, rt << 1);
    return min(query_min(L, R, l, mid, rt << 1), query_min(L, R, mid + 1, r, rt << 1|1));
}
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int n, q;
    scanf("%d%d",&n,&q);
    build(1, n, 1);
    rep(i,0,q) {
        static int L,R;
        scanf("%d%d",&L,&R);
        printf("%d\n",query_max(L,R,1,n,1)-query_min(L,R,1,n,1));
    }
    return 0;
}