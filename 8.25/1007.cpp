#include<bits/stdc++.h>
#define MAXN 20005
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define rec(i,x) for(int i=0;i<x;i++)
#define REC(i,x) for(int i=1;i<=x;i++)
#define Rec(i,f,t) for(LL i=f;i<=t;i++)
#define P pair<int,int>
#define LL long long
#define mms(x) memset(x,0,sizeof(x))
using namespace std;
LL A[MAXN];
LL vis[MAXN];
LL huan[MAXN*2];
LL pre[MAXN*2];
LL tot;
list<LL> q;
LL getans(LL rst){
    q.clear();
    LL mxn=0;
    q.push_front(0);
    for(LL i=1;i<=tot;i++){
        while(!q.empty()&&pre[q.front()]>pre[i]){
            q.pop_front();
        }
        q.push_front(i);
        while(!q.empty()&&i-q.back()>rst){
            q.pop_back();
        }
        mxn=max(mxn,pre[i]-pre[q.back()]);
    }
    return mxn;
}
int main(){
    int T;
    scanf("%d",&T);
    int CASE=0;
    while(T--){
        memset(vis,0,sizeof(vis));
        LL n,s,m,k;
        scanf("%lld%lld%lld%lld",&n,&s,&m,&k);
        rec(i,n){
            scanf("%lld",&A[i]);
        }
        LL Tans=0;
        for(LL ii=0;ii<n;ii++){
            if(!vis[ii]){
                tot=0;
                LL cur=ii;
                LL sm=0;
                LL ans=0;
                while(!vis[cur]){
                    huan[++tot]=A[cur];
                    sm+=A[cur];
                    vis[cur]=1;
                    cur=(cur+k)%n;
                }
                LL rst=0;
                if(sm>0){
                    ans+=(m/tot)*sm;
                    rst=m%tot;
                }else{
                    rst=min(m,tot);
                }
                LL up=tot;
                for(LL j=1;j<=up;j++){
                    huan[++tot]=huan[j];
                }
                pre[0]=0;
                for(LL i=1;i<=tot;i++){
                    pre[i]=pre[i-1]+huan[i];
                }
                Tans=max(Tans,ans+getans(rst));
                if(sm>0){
                    ans=(m/up-1)*sm;
                    rst=up;
                    Tans=max(Tans,ans+getans(rst));
                }
            }
        }
        printf("Case #%d: %lld\n",++CASE,max(0LL,s-Tans));
    }
    return 0;
}
