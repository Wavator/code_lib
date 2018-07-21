#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

class PolyInter
{
public:
    void init(const std::vector<int>& v, int m = 0)
    {
        mod_ = m, deg = v.size(), val = buf = v;
        inv.resize(std::max(2, deg));
        inv[1] = 1;
        for (int i = 2; i < deg; ++ i) {
            inv[i] = 1LL * (mod() - mod() / i) * inv[mod() % i] % mod();
        }
    }

    int eval(long long n)
    {
        long long b = 1;
        for (int i = 1; i < deg; ++ i) {
            b = b * residue(n - i + 1) % mod() * inv[i] % mod();
            buf[i] = b * val[i] % mod();
        }
        b = 1;
        int result = buf[deg - 1];
        for (int i = deg - 2; i >= 0; -- i) {
            b = (mod() - b) * inv[deg - 1 - i] % mod() * residue(n - i - 1) % mod();
            result += buf[i] * b % mod();
            if (result >= mod()) {
                result -= mod();
            }
        }
        return result;
    }

private:
    int mod() const {
        return MOD ? MOD : mod_;
    }

    int residue(long long x) const {
        x %= mod();
        return x < 0 ? x + mod() : x;
    }

    int mod_, deg;
    std::vector<int> inv, val, buf;
};

void update(int& x, int a)
{
    x += a;
    if (x >= MOD) {
        x -= MOD;
    }
}

int pow(int a, int n)
{
    int result = 1;
    while (n) {
        if (n & 1) {
            result = 1LL * result * a % MOD;
        }
        a = 1LL * a * a % MOD;
        n >>= 1;
    }
    return result;
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        std::vector<int> a(n);
        int prod = 1;
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &a[i]);
            prod = 1LL * prod * a[i] % MOD;
        }
        std::sort(a.begin(), a.end());
        int result = prod;
        int pre = 1;
        for (int i = 0; i < n; ++ i) {
            int prev = i ? a[i - 1] : 0;
            int exp = n - i;
            std::vector<int> vals(exp + 2);
            for (int j = 1; j <= exp + 1; ++ j) {
                vals[j] = vals[j - 1];
                update(vals[j], prod);
                update(vals[j], MOD - 1LL * pre * pow(j, exp) % MOD);
            }
            PolyInter p;
            p.init(vals);
            update(result, p.eval(a[i]));
            update(result, MOD - p.eval(prev));
            pre = 1LL * pre * a[i] % MOD;
        }
        printf("%d\n", result);
    }
}
