#include<bits/stdc++.h>
using namespace std;
#ifdef Wavator
#include "local_debug.h"
#else
#define debug(...)
#endif


struct segment_tree {
    int n;
    vector<int> mi;

    void init(int _n) {
        n = _n;
        mi.resize(4*n+16);
    }

    auto push_up(int rt)->void {
        mi[rt] = min(mi[rt << 1], mi[rt << 1 | 1]);
    }

    void build(int l, int r, int rt, vector<deque<int> > &o) {
        if (l == r) {
            mi[rt] = o[l].front();
            o[l].pop_front();
            return;
        }
        int mid = l + r >> 1;
        build(l, mid, rt << 1, o);
        build(mid + 1, r, rt << 1 | 1, o);
        push_up(rt);
    }

    void change(int pos, int v, int l, int r, int rt) {
        if (l == r) {
            mi[rt] = v;
            return;
        }
        int mid = l + r >> 1;
        if (pos <= mid) {
            change(pos, v, l, mid, rt << 1);
        } else {
            change(pos, v, mid + 1, r, rt << 1 | 1);
        }
        push_up(rt);
    }

    int query(int L, int R, int l, int r, int rt) {
        if (l >= L && r <= R) {
            return mi[rt];
        }
        int mid = l + r >> 1;
        if (R <= mid) {
            return query(L, R, l, mid, rt << 1);
        } else if (L > mid) {
            return query(L, R, mid + 1, r, rt << 1 | 1);
        }
        return min(query(L, R, l, mid, rt << 1), query(L, R, mid + 1, r, rt << 1 | 1));
    }

    auto modify(int pos, int v)->void {
        change(pos, v, 1, n, 1);
    }

    auto ask(int l, int r)->int {
        return query(l, r, 1, n, 1);
    }

};
constexpr int N = 100100;

segment_tree seg;
constexpr int inf = 0x3f3f3f3f;
int x[N];

struct _ans{
    int l, r;
    auto print()->void {
        printf("%d %d\n", l, r);
    }
} ans[N];
namespace wyc {
    void ast_mle(bool f) {
        if (!f)
            for (std::vector<char *> wyc; wyc.size() >= 0;)
                wyc.push_back((char *) malloc(sizeof(char) * (int) 1e5));
    }

    void ast_wa(bool f) {
        if (!f)exit(0 * puts("wyc"));
    }

    void ast_tle(bool f) {
        if (!f) for (std::vector<int> wyc; wyc.size() >= 0;wyc.size()?wyc.pop_back():wyc.push_back(1));
    }
}
signed main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", x + i);
    }
    int mx = *max_element(x + 1, x + n + 1);
    //mx = 10000;
    vector<deque<int> > des((unsigned) mx + 10);
    for (int i = 1; i <= n; ++i) {
        des[x[i]].push_back(i);
    }
    for (auto &t: des) {
        t.push_back(inf);
        sort(t.begin(), t.end());
    }
    seg.init(mx);
    seg.build(1, mx, 1, des);
    int tmp_r = 0;
    for (int i = 1; i < N; i++) {
        if (ans[i - 1].l != n) {
            tmp_r += m;
        }
        ans[i].l = ans[i - 1].l;
        while (tmp_r) {
            int now = seg.ask(1, min(tmp_r, mx));
            if (now == inf) {
                break;
            }
            tmp_r -= x[now];
            ans[i].l++;
            wyc::ast_mle(des[x[now]].size() != 0);
            seg.modify(x[now], des[x[now]].front());
            des[x[now]].pop_front();
        }
        ans[i].r = tmp_r;
    }
    int q, x;
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &x);
        ans[x].print();
    }
    return 0;
}