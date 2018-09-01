#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005;
#define int long long
vector<pair <int,int>> Color[10];
int m,n;
vector<int> yIndex[MAX];
int bottom[MAX];
long long calc(int col){
    memset(bottom,0,sizeof(bottom));
    for (int i = 1;i<=n;i++){
        yIndex[i].clear();
    }
    long long ans = 0;
    for (auto now:Color[col]){
        int ni = now.first,nj = now.second;
        for (int i = 1;i<=m;i++){
            yIndex[i].clear();
        }
        for (int i = 1;i<=m;i++){
            if (bottom[i]){
                yIndex[bottom[i]].push_back(i);
            }
        }
        int yl=1,yr=m;
        bool br = false;
        for (int ii = ni;ii>=1;ii--){
            for (vector<int>::iterator it = yIndex[ii].begin();it!=yIndex[ii].end();it++){
                int yy = *it;
                if (yy<nj){
                    yl = max(yl,yy+1);
                }else if (yy>nj){
                    yr = min (yr,yy-1);
                }else{
                    br = true;
                    break;
                }
            }
            if (br){
                break;
            }
            ans+=(n-ni+1)*(nj-yl+1)*(yr-nj+1);
        }
        bottom[nj] = ni;
    }

    return ans;
}

signed main(){
#ifdef Wavator
    freopen("test.in","r",stdin);
#endif
    int Cas;
    scanf("%lld",&Cas);
    int ks=1;
    while (Cas--){
        Color[1].clear();
        int k;
        scanf("%lld%lld%lld",&n,&m,&k);
        while(k--){
            int x,y;
            scanf("%lld%lld",&x,&y);
            Color[1].push_back(make_pair(x,y));
        }
        for (int i=0;i<=1;i++){
            if (!Color[i].empty()){
                sort(Color[i].begin(),Color[i].end());
            }
        }
        printf("Case #%lld: %lld\n",ks++,1ll*n*(n+1)*m*(m+1)/4 - calc(1));
    }
    return 0;
}