#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    n <<= 1;
    vector<int> a(n | 1);
    for (int i = 1, d; i <= n; i++) {
        scanf("%d", &d);
        a[i] = d;
    }
    int ans = 0;
    for (int i = 1; i <= n; i+=2) {
        if (a[i + 1] != a[i]) {
            int t;
            for (int j=i + 1; j <= n; j++)
                if (a[j] == a[i]) {
                    t=j;
                    break;
                }
            for(int j = t;j >= i + 2; j--) {
                swap(a[j], a[j - 1]);
                ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
