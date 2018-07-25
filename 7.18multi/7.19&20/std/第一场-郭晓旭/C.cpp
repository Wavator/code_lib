#include <bits/stdc++.h>

const int MOD = 1e9 + 7;
const int INV_2 = 5e8 + 4;

using Hash = unsigned long long;

const Hash MAGIC = 3;

int main()
{
    int n, m;
    while (scanf("%d%d", &m, &n) == 2) {
        std::vector<std::vector<bool>> mat(n, std::vector<bool>(m));
        for (int i = 0; i < m; ++ i) {
            std::vector<char> buffer(n + 1);
            scanf("%s", buffer.data());
            for (int j = 0; j < n; ++ j) {
                mat[j][i] = buffer[j] == '1';
            }
        }
        int two[4];
        two[0] = 1;
        for (int i = 0; i < m; ++ i) {
            two[0] = (two[0] << 1) % MOD;
        }
        for (int i = 1; i <= 3; ++ i) {
            two[i] = (1LL * two[i - 1] * INV_2) % MOD;
        }
        int result = 0;
        for (int i = 0; i < n; ++ i) {
            int pivot = 0;
            while (!mat[i][pivot] && pivot < m) {
                pivot ++;
            }
            int cnt[] = {0, 0, 0, 0};
            cnt[pivot < m] ++;
            std::unordered_map<Hash, int> uom;
            int zero = 0;
            for (int j = 0; j < i; ++ j) {
                bool flip = pivot < m && mat[j][pivot];
                Hash hash = 0;
                for (int k = 0; k < m; ++ k) {
                    int val = mat[j][k] ^ (mat[i][k] && flip);
                    hash = hash * MAGIC + val;
                }
                (hash ? uom[hash] : zero) ++;
                cnt[(pivot < m) + !!hash] += 6;
            }
            int rk1 = zero * (zero - 1) / 2;
            int rk3 = i * (i - 1) / 2 - rk1;
            int rk2 = 0;
            for (auto&& it : uom) {
                int tmp = it.second * zero;
                rk3 -= tmp, rk2 += tmp;
                tmp = it.second * (it.second - 1) / 2;
                rk3 -= tmp, rk2 += tmp;
            }
            // fprintf(stderr, "%d %d %d\n", rk1, rk2, rk3);
            cnt[(pivot < m) + 2] += rk3 * 6;
            cnt[(pivot < m) + 1] += rk2 * 6;
            cnt[(pivot < m) + 0] += rk1 * 6;
            for (int j = 0; j <= 3; ++ j) {
                result += 1LL * two[j] * cnt[j] % MOD;
                if (result >= MOD) {
                    result -= MOD;
                }
            }
        }
        printf("%d\n", result);
    }
}
