#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#include "local_debug.h"
#else
#define debug(...)
#endif
constexpr double eps = 1e-9;
auto sgn(double x) -> int{
    return x < -eps ? -1 : (x > eps ? 1 : 0);
}
auto sqr(double x) -> double{
    return x * x;
}
struct Vector {
    double x, y;
    Vector() {}
    Vector(double x, double y) : x(x), y(y) {}
    bool operator == (const Vector& p) const {
        return sgn(x - p.x) == 0 && sgn(y - p.y) == 0;
    }
    bool operator != (const Vector& p) const {
        return sgn(x - p.x) != 0 || sgn(y - p.y) != 0;
    }
    inline double length() const {
        return sqrt(sqr(x) + sqr(y));
    }
    inline double angle() const {
        return atan2(y, x);
    }
    friend Vector operator + (const Vector &a, const Vector & b) {
        return Vector(a.x + b.x, a.y + b.y);
    }
    friend Vector operator - (const Vector & a, const Vector & b) {
        return Vector(a.x - b.x, a.y - b.y);
    }
    friend Vector operator * (const Vector & v, double mul)
    {
        return Vector(v.x * mul, v.y * mul);
    }
    friend Vector operator / (const Vector & v, double div)
    {
        return Vector(v.x / div, v.y / div);
    }
    friend double operator ^ (const Vector & a, const Vector & b) {
        return a.x * b.y - a.y * b.x;
    }
    Vector norm() const {
        return *this / length();
    }
    Vector normal() const {
        return Vector(-y, x);
    }
};

struct Line {
    Vector p;
    Vector v;
    Line() {}
    Line(Vector p, Vector v) : p(p), v(v) {}
    friend Vector operator + (const Line &a, const Line &b) {
        double coef = (b.v ^ (a.p - b.p)) / (a.v ^ b.v);
        return a.p + a.v * coef;
    }

    bool operator & (const Vector &p) const {
        return sgn((v ^ ( p - this->p))) > 0;
    }
};

int half_plane(vector<Line> &lines, unsigned n, vector<Vector>& poly) {
    sort(lines.begin(), lines.end(), [](const Line &a, const Line &b) -> bool {
        return a.v.angle() < b.v.angle();
    });
    vector<Vector> p(n);
    vector<Line> q(n);
    int head = 0, tail = 0;
    q[0] = lines[0];
    for (int i = 1; i < n; i++) {
        while (head < tail && !(lines[i] & p[tail - 1])) {
            tail--;
        }
        while (head < tail && !(lines[i] & p[head])) {
            head++;
        }
        q[++tail] = lines[i];
        if (sgn(q[tail].v ^ q[tail - 1].v) == 0) {
            tail--;
            if (q[tail] & lines[i].p)
                q[tail] = lines[i];
        }
        if (head < tail) {
            p[tail - 1] = q[tail - 1] + q[tail];
        }
    }
    while (head < tail && !(q[head] & p[tail - 1])) {
        tail--;
    }
    if (tail - head <= 1) {
        return 0;
    }
    p[tail] = q[tail] + q[head];
    for (int i = head; i <= tail; i++) {
        poly.push_back(p[i]);
    }
    return poly.size();
}

auto calc(const Vector &a, const Vector &b, const Vector &c) ->double {
    return fabs((b - a) ^ (c - a));
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int T;
    for (cin >> T; T--; )
    {
        double r;
        int n;
        scanf("%d%lf", &n, &r);
        vector<Vector> p((unsigned)n);
        vector<Line> lines((unsigned)n);
        vector<Vector> ip((unsigned)n);
        for (auto &e: p) {
            scanf("%lf%lf", &e.x, &e.y);
        }
        for (int i = 0; i < n; ++i) {
            ip[i] = (p[i] - p[(i + 1) % n]).norm();
        }
        for (int i = 0; i < n; i ++) {
            lines[i] = Line(p[(i + 1) % n] + ip[i].normal() * r, ip[i]);
        }
        vector<Vector> hf;
        int m = half_plane(lines, (unsigned)n, hf);
        double ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = (i + 1) % m, k = (i + 2) % m; j != i && k != i; j = (j + 1) % m) {
                while (calc(hf[i], hf[j], hf[(k + 1) % m]) > calc(hf[i], hf[j], hf[k])) {
                    k = (k + 1) % m;
                }
                ans = max(ans, calc(hf[i], hf[j], hf[k]));
            }
        }
        printf("%.5f\n", ans);
    }
    return 0;
}