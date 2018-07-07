#include <bits/stdc++.h>
using namespace std;
const int N = 10000 + 100;
struct edge {
    int y;
    edge * next;
};
const int M = N << 1;
edge e[M], *li[N];
int etop;
void init() {
    memset(li, 0, sizeof(li));
    etop = 0;
}
inline void add_edge(int u, int v) {
    //cout << u << ' ' << v << endl;
    e[etop].y = v;
    e[etop].next = li[u];
    li[u] = &e[etop++];
}

int ind[N];

int x[N<<1], y[N<<1], fa[N], pp[N<<1];
int find(int u) {
    return fa[u] == u ? u : fa[u] = find(fa[u]);
}

//int id[N];

int main() {
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        getchar();
        init();
        char op;
        for (int i = 1; i <= n; ++i)
            fa[i] = i;
        int xx = m;
        int exact = n;
        for (int x, y, ptr = 1;m--;) {
            scanf("%d%*c%c%*c%d",&x,&op,&y);
            getchar();
            ::x[ptr] = ++x;
            ::y[ptr] = ++y;
            if (op == '=')
            {
                //fa[find(x)] = find(y);
                x = find(x);
                y = find(y);
                if (x != y)
                    exact--;
                fa[x] = y;
                pp[ptr]=0;
            }
            else
                pp[ptr] = (op == '>'? 1: -1);
            ptr++;
        }
        memset(ind,0,sizeof(ind));
//        int cnt = 0;
//        for (int i = 1; i <= n; ++i) {
//            id[cnt++] = find(i);
//        }
//        sort(id,id+cnt);
//        cnt=unique(id,id+cnt)-id;
//        for (int i = 1; i <= xx; ++i) {
//            static int a, b;
//            a = find(x[i]), b = find(y[i]);
//            a = lower_bound(id,id+cnt,a)-id;
//            b = lower_bound(id,id+cnt,b)-id;
//            a++, b++;
//            if (a == b)
//                continue;
//            //cerr << pp[i] << endl;
//            if (~pp[i]) {
//                add_edge(a,b);
//                ind[b]++;
//            } else {
//                add_edge(b,a);
//                ind[a]++;
//            }
//        }
        for (int i = 1; i <= xx; ++i) {
            int a = x[i], b = y[i];
            a = find(a);
            b = find(b);
            if (pp[i] == 0)
                continue;
            if (pp[i] == 1) {
                add_edge(a,b);
                ind[b]++;
            } else {
                add_edge(b,a);
                ind[a]++;
            }
        }
        //m = edges;
        static int que[N<<1];
        int head = 0, tail = 0;
        for (int i = 1; i <= n; ++i) {
            if (ind[i] == 0 && i == find(i)) {
                que[tail++] = i;
            }
        }
        edge * t;
        bool f = false;
        while (head != tail) {
            if (tail - head > 1)
                f = true;
            exact--;
            int u = que[head++];
            int v;
            for (t = li[u]; t; t = t->next) {
                ind[v = t->y]--;
                if (ind[v] == 0) {
                    que[tail++] = v;
                }
            }
        }
        if (exact)
            puts("CONFLICT");
        else puts(f == 0? "OK": "UNCERTAIN");
    }
    return 0;
}