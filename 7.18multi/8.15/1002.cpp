#pragma optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#include "local_debug.h"
#else
#define debug(...)
#endif
#define pb push_back
#define rep(i,a,n) for(int i=(a);i<(n);++i)
#define per(i,a,n) for(int i=(n)-1;i>=(a);--i)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
const db pi = acos(-1.0);
const db eps = 1e-8;
inline db sqr(db x)
{
    return x*x;
}
struct Vector {
    db x, y;
    Vector(db x=0,db y=0):x(x),y(y){}
    void scan()
    {
        scanf("%lf%lf",&x,&y);
    }
} tri[4];
Vector operator+(const Vector &a, const Vector &b) {
    return (Vector){a.x + b.x, a.y + b.y};
}
Vector operator-(const Vector &a, const Vector &b) {
    return (Vector){a.x - b.x, a.y - b.y};
}
Vector operator*(const Vector &a, const db &k) {
    return (Vector){a.x * k, a.y * k};
}
Vector operator/(const Vector &a, const db &k) {
    return (Vector){a.x / k, a.y / k};
}
db operator*(const Vector &a, const Vector &b) {
    return a.x * b.x + a.y * b.y;
}
db operator^(const Vector &a, const Vector &b) {
    return a.x * b.y - a.y * b.x;
}
inline int sgn(db x) {
    return x < -eps ? -1 : (x > eps ? 1 : 0);
}
inline db Area2(Vector &a, Vector &b, Vector &c)
{
    Vector t1 = b - a;
    Vector t2 = c - a;
    return fabs(t1 ^ t2);
}
inline db dot(Vector &a, Vector &b, Vector &c)
{
    Vector t1 = b - a;
    Vector t2 = c - a;
    return t1 * t2;
}
inline db dist(Vector &a, Vector &b)
{
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

db angle(Vector a, Vector b)
{
    return acos(a * b / sqrt(a * a)/ sqrt(b * b));
}
Vector rot(Vector a, db angle)
{
    return Vector(a.x * cos(angle) - a.y * sin(angle), a.x * sin(angle) + a.y * cos(angle));
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--)
    {
        rep(i,0,3)tri[i].scan();
        db w;
        scanf("%lf", &w);
        double area = Area2(tri[0], tri[1], tri[2]);
        bool flag = false;
        for (int i = 0; i < 3; i ++)
        {
            double len = dist(tri[i], tri[(i + 1) % 3]);
            if (sgn(w - area / len) >= 0)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            printf("impossible\n");
            continue;
        }
        double ans = 1e9;
        for (int i = 0; i < 3; i ++)
            for (int j = 0; j < 3; j ++) if (i != j)
                {
                    int k = 3 - i - j;
                    double len = dist(tri[i], tri[j]);
                    double ang = angle(tri[k] - tri[i], tri[j] - tri[i]);
                    if (sgn(w - len) >= 0)
                    {
                        Vector v = rot(Vector(dist(tri[i], tri[k]), 0), ang);
                        if (sgn(v.y) >= 0 && sgn(v.x) >= 0 && sgn(v.x - w) <= 0)
                            ans = min(ans, v.y);
                        v = rot(Vector(dist(tri[i], tri[k]), 0), -ang);
                        if (sgn(v.y) >= 0 && sgn(v.x) >= 0 && sgn(v.x - w) <= 0)
                            ans = min(ans, v.y);
                    }
                    else
                    {
                        double base = acos(w / len);
                        double h = sqrt(max(0.0, sqr(len) - sqr(w)));
                        Vector v = rot(Vector(dist(tri[i], tri[k]), 0), base + ang);
                        if (sgn(v.y) >= 0 && sgn(v.x) >= 0 && sgn(v.x - w) <= 0)
                            ans = min(ans, max(h, v.y));
                        v = rot(Vector(dist(tri[i], tri[k]), 0), base - ang);
                        if (sgn(v.y) >= 0 && sgn(v.x) >= 0 && sgn(v.x - w) <= 0)
                            ans = min(ans, max(h, v.y));
                    }
                }
        printf("%.9f\n", ans);
    }
    return 0;
}