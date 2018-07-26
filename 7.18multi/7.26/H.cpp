#include <bits/stdc++.h>
using namespace std;
template <typename T> using V = vector<T>;
template <typename T> using pqmax = priority_queue<T>;
template <typename T> using pqmin = priority_queue<T, V<T>, greater<T> >;
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define SZ(x) ((int)(x).size())
#define pb push_back
#define gc getchar
template <typename T> inline bool read(T& x) {
    static int ch;
    static int f;
    for (f = 1, ch = gc(); !isdigit(ch); ch = gc()) {
        if (ch == -1) return false;
        if (ch == 45) f = -1;
    }
    for (x = ch - 48; ;x = x * 10 + ch - 48)
        if (!isdigit(ch = gc())) break;
    x *= f;
}
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
const ll mod = (ll)1e9+7;
ll pow_mod(ll a, ll b = mod - 2) {
    assert(b >= 0); ll res = 1; for (a %= mod; b; b >>= 1, a = a * a % mod) if (b & 1) res = res * a % mod;
    return res;
}
const int N = 10000002;
int isp[N];

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int n;
    cin >> n;
    for (int i = 2; i <= n; ++i) isp[i] = true;
    for (int i = 2; i <= n; ++i) {
        if (isp[i]) for (int j = 2 * i; j <= n; j += i) isp[j] = false;
    }
    for (int i = 1; i <= n; ++i) isp[i] += isp[i - 1];
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += 1ll * isp[n / i] * (isp[n / i] - 1);
    }
    cout << ans << endl;
    return 0;
}
关于我们 加入我们 意见反馈 企业服务 联系我们 免责声明 友情链接
        京ICP备14055008号-4
牛客网©2017 All Rights Reserved
        牛客网，程序员必备求职神器
        QQ群：169195721
微 信：www_nowcoder_com 关注
微 博：牛客网 关注
