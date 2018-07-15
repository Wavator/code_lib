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
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second
const int N = 505;
struct top {
    int x, y, z;
    inline bool operator<(const top&o) const {
        return z > o.z;
    }
};
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int h, w, d;
int mat[N][N];
inline bool ck_go(int x, int y, int az) {
    return !(x < 0 || x >= h || y < 0 || y >= w || mat[x][y] <= az - d);
}
top tops[N*N];

bool vis[N][N];

int height[N][N];

int gao(const top &a) {
    if (vis[a.x][a.y])
        return 0;
    vis[a.x][a.y] = true;
    height[a.x][a.y] = a.z;
    int cnt = 1;
    bool flag = true;
    static top que[N*N];
    int head = 0, tail = 0;
    que[tail++]=a;
    while (head^tail)   {
        top &r = que[head++];
        rep(i, 0, 4) {
            int tx = r.x + dx[i];
            int ty = r.y + dy[i];
            if (!ck_go (tx, ty, a.z))
                continue;
            if (vis[tx][ty])    {
                if (height[tx][ty] != a.z)
                    flag = false;
                continue;
            }
            vis[tx][ty] = true;
            height[tx][ty] = a.z;
            que[tail++] = top{tx, ty, mat[tx][ty]};
            cnt += (mat[tx][ty] == a.z);
        }
    }
    return flag? cnt: 0;
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int T;
    for (scanf("%d", &T); T--;) {
        scanf ("%d%d%d", &h, &w, &d);
        int cnt = 0;
        rep(i,0,h){
            rep(j,0,w){
                scanf ("%d",&mat[i][j]);
                tops[cnt++] = (top{i, j, mat[i][j]});
            }
        }
        sort(tops, tops + cnt);
        memset(vis,false,sizeof(vis));
        memset(height,0,sizeof(height));
        int ans=0;
        rep(i, 0, cnt) ans += gao(tops[i]);
        printf("%d\n", ans);
    }
    return 0;
}
