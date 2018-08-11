/*************************************************************************
    > File Name: G.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com
    > Created Time: 2018-08-11 00:27:02
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
//wavator cai a!
ll T,p;
ll F,G;
ll prime[665000],miu[MAXN];
bool is_prime[10000005];
ll sieve(ll n)
{
    ll p=0;
    for(ll i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(ll i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(ll j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
void genmiu(ll n)
{
    ll p=0;
    memset(miu,0,sizeof(miu));
    miu[1]=1;
    for(ll i=2;i<=n;i++)
    {
        if(is_prime[i]) {p++; miu[i]=-1;}
        for(ll j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            miu[i*prime[j]]=i%prime[j]?-miu[i]:0;
            if(i%prime[j]==0) break;
        }
    }
}
vector<ll> save;
void fact(ll x)
{
    save.clear();
    for(ll i=0;i<p;i++)
    {
        if(x<=10000000&&is_prime[x])
        {
            save.push_back(1); return;
        }
        if(x==1) return;
        if(x%prime[i]==0)
        {
            ll cnt=0;
            while(x%prime[i]==0) {x=x/prime[i]; cnt++;}
            save.push_back(cnt);
        }
    }
    if(x>1) save.push_back(1);
}
ll cal(ll x)
{
    fact(x);
    ll cal1=1,cal2=1,cal3=1;
    for(ll i=0;i<(int)save.size();i++)
        cal1=cal1*(save[i]+1)*(save[i]+2)/2;
    for(ll i=0;i<(int)save.size();i++)
        cal2=cal2*(save[i]/2+1);
    for(ll i=0;i<(int)save.size();i++)
        if(save[i]%3) {cal3=0; break;}
    return (cal1+3*cal2+2*cal3)/6;
}
int main()
{
    p=sieve(10000000);genmiu(100000);
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld",&F,&G);
        if(F%G) {puts("0"); continue;}
        F=F/G;
        if(F%G) {puts("0"); continue;}
        F=F/G;
        ll ans=0;
        for(ll i=1;1LL*i*i*i<=F;i++)
        {
            if(F%(1LL*i*i*i)) continue;
            ans+=miu[i]*cal(F/(1LL*i*i*i));
        }
        printf("%lld\n",ans);
    }
    return 0;
}