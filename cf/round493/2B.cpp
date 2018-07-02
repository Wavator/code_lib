#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, b;
    cin >> n >> b;
    vector<int> a(n),e(n,0),o(n,0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ee = 0, oo = 0;
    int ptr = 0;
    for (int &x: a) {
        if (x & 1)
            ee++;
        else
            oo++;
        e[ptr]=ee;
        o[ptr++]=oo;
    }
    int ans = 0,m = b;
    vector<int> qu;
    for (int i = 1; i < n; ++i) {
        if (e[i] == o[i]) qu.push_back(abs(a[i + 1] - a[i]));
    }
    sort(qu.begin(), qu.end());
    for (auto &t: qu ) {
        if (m >= t) {
            ans++;
            m -= t;
        }
        else
            break;
    }
    cout << ans << '\n';
    return 0;
}