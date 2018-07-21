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

const int N = 20005, zero = N - 2;
int fa[N], val[N];

int find(int u) {
    if (u == fa[u])
        return u;
    int f = fa[u];
    fa[u] = find(f);
    val[u] ^= val[f];
    return fa[u];
}

bool merge(int u, int v, int c) {
    int uu = find(u);
    int vv = find(v);
    if (uu == vv) {
        return (val[u] ^ val[v]) == c;
    }
    //assert(fa[zero] == zero);
    if (uu == zero)
        swap(uu, vv);
    fa[uu] = vv;
    val[uu] = val[u] ^ c ^ val[v];
    //assert(fa[zero] == zero);
    return true;
}


void gao(int n) {
    static int num[50];
    static bool vis[50];
    rep(i, 0, n) scanf("%d", &num[i]);
    memset(vis, 0, sizeof(vis));
    int ans = 0;
    rep(i, 0, n) {
        if (vis[i])
        {
            continue;
        }
        int f = find(num[i]);
        int cnt = 0;
        rep(j, 0, n) {
            if (vis[j])
                continue;
            if (f == find(num[j])) {
                ans ^= val[num[j]];
                cnt++;
                vis[j] = 1;
            }
        }
        if (f != zero && (cnt & 1)) {
            printf("I don't know.\n");
            return;
        }
    }
    printf("%d\n", ans);
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int n, q;
    int cs = 1;
    while (~scanf("%d%d", &n, &q) && (n + q)) {
        printf("Case %d:\n", cs);
        memset(val, 0, sizeof(val));
        for (int i = 0; i < N; ++i) fa[i] = i;
        bool conflict = false;
        int tot = 0;
        rep(Q, 0, q) {
            static char op[5000];
            if (conflict){
                gets(op);
                continue;  
            } 
 
            scanf("%s ", op);
            if (op[0] == 'I') {
                tot++;
                gets(op);
                int x, y, z;
                int c = sscanf(op, "%d%d%d",&x,&y,&z);
                //for (int i = 0; op[i]; ++i) c += op[i] == ' ';
                //assert(c == 1 || c == 2);
                if (c == 2) {
                    if (!merge(x, zero, y)) {
                        printf("The first %d facts are conflicting.\n", tot);
                        conflict = 1;
                    }
                } else {
                    if (!merge(x, y, z)) {
                        printf("The first %d facts are conflicting.\n", tot);
                        conflict = 1;
                    }
                }
            } else {
                int x;
                scanf("%d", &x);
                gao(x);
            }
        }
        cs++;
        puts("");
    }
    return 0;
}