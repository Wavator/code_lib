#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,m,k,a=1,b=1,h,t,u,x,y;
vector<int> e[5001];
int c[5001],q[5001];
void f(int u,int w,int d){
    if(c[u]){if(d<k)x--;if(d<=k)y--;}
    for(int&v:e[u])if(v^w)f(v,u,d+1);
}
int main(){
    cin>>n>>m>>k;
    for(u=1;u<n;++u){
        cin>>x>>y;
        e[x].push_back(y),e[y].push_back(x);
    }
    for(q[t++]=1;h^t;){
        x=y=m;
        f(u=q[h++],0,0);
        a=1ll*x*a%mod;
        b=1ll*y*b%mod;
        c[u]=1;
        for(int&v:e[u])if(!c[v])q[t++]=v;
    }
    cout<<(a-b+mod)%mod;
}
