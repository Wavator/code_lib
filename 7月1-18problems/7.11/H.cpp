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

const int N = 100100 * 2;

int s[N];

inline void add(int pos, const int &val) {
    for (; pos < N; pos += pos & -pos) s[pos] += val;
}

inline int query(int pos) {
    int res = 0;
    for (; pos; pos -= pos & -pos) res += s[pos];
    return res;
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int T;
    for(scanf("%d",&T); T--; ) {
        static int pos[N];
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
            pos[i] = n - i + 1;
        for (int i = 1; i < N; ++i) s[i] = i & -i;
        int tot = n;
        rep(i, 0, m) {
            int x;
            scanf("%d",&x);
            if(i)
                printf(" ");
            printf("%d",n - query(pos[x]));
            add(pos[x], -1);
            pos[x] = ++tot;
        }
        puts("");
    }
    return 0;
}
