#include <bits/stdc++.h>
using namespace std;
const int N = 100002;

#ifdef Wavator

#define debug(...) fprintf(stderr, __VA_ARGS__)

#else


#define debug(...) 98;

#endif

struct _trie
{
    _trie * nxt[2];
    int value = N;

} * trie[N], tries[N * 16 * 20];

inline _trie * new_trie() {
    static int top = 0;;
    return &tries[top++];
}

inline void insert(int val, int who) {
    _trie * t = trie[who];
    t->value = min(val, t->value);
    for (int i = 18; ~i; --i) {
        int c = val >> i & 1;
        if (t->nxt[c] == nullptr)
            t->nxt[c] = new_trie();
        t = t->nxt[c];
        t->value = min(t->value, val);
    }
}

inline int query(int x, int who, int s) {
    _trie * t = trie[who];
    if (x % who || t->value + x > s)
        return -1;
    int res = 0;
    for (int i = 18; ~i; --i) {
        int c = x >> i & 1;
        c ^= 1;
        if ((t->nxt[c] == nullptr) || (t->nxt[c]->value + x > s))
            c ^= 1;
        res ^= (c << i);
        t = t->nxt[c];
    }
    return res;
}

bool contains[N];

vector<int> f[N];

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif

    for (int i = 1; i < N; ++i)
        for (int j = i; j < N; j += i)
            f[j].push_back(i);
    for (int i = 1; i < N; ++i)
        trie[i] = new_trie();
    int q;
    for (scanf("%d", &q); q--; ) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int x;
            scanf("%d", &x);
            if (!contains[x]) {
                contains[x] = true;
                for (int &ff: f[x])
                    insert(x, ff);
            }
        } else {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            printf("%d\n", query(x, y, z));
        }
    }
    return 0;
}
