#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<ll, ll> > a;
    ll x, y;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        a.emplace_back(x, 0);
        a.emplace_back(y, 1);
    }
    ll ptr = -1, now = 0;
    vector<ll> ans(n + 1, 0);
    sort(a.begin(), a.end());
    for (auto &t: a) {
        if (!t.second) {
            if (ptr != -1) {
                ans[now] += t.first - ptr;
            }
            ptr = t.first;
            now++;
        } else {
            if (ptr > t.first) {
                ptr = t.first + 1;
                now--;
                continue;
            } else {
                ans[now] += t.first - ptr + 1;
            }
            ptr = t.first + 1;
            now--;
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}