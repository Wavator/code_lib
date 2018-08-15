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
char ans[4][4], s[5];
int main() {
    int T;
    for(scanf("%d", &T); T--; ){
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= 3; ++i) {
            scanf("%s", ans[i] + 1);
        }
        for(int i = 1; i <= n; ++i) {
            scanf("%s", s);
            int num = s[0] - '0';
            int op = s[1] == 'C';
            if(num == 1) {
                if(op) {
                    char t = ans[1][1];
                    ans[1][1] = ans[2][1];
                    ans[2][1] = ans[2][2];
                    ans[2][2] = ans[1][2];
                    ans[1][2] = t;
                }
                else {
                    char t = ans[1][1];
                    ans[1][1] = ans[1][2];
                    ans[1][2] = ans[2][2];
                    ans[2][2] = ans[2][1];
                    ans[2][1] = t;
                }
            }
            else if(num == 2) {
                if(op) {
                    char t = ans[1][2];
                    ans[1][2] = ans[2][2];
                    ans[2][2] = ans[2][3];
                    ans[2][3] = ans[1][3];
                    ans[1][3] = t;
                }
                else {
                    char t = ans[1][2];
                    ans[1][2] = ans[1][3];
                    ans[1][3] = ans[2][3];
                    ans[2][3] = ans[2][2];
                    ans[2][2] = t;
                }
            }
            else if(num == 3) {
                if(op) {
                    char t = ans[2][1];
                    ans[2][1] = ans[3][1];
                    ans[3][1] = ans[3][2];
                    ans[3][2] = ans[2][2];
                    ans[2][2] = t;
                }
                else {
                    char t = ans[2][1];
                    ans[2][1] = ans[2][2];
                    ans[2][2] = ans[3][2];
                    ans[3][2] = ans[3][1];
                    ans[3][1] = t;
                }
            }
            else {
                if(op) {
                    char t = ans[2][2];
                    ans[2][2] = ans[3][2];
                    ans[3][2] = ans[3][3];
                    ans[3][3] = ans[2][3];
                    ans[2][3] = t;
                }
                else {
                    char t = ans[2][2];
                    ans[2][2] = ans[2][3];
                    ans[2][3] = ans[3][3];
                    ans[3][3] = ans[3][2];
                    ans[3][2] = t;
                }
            }
        }
        for(int i = 1; i <= 3; ++i) {
            for(int j = 1; j <= 3; ++j) putchar(ans[i][j]);
            putchar('\n');
        }
    }
    return 0;
}