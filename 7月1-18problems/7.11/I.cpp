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
ll bin[70];
inline ll gao(ll x) {
    ll ans = 0;
    for(int i = 0; bin[i] <= x; i++) {
        ans = ans + ((x / bin[i] - x / bin[i+1]) * bin[i]);
    }
    return ans;
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    bin[0] = 1;
    rep(i, 1, 66) bin[i] = bin[i - 1] * 2ll;
    ll n, q;
    while (~scanf("%lld%lld", &n, &q)) {
        rep(Q, 0, q) {
            static int op;
            scanf("%d",&op);
            if(op == 1) {
                ll x, y;
                scanf("%lld%lld",&x,&y);
                printf("%lld\n",gao(y) - gao(x - 1));
            }
            if (op == 2) {
                ll x;
                scanf("%lld",&x);
                int ans = 0;
                while(x <= n) {
                    ans++;
                    x += x & -x;
                }
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
