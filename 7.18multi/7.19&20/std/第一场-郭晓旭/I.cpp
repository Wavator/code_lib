#include <bits/stdc++.h>

const int N = 20000 * 6;

struct SA {
    SA(const std::vector<int>& s)
        : n(s.size())
        , rank(n)
        , order(n)
        , height(n)
    {
        int n = s.size();
        int m = *std::max_element(s.begin(), s.end()) + 1;
        std::vector<int> count(std::max(n + 1, m));
        for (int i = 0; i < n; ++i) {
            count[s[i]]++;
        }
        for (int i = 1; i < m; ++i) {
            count[i] += count[i - 1];
        }
        std::vector<int> tmp_rank(n), tmp_rank2(n), tmp_order(n);
        for (int i = 0; i < n; ++i) {
            rank[i] = count[s[i]] - 1;
        }
        for (int len = 1; len < n; len <<= 1) {
            std::fill(count.begin(), count.end(), 0);
            for (int i = 0; i < n; ++i) {
                count[tmp_rank[i] = i + len < n ? rank[i + len] + 1 : 0]++;
            }
            for (int i = 1; i <= n; ++i) {
                count[i] += count[i - 1];
            }
            for (int i = n - 1; i >= 0; --i) {
                tmp_order[--count[tmp_rank[i]]] = i;
            }
            std::fill(count.begin(), count.end(), 0);
            for (int i = 0; i < n; ++i) {
                count[tmp_rank2[i] = rank[i]]++;
            }
            for (int i = 1; i <= n; ++i) {
                count[i] += count[i - 1];
            }
            for (int i = n - 1; i >= 0; --i) {
                order[--count[rank[tmp_order[i]]]] = tmp_order[i];
            }
            rank[order[0]] = 0;
            for (int i = 1; i < n; ++i) {
                rank[order[i]] = rank[order[i - 1]] + (tmp_rank2[order[i - 1]] != tmp_rank2[order[i]] || tmp_rank[order[i - 1]] != tmp_rank[order[i]]);
            }
        }
        for (int i = 0, lcp = 0; i < n; ++i) {
            if (rank[i]) {
                int j = order[rank[i] - 1];
                while (i + lcp < n && j + lcp < n && s[i + lcp] == s[j + lcp]) {
                    lcp++;
                }
                height[rank[i]] = lcp;
            }
            if (lcp) {
                lcp--;
            }
        }
    }

    int n;
    std::vector<int> rank, order, height;
};

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        std::vector<char> buffer(n + 1);
        scanf("%s", buffer.data());
        std::vector<int> s(6 * (n + 1));
        int len = 0, perm[] = { 0, 1, 2 };
        for (int j = 0; j < 6; ++j) {
            for (int i = 0; i < n; ++i) {
                s[len++] = perm[buffer[i] - 'a'];
            }
            s[len++] = 3 + j;
            std::next_permutation(perm, perm + 3);
        }
        SA sa(s);
        std::vector<bool> used(n);
        int lcp = 0;
        long long result = 0;
        for (int i = 0; i < 6 * n; ++i) {
            int r = sa.order[i];
            lcp = std::min(lcp, sa.height[i]);
            int rr = r % (n + 1);
            if (used.at(rr)) {
                continue;
            }
            used.at(rr) = true;
            result += n - rr - lcp;
            lcp = n - rr;
        }
        std::cout << result << std::endl;
    }
}
