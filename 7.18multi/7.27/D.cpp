#include <bits/stdc++.h>
using namespace std;
class solver {
private:
    int n;
    vector<vector<int> > ch;
    vector<int> id, a, ans;
    function<void(int)> pre_dfs = [&](int x) {
        if (id[x] <= 2 || id[x] == 5) {
            pre_dfs(ch[x][0]);
            pre_dfs(ch[x][1]);
            if (id[x] == 1) {
                a[x] = a[ch[x][0]] & a[ch[x][1]];
            } else if (id[x] == 2) {
                a[x] = a[ch[x][0]] | a[ch[x][1]];
            } else {
                a[x] = a[ch[x][0]] ^ a[ch[x][1]];
            }
        } else if (id[x] == 3) {
            pre_dfs(ch[x][0]);
            a[x] = !a[ch[x][0]];
        }
    };

    function<void(int, int)> dfs = [&](int x, int ss) {
        if (id[x] == 1) {
            if (a[ch[x][0]] > a[ch[x][1]]) {
                swap(ch[x][0], ch[x][1]);
            }
            if (!a[ch[x][1]]) {
                dfs(ch[x][0], 0);
                dfs(ch[x][1], 0);
            } else if (!a[ch[x][0]] && a[ch[x][1]] == 1) {
                dfs(ch[x][0], ss);
                dfs(ch[x][1], 0);
            } else {
                for(int i=0;i<2;++i)dfs(ch[x][i],ss);
            }
        } else if (id[x]==2){
            if (a[ch[x][0]] > a[ch[x][1]]) {
                swap(ch[x][0], ch[x][1]);
            }
            if (!a[ch[x][1]]) {
                dfs(ch[x][0], ss);
                dfs(ch[x][1], ss);
            } else if (!a[ch[x][0]] && a[ch[x][1]] == 1) {
                dfs(ch[x][0], 0);
                dfs(ch[x][1], ss);
            } else {
                for(int i=0;i<2;++i)dfs(ch[x][i],0);
            }
        } else if (id[x] == 3) {
            dfs(ch[x][0], ss);
        } else if (id[x] == 5) {
            for(int i=0;i<2;++i)dfs(ch[x][i], ss);
        } else {
            ans[x]=((ss==1)?(a[1]):(a[1]^1));
        }
    };
public:
    solver(int n): n(n), ch(n + 1, vector<int>(2, 0)), a(n + 1, 0), ans(n + 1, 0), id(n + 1, 0) {
        char s[10];
        for (int i = 1; i <= n; ++i) {
            scanf("%s", s);
            if (s[0] == 'A') {
                scanf("%d%d", &ch[i][0], &ch[i][1]);
                id[i] = 1;
                continue;
            }
            if (s[0] == 'O') {
                scanf("%d%d", &ch[i][0], &ch[i][1]);
                id[i] = 2;
                continue;
            }
            if (s[0] == 'N') {
                scanf("%d", &ch[i][0]);
                id[i] = 3;
                continue;
            }
            if (s[0] == 'I') {
                scanf("%d", &a[i]);
                id[i] = 4;
                continue;
            }
            scanf("%d%d", &ch[i][0], &ch[i][1]);
            id[i] = 5;
        }
    }
    void solve() {
        pre_dfs(1);
        dfs(1,1);
        for(int i = 1; i <= n; ++i){
            if(id[i]==4) printf("%d",ans[i]^1);
        }
        printf("\n");
    }

};
int main() {
    int n;
    scanf("%d", &n);
    (new solver(n))->solve();
    return 0;
}