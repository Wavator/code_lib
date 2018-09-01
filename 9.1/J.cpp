#include<bits/stdc++.h>
using namespace std;
const int N = (int)2e7 + 5;
bool isp[N];
int p[N],dp[N],sum[N];
int main(){
    memset(isp,true,sizeof(isp));
    for(int i = 2; i < N; ++i) {
        if (isp[i]) {
            p[++*p]=i;
        }
        for(int j=1;j<=p[0],i*p[j]<N;++j){
            isp[i*p[j]]=false;
            dp[i*p[j]]=p[j];
            if(i%p[j]==0){
                break;
            }
        }
    }
    sum[1]=1;
    for(int i=2;i<N;++i){
        if(!dp[i]){
            sum[i]=2;
        }else{
            if((i/dp[i])%(dp[i]*dp[i])==0)sum[i]=0;
            else if((i/dp[i])%dp[i]==0)sum[i]=sum[i/dp[i]]/2;
            else sum[i]=sum[i/dp[i]]<<1;
        }
    }
    for(int i=1;i<N;++i)sum[i]+=sum[i-1];
    int T;
    for(scanf("%d", &T); T--; ) {
        int n;
        scanf("%d", &n);
        printf("%d\n", sum[n]);
    }
    return 0;
}
