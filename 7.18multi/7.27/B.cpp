#include <bits/stdc++.h>
using namespace std;
inline int query(int x) {
    cout << x << '\n' << flush;
    cin >> x;
    return x;
}
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int x, n;
    cin>>x>>n;
    vector<int> ret(n, 0);
    for(int i=0;i<n;++i) {
        ret[i] = query(1);
        if (!ret[i])return 0;
    }
    int l=0,r=x+1,mid,gg=-1;
    while(l^r){
        mid=l+r>>1;
        int m = query(mid);
        if(!m)return 0;
        ++gg;
        if(gg>=n)gg=0;
        if(ret[gg]==-1)m=-m;
        if(m!=1)r=mid;
        else l=mid+1;
    }
    query(l);
    return 0;
}