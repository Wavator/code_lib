#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#define debug(...) fprintf(stderr, __VA_ARGS__),fprintf(stderr, "\n"),fflush(stderr)
#else
#define debug(...) 98
#endif
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const ll mod = (ll)1e9+7;
//#define scanf ______
#define gc getchar
//inline char gc() { static char buf[1<<20], *head = buf, *tail = buf;return (head == tail && (tail = (head = buf) + fread(buf, 1, 1 << 20, stdin), head == tail)? -1: *head++); }
template <typename T> inline bool read(T &x){ static bool f;static char c;for (c = gc(), f = false; !isdigit(c); c = gc()) { if (c == EOF)return false; else if (c == 45)f = true; }for (x=0;isdigit(c);c=gc())x = x * 10 + c - 48;if (f)x = -x;return true; }
template <typename A, typename B> inline bool read(A&a,B&b){return read(a)&&read(b);}
template <typename A, typename B, typename C> inline bool read(A&a,B&b,C&c){return read(a)&&read(b)&&read(c);}
ll pow_mod(ll a, ll b = mod - 2) { assert(b>=0);ll res=1;for(a%=mod;b;b>>=1,a=a*a%mod)if(b&1)res=res*a%mod;return res; }
/*
 * head
 */
const int N = 100005;
int a[N];
int mi[N << 2], s[N << 2], lzy[N << 2];
inline void push_up(int rt) {
    mi[rt] = min(mi[rt << 1], mi[rt << 1 | 1]);
    s[rt] = s[rt << 1] + s[rt << 1 | 1];
}
void update(const int &v, int l, int r, int rt) {
    mi[rt] -= v;
    lzy[rt] += v;
    if (mi[rt])
        return;
    if (l == r) {
        s[rt]++;
        mi[rt] = a[l];
        return;
    }
    int mid = l + r >> 1;
    update(lzy[rt], l, mid, rt << 1);
    update(lzy[rt], mid + 1, r, rt << 1 | 1);
    lzy[rt] = 0;
    push_up(rt);
}
void build(int l, int r, int rt) {
    s[rt] = lzy[rt] = 0;
    if (l == r) {
        mi[rt]=a[l];
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
    push_up(rt);
}

inline void push_down(int l, int r, int rt) {
    if (lzy[rt]) {
        int mid = l + r >> 1;
        update(lzy[rt], l, mid, rt << 1);
        update(lzy[rt], mid + 1, r, rt << 1 | 1);
        lzy[rt]=0;
    }
}

void change(int L, int R, int l, int r, int rt) {
    if (L == l && R == r) {
        update(1, l, r, rt);
        return;
    }
    push_down(l, r, rt);
    int mid = l + r >> 1;
    if (R <= mid) change(L, R, l, mid, rt << 1);
    else if (L > mid) change(L, R, mid + 1, r, rt << 1 | 1);
    else {
        change(L, mid, l, mid, rt << 1);
        change(mid + 1, R, mid + 1, r, rt << 1 | 1);
    }
    push_up(rt);
}
int query(int L, int R, int l, int r, int rt) {
    if (L == l && R == r) return s[rt];
    int mid = l + r >> 1;
    if (R <= mid)
        return query(L, R, l, mid, rt << 1);
    else if (L > mid)
        return query(L, R, mid + 1, r, rt << 1 | 1);
    else
        return query(L, mid, l, mid, rt << 1) + query(mid + 1, R, mid + 1, r, rt << 1 | 1);
}
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int n, q;
    while (read(n, q)) {
        for (int i = 1; i <= n; ++i) read(a[i]);
        build(1, n, 1);
        while (q--) {
            static char op[15];
            static int l, r;
            scanf("%s", op);
            read(l, r);
            if (op[0] == 'a')
                change(l, r, 1, n, 1);
            else
                printf("%d\n", query(l, r, 1, n, 1));
        }
    }
    return 0;
}
