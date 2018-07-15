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
const int N = 100010;

namespace rmq {
    const int LOG = log2(N) + 1;
    int ma[N][LOG];
    int mi[N][LOG];
    int base[N];
    int n;
    void initRMQ(int * a) {
        base[0] = -1;
        for (int i = 1; i <= n; i++) {
            base[i] = ((i & (i - 1)) == 0) ? base[i - 1] + 1 : base[i - 1];
            ma[i][0] = a[i];
            mi[i][0] = a[i];
        }
        for (int j = 1; j <= base[n]; j++)
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                ma[i][j] = max(ma[i][j - 1], ma[i + (1 << (j - 1))][j - 1]);
                mi[i][j] = min(mi[i][j - 1], mi[i + (1 << (j - 1))][j - 1]);
            }
    }

    int rmq(int x, int y) {
        int k = base[y - x + 1];
        return max(ma[x][k], ma[y - (1 << k) + 1][k]) -
               min(mi[x][k], mi[y - (1 << k) + 1][k]);
    }
}

int n;
int a[N];
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--){
        ll k;
        scanf("%d%lld",&n,&k);
        rep(i, 1, n + 1) scanf("%d", a + i);
        rmq::n = n;
        rmq::initRMQ(a);

        ll ans = 0;
        for(int i = 1; i <= n; i++){
            int l = i, r = n;
            while(l < r){
                int mid = l + (r - l + 1) / 2;
                if(rmq::rmq(i, mid) < k){
                    l = mid;
                }else{
                    r = mid - 1;
                }
            }
            ans+=(l-i+1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
