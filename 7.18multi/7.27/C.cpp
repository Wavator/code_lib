#include <bits/stdc++.h>
using namespace std;
namespace fft {

    typedef int T;

    typedef double db;

    struct cp {
        db x, y;
        cp() { x = y = 0; }
        cp(db x, db y) : x(x), y(y) {}
    };

    inline cp operator+(cp a, cp b) { return cp(a.x + b.x, a.y + b.y); }
    inline cp operator-(cp a, cp b) { return cp(a.x - b.x, a.y - b.y); }
    inline cp operator*(cp a, cp b) { return cp(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
    inline cp conj(cp a) { return cp(a.x, -a.y); }

    T base = 1;
    vector<cp> roots = {{0, 0}, {1, 0}};
    vector<T> rev = {0, 1};

    const db PI = acosl(-1.0);

    void ensure_base(T nbase) {
        if (nbase <= base) {
            return;
        }
        rev.resize(static_cast<unsigned long>(1 << nbase));
        for (T i = 0; i < (1 << nbase); i++) {
            rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
        }
        roots.resize(static_cast<unsigned long>(1 << nbase));
        while (base < nbase) {
            db angle = 2 * PI / (1 << (base + 1));
            for (T i = 1 << (base - 1); i < (1 << base); i++) {
                roots[i << 1] = roots[i];
                db angle_i = angle * (2 * i + 1 - (1 << base));
                roots[(i << 1) + 1] = cp(cos(angle_i), sin(angle_i));
            }
            base++;
        }
    }

    void fft(vector<cp> &a, T n = -1) {
        if (n == -1) {
            n = a.size();
        }
        assert((n & (n - 1)) == 0);
        T zeros = __builtin_ctz(n);
        ensure_base(zeros);
        T shift = base - zeros;
        for (T i = 0; i < n; i++) {
            if (i < (rev[i] >> shift)) {
                swap(a[i], a[rev[i] >> shift]);
            }
        }
        for (T k = 1; k < n; k <<= 1) {
            for (T i = 0; i < n; i += 2 * k) {
                for (T j = 0; j < k; j++) {
                    cp z = a[i + j + k] * roots[j + k];
                    a[i + j + k] = a[i + j] - z;
                    a[i + j] = a[i + j] + z;
                }
            }
        }
    }

    vector<cp> fa, fb;

    vector<T> multiply(vector<T> &a, vector<T> &b) {
        T need = a.size() + b.size() - 1;
        T nbase = 0;
        while ((1 << nbase) < need) nbase++;
        ensure_base(nbase);
        T sz = 1 << nbase;
        if (sz > (T) fa.size())
            fa.resize(static_cast<unsigned long>(sz));
        for (T i = 0; i < sz; i++) {
            T x = (i < (T) a.size() ? a[i] : 0);
            T y = (i < (T) b.size() ? b[i] : 0);
            fa[i] = cp(x, y);
        }
        fft(fa, sz);
        cp r(0, -0.25 / sz);
        for (T i = 0; i <= (sz >> 1); i++) {
            T j = (sz - i) & (sz - 1);
            cp z = (fa[j] * fa[j] - conj(fa[i] * fa[i])) * r;
            if (i != j) {
                fa[j] = (fa[i] * fa[i] - conj(fa[j] * fa[j])) * r;
            }
            fa[i] = z;
        }
        fft(fa, sz);
        vector<T> res(static_cast<unsigned long>(need));
        for (T i = 0; i < need; i++) {
            res[i] = fa[i].x + 0.5;
        }
        return res;
    }
}

class solver {
private:
    vector<int> vl,ans;
    int n, k;
public:
    solver(int n, int k): n(n), k(k), vl(k, 0), ans(k, 0){};
    vector<int> check(vector<int> &a)
    {
        for(int i=0;i<(int)a.size();i++)
            if(a[i]) a[i%k]=1;
        a.resize(k);
        return a;
    }
    void work() {
        for(int i = 0, x; i < n; i++) {
            scanf("%d",&x);
            vl[x % k] = 1;
        }
        vl[0]=1;
        ans[0]=1;
        for (int x = 100000; x; x >>= 1) {
            if(x&1)
            {
                ans = fft::multiply(ans, vl);
                ans = check(ans);
            }
            vl = fft::multiply(vl, vl);
            vl = check(vl);
        }
        vector<int> real;
        for(int i=0;i<k;++i) if(ans[i]) real.push_back(i);
        printf("%d\n",(int)real.size());
        for(const auto &ret: real) printf("%d ", ret);
        puts("");
    }
};

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int n, m;
    scanf("%d%d",&n,&m);
    (new solver(n, m))->work();
    return 0;
}