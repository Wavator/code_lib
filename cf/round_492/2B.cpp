#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int n, a[N], res[N];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int i = 0; i < n; ++i)
        res[i] = max(0, a[i] - i + n - 1) / n;
    cout << min_element(res, res + n) - res + 1 << '\n';
    return 0;
}
