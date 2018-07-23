#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
vector<pair<int, pair<int,int> > > s;
string temp;
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    for (cin >> T; T--;) {
        int n;
        cin >> n;
        s.clear();
        int in = 0;
        for (int i = 0; i < n; ++i) {
            cin >> temp;
            int l = 0, r = 0;
            for (const auto &c: temp) {
                if (c == '(') r++;
                else {
                    if (r == 0)l++;
                    else r--, in++;
                }
            }
            s.push_back({l - r, {l, r}});
        }
        sort(s.begin(),s.end(), [&](const pair<int, pair<int,int> > &a, const pair<int, pair<int, int>> &b){
            int dx = a.fi > 0? 1: (a.fi? -1: 0);
            int dy = b.fi > 0? 1: (b.fi? -1: 0);
            return dx != dy? dx < dy: (dx > 0? (a.se.se > b.se.se): (dx < 0? a.se.fi < b.se.fi: 0));
        });
        int pre = 0;
        int tot = 0;
        for (const auto &seg: s) {
            if(pre >= seg.se.fi) {
                tot += seg.se.fi;
                pre -= seg.se.fi;
            } else {
                tot += pre;
                pre = 0;
            }
            pre += seg.se.se;
        }
        printf("%d\n", (in + tot) * 2);
    }
    return 0;
}