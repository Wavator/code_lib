#include <bits/stdc++.h>
using namespace std;
const int N = 100003;
int x[N], y[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> y[i];
        x[i] -= y[i];
    }
    long long ans = 0;
    for(int i = n; i >= 2; i--){
        if(x[i] > 0)
        {
            x[i - 1] += x[i];
            ans += 1ll * x[i];
            x[i] = 0;
        }
    }
    for(int i = 1; i < n; i++){
        if(x[i] > 0)
        {
            x[i + 1] += x[i];
            ans += 1ll * x[i];
            x[i] = 0;
        }
    }
    cout << ans << endl;
    return 0;
}