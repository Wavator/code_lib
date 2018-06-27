#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string,int> mp;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string buf;
        cin >> buf;
        mp[buf]++;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        string buf;
        cin >> buf;
        if (mp[buf]) {
            mp[buf]--;
        } else
            ans++;
    }
    cout << ans << '\n';
    return 0;
}