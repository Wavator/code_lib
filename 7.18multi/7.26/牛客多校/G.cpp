#include <bits/stdc++.h>
using namespace std;
int n,m,k,a=1,b=1,h,t,u,x,y,M=1e9+7;
vector<int> e[5001];
int c[5001],q[5001];
void f(int u,int w,int d){
    if(c[u]){if(d<k)x--;if(d<=k)y--;}
    for(int&v:e[u])if(v^w)f(v,u,d+1);
}
int main(){
    cin>>n>>m>>k;
    while(--n){
        cin>>x>>y;
        e[x].push_back(y),e[y].push_back(x);
    }
    for(q[t++]=1;h^t;){
        x=y=m;
        f(u=q[h++],0,0);
        a=1ll*x*a%M;
        b=1ll*y*b%M;
        c[u]=1;
        for(int&v:e[u])if(!c[v])q[t++]=v;
    }
    cout<<(a-b+M)%M;
}
