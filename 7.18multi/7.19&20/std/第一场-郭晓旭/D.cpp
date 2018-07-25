#include <bits/stdc++.h>

struct Edge { int a, b; };

using Graph = std::vector<Edge>;

Graph read(int m)
{
    Graph edges;
    for (int i = 0, a, b; i < m; ++ i) {
        scanf("%d%d", &a, &b);
        a --, b --;
        edges.push_back(Edge { a, b });
    }
    return edges;
}

int count(int n, const Graph& a, const Graph& b)
{
    std::vector<std::vector<bool>> target(n, std::vector<bool>(n, false));
    for (auto&& e : b) {
        target[e.a][e.b] = target[e.b][e.a] = true;
    }
    std::vector<int> phi(n);
    std::iota(phi.begin(), phi.end(), 0);
    int result = 0;
    do {
        bool ok = true;
        for (auto&& e : a) {
            ok &= target[phi[e.a]][phi[e.b]];
        }
        result += ok;
    } while (std::next_permutation(phi.begin(), phi.end()));
    return result;
}

int main()
{
    int n, m1, m2;
    while (scanf("%d%d%d", &n, &m1, &m2) == 3) {
        auto g1 = read(m1);
        auto g2 = read(m2);
        int iso = count(n, g1, g2);
        int aut = count(n, g1, g1);
#ifdef GEN
        printf("%d %d\n", iso, aut);
#else
        assert(iso % aut == 0);
        printf("%d\n", iso / aut);
#endif
    }
}
