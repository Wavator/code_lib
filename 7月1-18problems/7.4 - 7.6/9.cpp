#include <bits/stdc++.h>
using namespace std;
long long n;
inline long long count(int n) {
    set<long long> s;
    for(long long a = 0; a <= n; a++)
        for(long long b = 0;a + b <= n; b++)
            for(long long c = 0; a + b + c <= n; c++) {
                long long d = n - a - b - c;
                s.insert(a+5ll*b+10ll*c+50ll*d);
            }
    return (long long)(s.size());
}
int main() {
    cin >> n;
    vector<long long> ans(13);
    for(int i = 1; i <= 12; ++i) {

        ans[i] = count(i);
    }

    if(n <= 11) {
        cout << ans[n] << endl;
        return 0;
    }
    cout << (ans[12] - ans[11]) * (n - 11) + ans[11];
    return 0;
}