#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, double> dp;
map<ll, bool> vis;

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    hash<string> h;
    ll st = h("pink");
    ll ed = h("blue");
    vis[st] = true;;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string s, e;
        double p;
        cin >> s >> e >> p;
        //cerr << s << e << p << endl;
        ll ss = h(s);
        ll ee = h(e);
        if (!vis[ee])
            continue;
        if (!vis[ss])
            dp[ss] = -1000000000;
        dp[ss] = max(dp[ss], dp[ee] + log10(p));
        //fprintf(stderr, "%.4f %.4f\n", dp[ss], dp[ee] + log10(p));
        vis[ss] = true;
    }
    if (!vis[ed])
        return !printf("0.000000000000");
    double ans = pow(10, dp[ed]);
    ans = min(ans, 10.0);
    return !printf("%.10f\n", ans);
}
