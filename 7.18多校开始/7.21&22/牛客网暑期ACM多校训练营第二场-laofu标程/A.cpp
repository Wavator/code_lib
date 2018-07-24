#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<ctime>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<assert.h>
using namespace std;

typedef long long LL;

const int INF=2147483647;

LL getint()
{
    LL res=0,p=1;
    char ch=getchar();
    while ((ch<'0'||ch>'9') && ch!='-') ch = getchar();
    if (ch=='-') p=-1,ch=getchar();
    while (ch>='0'&&ch<='9') res=res*10+ch-'0',ch=getchar();
    return res*p;
}

const LL MOD=1000000007;
const int n=100000;
int T,k;
LL dp[100050][2];

int main()
{
    T=getint();
	assert(0<=T&&T<=1e5);
    k=getint();
	assert(1<=k&&k<=1e5);
    dp[0][0]=1;
    LL i,l,r,ans;
    for (i=1;i<=n;i++) {
        if (i>=k) dp[i][1]=dp[i-k][0];
        dp[i][0]=(dp[i-1][0]+dp[i-1][1])%MOD;
    }
    for (i=1;i<=n;i++) dp[i][0]=(dp[i][0]+dp[i-1][0]+dp[i][1])%MOD;
    while (T--) {
        l=getint();
        r=getint();
		assert(1<=l&&l<=r&&r<=1e5);
        ans=dp[r][0];
        if (l) ans=ans-dp[l-1][0];
        ans=(ans%MOD+MOD)%MOD;
        printf("%lld\n",ans);
    }
    return 0;
}
