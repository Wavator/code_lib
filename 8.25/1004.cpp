#pragma optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#include "local_debug.h"
#else
#define debug(...)
#endif
#define pb push_back
#define rep(i,a,n) for(int i=(a);i<(n);++i)
#define per(i,a,n) for(int i=(n)-1;i>=(a);--i)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
ll alpppa,n, bt,c;
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld", &n,&alpppa);
        if (n==0)
        {
            printf("-1 -1\n");
            continue;
        }
        if (n > 2)
        {
            printf("-1 -1\n");
            continue;
        }
        if (alpppa&1)
        {
            ll temp= (alpppa-1)/2;
            bt=temp*temp*2+2*temp;
            c=bt+1;

        } else {
            ll tmp=alpppa/2;
            bt=tmp*tmp-1;
            c=tmp*tmp+1;
        }
        if (n == 1) {
            bt=alpppa;
            c=2*alpppa;
            printf("%lld %lld\n", bt,c);
        }
        else {
            printf("%lld %lld\n", bt,c);
        }
    }
    return 0;
}