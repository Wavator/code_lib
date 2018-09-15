#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
const int maxn = 25;
const int maxs = 10005;
const int mod = 1000000007;
int T,n,q,s,dp[maxs];
int temp,v[maxn],c[maxn];
int main(void)
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&q);
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d",&v[i],&c[i]);
            for(int j = 0; j < c[i]; j++)
                for(int k = maxs-1; k >= 0; k--)
                {
                    temp = (1<<j)*v[i];
                    if(k - temp < 0) continue;
                    dp[k] = (dp[k]+dp[k - temp])%mod;
                }
        }
        for(int i = 0; i < q; i++)
        {
            scanf("%d",&s);
            printf("%d\n",dp[s]);
        }
    }
    return 0;
}
