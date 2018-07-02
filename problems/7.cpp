#include <bits/stdc++.h>
using namespace std;

template <typename T> inline void read(T &x) {
    static char ch; static bool f;
    for (f = false, ch = getchar_unlocked(); !isdigit(ch); ch = getchar_unlocked()) {
        if (ch == 45) {
            f = true;
        }
    }
    for (x = 0; isdigit(ch); ch = getchar_unlocked()) {
        x = x * 10 + ch - 48;
    }
    if (f) {
        x = -x;
    }
}

const int N = 500020;
struct data {
    int val, pos;
    data(int val = 0, int pos = 0): val(val), pos(pos){}
    friend inline data operator + (const data &l, const data &r) {
        return l.val < r.val? l: r;
    }
    inline void update(const int &o) {
        val = max(o, val);
    }
};

struct Node {
    data d;
    int l, r;
    Node(data d = data(), int l = 0, int r = 0) :d(d.val, d.pos), l(l), r(r){}
    inline bool operator < (const Node &o) const {
        return d.val > o.d.val;
    }
};



data a[N << 2];

int tag[N << 2];

inline void push_up(const int &rt) {
    a[rt] = a[rt << 1] + a[rt << 1 | 1];
}

inline void push_down(const int &rt) {
    if (tag[rt]) {
        tag[rt << 1] = max(tag[rt], tag[rt << 1]);
        tag[rt << 1 | 1] = max(tag[rt], tag[rt << 1 | 1]);
        a[rt << 1].update(tag[rt]);
        a[rt << 1 | 1].update(tag[rt]);
        tag[rt] = 0;
    }
}

inline void build(int l, int r, int rt) {
    if (l == r) {
        read(a[rt].val);
        a[rt].pos = l;
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
    push_up(rt);
}

inline void change(const int &L, const int &R, int l, int r, int rt, const int &k) {
    if (l >= L && r <= R) {
        tag[rt] = max(tag[rt], k);
        a[rt].update(k);
        return;
    }
    push_down(rt);
    int mid = l + r >> 1;
    if (L <= mid)
        change(L, R, l, mid, rt << 1, k);
    if (R > mid)
        change(L, R, mid + 1, r, rt << 1 | 1, k);
    push_up(rt);
}

inline data query(const int &L, const int &R, int l, int r, int rt) {
    if (l >= L && r <= R)
        return a[rt];
    push_down(rt);
    int mid = l + r >> 1;
    if (L > mid)
        return query(L, R, mid + 1, r, rt << 1 | 1);
    if (R <= mid)
        return query(L, R, l, mid, rt << 1);
    return (query(L, R, l, mid, rt << 1) + query(L, R, mid + 1, r, rt << 1 | 1));
}

priority_queue<Node> q;
int n, m;
int ans[N];
inline void task() {
    static int op, l, r, k, x;
    read(op);
    read(l);
    read(r);
    read(k);
    if (op == 1) {
        change(l, r, 1, n, 1, k);
        return;
    }
    read(x);
    if (x > r - l + 1) {
        puts("-1");
        return;
    }
    while (!q.empty()) q.pop();
    int tp;
    Node now = Node(query(l, r, 1, n, 1), l, r);
    q.push(now);
    for(tp = 0; tp < x; ++tp) {
        now = q.top();
        q.pop();
        if (now.d.val >= k) {
            puts("-1");
            return;
        }
        ans[tp] = now.d.val;
        int pos = now.d.pos;
        if (pos > now.l)
            q.push(Node(query(now.l, pos - 1, 1, n, 1), now.l, pos - 1));
        if (pos < now.r)
            q.push(Node(query(pos + 1, now.r, 1, n, 1), pos + 1, now.r));
    }
    printf("%d", ans[0]);
    for(int i = 1; i < tp; ++i) {
        printf(" %d", ans[i]);
    }
    putchar(10);
}

int main() {
    read(n);
    build(1, n, 1);
    for (read(m); m--; task());
    return 0;
}