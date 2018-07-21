#include<bits/stdc++.h>

using namespace std;
const int maxn = 1005;
const int inf = 0x3f3f3f3f;
double n,w,v,u;
int main(){
    scanf("%lf%lf%lf%lf", &n, &w, &v, &u);
    double minnum = inf*1.0;
    double maxnum = -inf*1.0;
    for(int i = 0 ; i < n; ++i){
        double x,y;
        scanf("%lf %lf", &x, &y);
        minnum = min(minnum, x - y*v/u);
        maxnum = max(maxnum, x - y*v/u);
    }
    if (minnum >= 0.0) printf("%.10lf\n", w/u);
    else if(maxnum >= 0.0) printf("%.10lf\n", maxnum/v + w/u);
            else printf("%.10lf\n", w/u);
    return 0;
}