#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

map<pair<int,int>,int > s;

inline void insert(int u,int pos,const int &val) {
    for (;pos<N;pos+=pos&-pos)
        s[{u,pos}]=max(s[{u,pos}],val);
}

inline int get(int u, int id) {
    int res=0;
    for(;id;id-=id&-id)
        if(s.count({u,id}))
            res=max(res,s[{u,id}]);
    return res;
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int n,m;
    scanf("%d%d",&n,&m);
    int ans=0;
    for(int u,v,w;m--;) {
        scanf("%d%d%d",&u,&v,&w);
        int len=1+get(u,w);
        insert(v,w+1,len);
        ans=max(ans,len);
    }
    cout<<ans<<endl;
    return 0;
}
