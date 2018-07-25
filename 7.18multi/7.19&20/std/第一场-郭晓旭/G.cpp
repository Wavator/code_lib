#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

using Info = std::pair<int, int>;

template<typename T>
using PQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;

static const Info ONE { 1, 1 };

int lowbit(int msk)
{
    return msk & -msk;
}

Info add(const Info& a, const Info& b)
{
    return { a.first + b.first, 1LL * a.second * b.second % MOD };
}

void update(Info& x, const Info& a)
{
    if (a.first < x.first) {
        x = { a.first, 0 };
    }
    if (a.first == x.first) {
        x.second += a.second;
        if (x.second >= MOD) {
            x.second -= MOD;
        }
    }
}

int main()
{
    int n, m, l;
    while (scanf("%d%d%d", &n, &m, &l) == 3) {
        std::vector<std::vector<int>> graph(n);
        for (int i = 0, a, b; i < m; ++ i) {
            scanf("%d%d", &a, &b);
            a --, b --;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        if (l == 1) {
            puts("1");
            continue;
        }
        l --;
        std::vector<std::vector<Info>> dp(1 << l, std::vector<Info>(n, Info { m + 1, 0 })),
            merged(n, std::vector<Info>(1 << l, Info { m + 1, 0 }));
        int root = l;
        for (int i = 0; i < l; ++ i) {
            dp[1 << i][i] = { 0, 1 };
        }
        for (int msk = 0; msk < 1 << l; ++ msk) {
            for (int u = 0; u < n; ++ u) {
                auto& ref = merged.at(u);
                for (int subset = msk; subset > 0; subset = subset - 1 & msk) {
                    if (lowbit(subset) == lowbit(msk)) {
                        update(ref.at(msk), add(dp.at(subset).at(u), ref.at(msk ^ subset)));
                    }
                }
            }
            for (int u = 0; u < n; ++ u) {
                for (int v : graph[u]) {
                    update(dp.at(msk).at(v), add(merged.at(u).at(msk), ONE));
                }
            }
            auto& ref = dp.at(msk);
            PQ<std::pair<int, int>> pq;
            for (int u = 0; u < n; ++ u) {
                pq.emplace(ref.at(u).first, u);
            }
            while (!pq.empty()) {
                auto top = pq.top();
                pq.pop();
                int u = top.second;
                if (top.first == ref.at(u).first) {
                    for (int v : graph.at(u)) {
                        Info todo = add(ref.at(u), ONE);
                        if (todo.first < ref.at(v).first) {
                            pq.emplace(todo.first, v);
                        }
                        update(ref.at(v), todo);
                    }
                }
            }
            for (int u = 0; u < n; ++ u) {
                update(merged.at(u).at(msk), dp.at(msk).at(u));
// fprintf(stderr, "%s %d %d %d\n", std::bitset<3>(msk).to_string().c_str(), u, dp.at(msk).at(u).first, dp.at(msk).at(u).second);
            }
        }
        printf("%d\n", merged.at(root).at((1 << l) - 1).second);
    }
}
