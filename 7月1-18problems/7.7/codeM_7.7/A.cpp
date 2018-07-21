#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = (ll)1e9+7;
const int N = 101;
int a[N];
double f[N];
ll dp[N];
int main () {
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i)
        scanf("%d",&a[i]);
    for (int i = 1; i <= n; ++i) {
        f[i] = log2(a[i]);
        f[i] /= i;
    }
    fill(dp + 1, dp + n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            if (f[i] > f[j]) {
                dp[i] += dp[j];
                if (dp[i] >= mod)
                    dp[i] -= mod;
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += dp[i];
        if (ans >= mod)
            ans -= mod;
    }
    return !printf("%lld\n", ans);
}