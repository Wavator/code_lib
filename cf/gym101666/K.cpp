#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005;
bool vis[N];

bool a[N][N];

vector<int> ans;
int n;

void dfs(int u) {
    if (ans.size() == n - 1) {
        reverse(ans.begin(), ans.end());
        for (auto & v:ans)
            printf("%d ", v);
        puts("0");
        exit(0);
    }
    for (int i = 1; i <= n; ++i) {
        if (a[u][i] && !vis[i])
        {
            vis[i] = true;
            ans.push_back(i - 1);
            dfs(i);
        }
    }
}

char s[N];

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s + 1);
        for (int j = 1; j <= n; ++j) {
            a[i][j] = (s[j] == '1');
        }
    }
    vis[1] = 1;
    dfs(1);
    puts("impossible");
    return 0;
}
