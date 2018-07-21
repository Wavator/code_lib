#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y;
    string str;
    cin >> n >> x >> y >> str;
    long long cnt=0;
    bool f = false;
    for(auto &c: str) {
        if(c == '0') {
            if(!f) {
                cnt++;
                f = true;
            }
        }
        else
            f = false;
    }
    if(!cnt) {
        cout << 0 << endl;
        return 0;
    }
    cnt--;
    long long ans = y;
    ans += cnt * min(1ll * x, 1ll * y);
    cout << ans << endl;
    return 0;
}