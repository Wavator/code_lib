#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    if (n == 1||(n == 2 && a[0] == a[1]))
        return !printf("-1\n");
    int mi = 0x3f3f3f3f, ans = 1;
    for (int i = 0; i < n; i++)
        if (a[i] < mi) {
            ans = i + 1;
            mi = a[i];
        }
    cout << 1 << '\n' << ans << '\n';
    return 0;
}