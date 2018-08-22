#pragma optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#include "local_debug.h"
#else
#define debug(...)
#endif
typedef long long ll;
const int N = 1000200;
ll f[N][2], fp[N], tdp[N];
const int INF = INT_MAX;
char s[N], t[N], a[N], b[N];
inline void check_min(ll &x, const ll &b)
{
    if (x > b)
        x = b;
}
int main(){
    int T;
    for (scanf("%d", &T); T--;)
    {
        int n;
        scanf("%d%s%s%s", &n, s + 1, a + 1, b + 1);
        for(int i = 1;i <= n; ++i)
        {
            t[i] = '1' + '0' - s[i];
        }
        t[1] ++;
        for(int i = 1;i <= n; ++i)
        {
            if(t[i] == '2')
            {
                t[i] = '0';
                t[i + 1] ++;
            }
        }
        t[n + 1] = 0;
        fp[0] = tdp[0] = -1;
        for(int i = 1; i <= n; ++i){
            if(a[i] == '0')
                fp[i] = 1;
            else {
                fp[i] = fp[i - 1] == -1? fp[i - 1]: (fp[i - 1] << 1);
                check_min(fp[i], (int)1e9);
            }
            if(b[i] == '0'){
                tdp[i] = 1;
            }else{
                tdp[i] = tdp[i - 1] == -1? tdp[i - 1]: (tdp[i - 1] << 1);
                check_min(tdp[i], (int)1e9);
            }
        }
        for(int i = 0;i <= n + 1; ++i)
        {
            f[i][0] = f[i][1] = INF;
        }
        f[0][0] = 0;
        f[0][1] = 0;
        for(int i = 1; i <= n; ++i){
            if(s[i] == '0')
            {
                check_min(f[i][0], f[i - 1][0]);
                if(fp[i] != -1)
                {
                    check_min(f[i][0], f[i - 1][1] + fp[i]);
                }
            }
            else
            {
                if(fp[i] != -1)
                {
                    check_min(f[i][0], f[i - 1][0] + fp[i]);
                }
            }
            if(t[i] == '0')
            {
                check_min(f[i][1], f[i - 1][1]);
                if(tdp[i] != -1)
                {
                    check_min(f[i][1], f[i - 1][0] + tdp[i]);
                }
            }
            else
            {
                if(tdp[i] != -1)
                {
                    check_min(f[i][1],f[i - 1][1] + tdp[i]);
                }
            }
        }
        printf("%lld\n", min(f[n][0], f[n][1] + 1));
    }
    return 0;
}

