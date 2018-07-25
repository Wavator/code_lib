#include <bits/stdc++.h>

const int N = 100000;

struct Solver
{
    using LL = long long;

    Solver(int n)
        : n(n), head(n, -1), next(n - 1 << 1), down(n), up(n), ans(n)
    {
    }

    void run()
    {
        for (int i = 0, a, b, c; i < n - 1; ++ i) {
            scanf("%d%d%d", &a, &b, &c);
            a --, b --;
            to.push_back(a);
            to.push_back(b);
            color.push_back(c);
        }
        for (int i = 0; i < n - 1 << 1; ++ i) {
            next[i] = head[to[i ^ 1]];
            head[to[i ^ 1]] = i;
        }
        int root = 0;
        for (int it = head[root]; ~it; it = next[it]) {
            dfs(it);
        }
// for (int i = 0; i < n; ++ i) {
//     fprintf(stderr, "down[%d] = %lld\n", i + 1, down[i]);
// }
        up[root] = 0;
        dfs2(-1, root);
        for (int s = 0; s < n; ++ s) {
            std::cout << ans[s] << "\n";
        }
    }

    void dfs(int pr)
    {
        int u = to[pr];
        for (int it = head[u]; ~it; it = next[it]) {
            if ((pr ^ it) == 1) {
                continue;
            }
            dfs(it);
            down[u] = std::max(down[u], down[to[it]] + sqr(color[pr >> 1] - color[it >> 1]));
        }
    }

    using Order = std::vector<std::pair<int, int>>;
    using Line = std::pair<LL, LL>;

    static bool check(const Line& a, const Line& b, const Line& c)
    {
        return 1LL * (a.second - b.second) * (c.first - a.first) < 1LL * (a.second - c.second) * (b.first - a.first);
    }

    static LL eval(const Line& a, int x)
    {
        return a.first * x + a.second;
    }

    void update(const Order& order)
    {
        std::vector<Line> lines;
        for (auto&& it : order) {
            int x = it.first;
            while (static_cast<int>(lines.size()) >= 2 && eval(lines[static_cast<int>(lines.size()) - 2], x) > eval(lines.back(), x)) {
                lines.pop_back();
            }
            if (!lines.empty()) {
                up[it.second] = std::max(up[it.second], eval(lines.back(), x) + sqr(x));
            }
            Line l(-2 * it.first, down[it.second] + sqr(it.first));
            if (!lines.empty() && lines.back().first == l.first && lines.back().second >= l.second) {
                continue;
            }
            while (static_cast<int>(lines.size()) >= 2 && !check(lines[static_cast<int>(lines.size()) - 2], lines.back(), l)) {
                lines.pop_back();
            }
            lines.push_back(l);
        }
    }

    void dfs2(int pr, int u)
    {
        Order order;
        for (int it = head[u]; ~it; it = next[it]) {
            int v = to[it];
            if ((pr ^ it) != 1) {
                order.emplace_back(color[it >> 1], v);
                if (~pr) {
                    up[v] = std::max(up[v], up[u] + sqr(color[pr >> 1] - color[it >> 1]));
                }
            }
        }
        std::sort(order.begin(), order.end(), std::greater<std::pair<int, int>>());
        update(order);
        for (auto& e : order) {
            e.first *= -1;
        }
        std::reverse(order.begin(), order.end());
        update(order);
        ans[u] = up[u];
        for (int it = head[u]; ~it; it = next[it]) {
            int v = to[it];
            if ((pr ^ it) != 1) {
                ans[u] = std::max(ans[u], down[v]);
                dfs2(it, v);
            }
        }
    }

    static LL sqr(int x)
    {
        return 1LL * x * x;
    }

    int n;
    std::vector<int> deg, head, to, next, color;
    std::vector<LL> down, up, ans;
};

int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    while (scanf("%d", &n) == 1) {
        Solver(n).run();
    }
}
