#include <bits/stdc++.h>

struct Query
{
    int l, r, id;
};

bool operator < (const Query& u, const Query& v)
{
    return u.r < v.r;
}

int main()
{
    int n, q;
    while (scanf("%d%d", &n, &q) == 2) {
        std::vector<int> a(n), first(n, -1), last(n);
        int total = 0;
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &a[i]);
            a[i] --, last[a[i]] = i;
            if (first[a[i]] == -1) {
                total ++, first[a[i]] = i;
            }
        }
        std::vector<Query> queries;
        for (int i = 0, l, r; i < q; ++ i) {
            scanf("%d%d", &l, &r);
            queries.push_back(Query {l - 1, r - 1, i});
        }
        std::sort(queries.begin(), queries.end());
        std::vector<int> count(n), result(q);
        for (int i = 0, k = 0; i < n; ++ i) {
            while (k < q && queries[k].r == i) {
                int& ref = result[queries[k].id] = total;
                for (int j = queries[k].l; j < n; j += ~j & j + 1) {
                    ref -= count[j];
                }
                k ++;
            }
            if (last[a[i]] == i) {
                for (int j = first[a[i]] - 1; ~j; j -= ~j & j + 1) {
                    count[j] ++;
                }
            }
        }
        for (int i = 0; i < q; ++ i) {
            printf("%d\n", result[i]);
        }
    }
}
