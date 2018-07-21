#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull bas = 19260817;
const int N = 400005;
ull hash_base[N], power[N], hash_val[N];
char s[N];
int n, pos,m;
inline bool check(int len) {
    pos = -1;
    int c = 0;
    static int rank[N];
    for (int i = 0; i < n - len + 1; ++i) {
        rank[i] = i;
        hash_val[i] = hash_base[i] - hash_base[i + len] * power[len];
    }
    sort(rank, rank + n - len + 1, [&](const int &a, const int &b){
        return hash_val[a] < hash_val[b] || (hash_val[a] == hash_val[b] && a < b);
    });
    for (int i = 0; i < n - len + 1; ++i) {
        if (!i || hash_val[rank[i]] != hash_val[rank[i - 1]])
            c = 0;
        if (++c >= m && rank[i] > pos)
            pos = rank[i];
    }
    return pos >= 0;

}

int main() {
    power[0] = 1;
    for (int i = 1; i < N; ++i) {
        power[i] = power[i - 1] * bas;
    }
    while (scanf("%d",&m) && m) {
        getchar();
        scanf("%s", s);
        n = (int)strlen(s);
        hash_base[n] = 0;
        for (int i = n - 1; ~i; --i)
            hash_base[i] = hash_base[i + 1] * bas + s[i] - 'a';
        int l = 1, r = n + 1;
        if (!check(l)) {
            puts("none");
            continue;
        }
        int ans = pos;
        while (r > l + 1) {
            static int mid;
            mid = l + r >> 1;
            if (check(mid)) {
                l = mid;
                ans = pos;
            } else {
                r = mid;
            }
        }
        printf("%d %d\n", l, ans);
    }
    return 0;
}