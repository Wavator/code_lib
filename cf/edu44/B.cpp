#include <bits/stdc++.h>
#ifdef Wavator

#define Debug(...) fprintf(stderr, __VA_ARGS__);

#else

#define Debug(...) 98;

#define cerr if (false) cout

#endif

#define pb push_back

#define fi firse

#define se second

using namespace std;

template <typename T> inline bool read(T &x) {
    char c = getchar();
    bool f = false;
    for (x = 0; !isdigit(c); c = getchar()) {
        if (c == EOF)
            return false;
        if (c == '-') {
            f = true;
        }
    }
    for (; isdigit(c); c = getchar()) {
        x = x * 10 + c - '0';
    }
    if (f) {
        x = -x;
    }
    return true;
}

template <typename A, typename B> inline bool read(A &x, B&y) {
    return read(x) && read(y);
}

template <typename A, typename B, typename C> inline bool read(A &x, B &y, C &z) {
    return read(x) && read(y) && read(z);
}

template <typename A, typename B, typename C, typename D> inline bool read(A &a, B &b, C &c, D &d) {
    return read(a) && read(b) && read(c) && read(d);
}

const int N = 2005;
char mz[N][N];

int cnt[N];
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int n, m;

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i)    scanf("%s", mz[i] + 1);

    for (int i = 1; i <= n; ++i)    for (int j = 1; j <= m; ++j)
            if (mz[i][j] == '1')
                cnt[j]++;
    for (int i = 1; i <= n; ++i)    {
        bool flg=1;
        for (int j = 1; j <= m; ++j)    {
            if (mz[i][j] == '1'&&cnt[j] == 1){
                flg=0;
                break;
            }
        }
        if(flg)
        {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
