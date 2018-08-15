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
typedef long long ll;
const int N = 205;
int cal(char s[N][N], int n, int m)
{
    int cnt=0;
    for (int i=0;i<n;i++)
    {
        bool flag=true;
        int now1=0;
        for (int j=0;j<m;j++)
        {
            if (s[i][j]=='(') now1++;
            else if (now1) now1--; else flag=false;
        }
        if (now1) flag=false;
        if (flag) cnt++;
    }
    for (int i=0;i<m;i++)
    {
        bool flag=true;
        int now1=0;
        for (int j=0;j<n;j++)
        {
            if (s[j][i]=='(') now1++;
            else if (now1) now1--; else flag=false;
        }
        if (now1) flag=false;
        if (flag) cnt++;
    }
    return cnt;

}

void print(char p[N][N], int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            printf("%c", p[i][j]);
        }
        puts("");
    }
}

char s[N][N], t[N][N];
const char le = '(', ri = ')';
int main() {
    int T;
    for (scanf("%d", &T); T--;)
    {
        int n, m;
        bool f = false;
        scanf("%d%d",&n, &m);
        if ((n + m) & 1)
        {
            if (m & 1)
            {
                f = true;
                swap(n, m);
            }
        } else {
            if (n < m)
            {
                swap(n, m);
                f = true;
            }
        }
        rep(i, 0, n)
        {
            if (i & 1)
            {
                s[i][0] = le;
                s[i][m - 1] = ri;
                rep(j, 1, m - 1)
                {
                    s[i][j] = (j & 1)? le: ri;
                }
            }
            else
            {
                rep(j, 0, m)
                {
                    s[i][j] = (j & 1)? ri: le;
                }
            }
        }
        if (f)
        {
            rep(i,0,max(n,m))
            {
                rep(j,i + 1,max(n,m))
                {
                    swap(s[i][j], s[j][i]);
                }
            }
            swap(n, m);
        }
        rep(i,0,n)rep(j,0,m)t[i][j]=le;
        if ((n % 2 == 0) && (m % 2 == 0))
        {
            rep(i,0,m){
                t[0][i]=le;
                t[n-1][i]=ri;
            }
            rep(i,1,n-1)
            {
                t[i][0]=le;
                t[i][m-1]=ri;
                rep(j,1,m-1)t[i][j]=((i+j)&1)?le:ri;
            }
        }
        print((cal(s, n, m) > cal(t, n, m)? s: t), n, m);
    }
    return 0;
}