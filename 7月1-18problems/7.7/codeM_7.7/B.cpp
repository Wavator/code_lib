#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = N * 2;
pair<int, int> Q[M];
vector<int> e[N];
int main () {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        cin >> Q[i].first >> Q[i].second;
    }
    int l = 1, r = m + 1, ans = 0;
    while (r >= l) {
        int mid = l + r >> 1;
        static vector<int> d(n + 1);
        fill(d.begin(), d.end(), 0);
        for (int i = 1; i <= n; ++i) {
            e[i].clear();
        }
        for (int i = 1; i < mid; ++i) {
            e[(Q[i].first + (i != 1) + n) % n + 1].push_back((Q[i].second + (i != 1) + n) % n + 1 );
        }
        for (int i = 1; i <= n; ++i) {
            for (auto &v: e[i])
                d[v]++;
        }
        static queue<int> q;
        while (!q.empty())
            q.pop();
        for (int i = 1; i <= n; ++i) {
            if (!d[i])
                q.push(i);
        }
        int cnt = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ++cnt;
            for (auto&v: e[u]) {
                --d[v];
                if (d[v] == 0)
                    q.push(v);
            }
        }
        if (cnt == n) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    for (int i = 1; i <= ans; ++i) {
        putchar(49), putchar(10);
    }
    for (int i = ans + 1; i <= m; ++i) {
        putchar(48), putchar(10);
    }
    return 0;
}