#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline void ckmax(ll &a, ll b) {
    a = max(a, b);
}
const int N = 1e5 + 10;
ll a[N], sum[N], cha[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    a[0]=0;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    a[++n] = k;
    for(int i = 1; i <= n; ++i) {
        cha[i] = a[i] - a[i - 1];
    }
    for(int i=0;i<=n;i++) {
        if(i & 1)
            sum[i]=sum[i-1]+cha[i];
        else sum[i]=sum[i-1];
    }
    ll ans=max(sum[n],k-sum[n]);
    for (int i = 1; i < n; ++i) {
        if(a[i] - 1 > a[i-1])
            ckmax(ans,(k-a[i])-(sum[n]-sum[i])+(sum[i] == sum[i-1]? 1: -1)+sum[i]);
        if(a[i + 1]>a[i] + 1)
            ckmax(ans,(k-a[i])-(sum[n]-sum[i])+(sum[i] == sum[i-1]? 1: -1)+sum[i]);
    }
    cout<<ans<<'\n';
    return 0;
}