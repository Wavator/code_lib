#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<time.h>
#include<math.h>
#include<memory>
#include<vector>
#include<bitset>
#include<fstream>
#include<stdio.h>
#include<utility>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define nb main
#define csl signed
int u[1005][1005],d[1005][1005],l[1005][1005],r[1005][1005];
char a[1005][1005];
int val[1005][1005];
int ssum1[1005][1005];
int ssum2[1005][1005];
csl nb()
{
#ifdef cubercsl
    freopen("test.in", "r", stdin);
#endif
    int n,m;
    scanf("%d%d",&n,&m);
    int i,j;
    for (i=0;i<n;i++)
    {
        scanf("%s",a[i]);
    }
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            if (a[i][j]=='.')
            {
                u[i][j]=-1;
                d[i][j]=-1;
                l[i][j]=-1;
                r[i][j]=-1;
            }
            else
            {
                if (i==0)
                {
                    u[i][j]=0;
                }
                else
                {
                    u[i][j]=u[i-1][j]+1;
                }
                if (j==0)
                {
                    l[i][j]=0;
                }
                else
                {
                    l[i][j]=l[i][j-1]+1;
                }
            }
        }
    }
    for (i=n-1;i>=0;i--)
    {
        for (j=m-1;j>=0;j--)
        {
            if (a[i][j]=='*')
            {
                if (i==n-1)
                {
                    d[i][j]=0;
                }
                else
                {
                    d[i][j]=d[i+1][j]+1;
                }
                if (j==m-1)
                {
                    r[i][j]=0;
                }
                else
                {
                    r[i][j]=r[i][j+1]+1;
                }
            }
        }
    }
    int cnt=0;
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            int k=min(min(u[i][j],d[i][j]),min(l[i][j],r[i][j]));
            val[i][j]=k;
            if ((k==0)||(k==-1)) continue;
            ssum1[i-k][j]++;
            ssum1[i+k+1][j]--;
            ssum2[i][j-k]++;
            ssum2[i][j+k+1]--;
            cnt++;
        }
    }
    for (i=0;i<n;i++)
    {
        int tot=0;
        for (j=0;j<m;j++)
        {
            tot+=ssum2[i][j];
            if ((a[i][j]=='.')&&(tot!=0))
            {
                return 1;
            }
            if (a[i][j]!='*') continue;
            if (tot!=0)
            {
                a[i][j]='#';
            }
        }
    }
    for (j=0;j<m;j++)
    {
        int tot=0;
        for (i=0;i<n;i++)
        {
            tot+=ssum1[i][j];
            if ((a[i][j]=='.')&&(tot!=0))
            {
                return 1;
            }
            if (a[i][j]!='*') continue;
            if (tot!=0)
            {
                a[i][j]='#';
            }
        }
    }
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            if (a[i][j]=='*')
            {
                puts("-1");
                return 0;
            }
        }
    }
    printf("%d\n",cnt);
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            if (val[i][j]>0)
            {
                printf("%d %d %d\n",i+1,j+1,val[i][j]);
            }
        }
    }
    return 0;
}