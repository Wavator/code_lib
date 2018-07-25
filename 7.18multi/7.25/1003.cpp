#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
namespace Graph {
    struct edge {
        int y, next;
        edge(int u = 0, int v = 0): y(u), next(v){};
    }e[N << 2];

    bool used[N << 2];

    int li[N];

    int deg[N];

    int cnt;

    int n, m;

    bool vis[N];

    vector<vector<int> > ans;

    inline void insert(int u, int v) {
        used[cnt] = used[cnt + 1] = false;
        e[cnt] = edge(v, li[u]);
        li[u] = cnt++;
        e[cnt] = edge(u, li[v]);
        li[v] = cnt++;
    }

    int ori;

    void init(int _, int ___) {
        n = _, m = ___;
        for (int i = 1; i <= n; ++i) {
            li[i] = -1;
            deg[i] = 0;
            vis[i] = false;
        }
        cnt = 0;
        ans.clear();
        for (int i = 0; i < m; ++i) {
            static int u, v;
            scanf("%d%d", &u, &v);
            insert(u, v);
            ++deg[u];
            ++deg[v];
        }
        ori = cnt;
    }

    vector<int> curr;

    void find_blk(int u) {
        if (deg[u] & 1)
            curr.push_back(u);
        vis[u] = 1;
        for (int i = li[u]; ~i; i = e[i].next)
            if (!vis[e[i].y])
                find_blk(e[i].y);
    }

    void dfs(int u) {
        for(int i = li[u]; ~i; i = e[i].next) {
            if(!used[i]) {
                used[i] = used[i ^ 1] = true;
                dfs(e[i].y);
                int j = i / 2 + 1;
                if ((i & 1) == 0)
                    j *= -1;
                if (i >= ori)
                    ans.push_back(vector<int>());
                else
                    ans.back().push_back(j);
            }
        }
    }

    void solve() {
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                if (!deg[i]) continue;
                curr.clear();
                find_blk(i);
                ans.push_back(vector<int>());
                if (curr.size() == 0) {
                    dfs(i);
                } else {
                    for (int j = 2; j < (int)curr.size(); j += 2)
                        insert(curr[j], curr[j + 1]);
                    dfs(curr[0]);
                }
            }
        }
    }

    void print() {
        printf("%d\n", (int)ans.size());
        for (const vector<int> & sol: ans) {
            printf("%d", (int)sol.size());
            for (const int &v: sol) printf(" %d", v);
            puts("");
        }
    }

}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        using namespace Graph;
        init(n, m);
        solve();
        print();
    }
    return 0;
}