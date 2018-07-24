#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<bitset>
#include<assert.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

template<typename T>inline bool upmin(T &x,T y) { return y<x?x=y,1:0; }
template<typename T>inline bool upmax(T &x,T y) { return x<y?x=y,1:0; }

typedef unsigned int u32;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double lod;
typedef pair<int,int> PR;
typedef vector<int> VI;

const lod pi=acos(-1);
const int oo=1<<30;
const LL OO=2e18;
const int mod=1e9+7;

const int N=1e5+100;

int qpow(int x,int y) {
	int ans=1;
	while (y) {
		if (y&1) ans=1LL*ans*x%mod;
		x=1LL*x*x%mod;y>>=1;
	}
	return ans;
}

int n,m;
struct Q{ int x,y,id; };
Q operator - (const Q &a,const Q &b) { return (Q){a.x-b.x,a.y-b.y}; }
LL operator * (const Q &a,const Q &b) { return 1LL*a.x*b.y-1LL*a.y*b.x; }
lod K(const Q &a,const Q &b) { return ((lod)b.y-a.y)/((lod)b.x-a.x); }
struct Convexhull{
	Q p[N],cur[N];
	lod ans[N];
	set<int>G,O;
	void work() {
		sort(p+1,p+1+n+m,[&](Q a,Q b){return a.x==b.x?a.id<b.id:a.x<b.x;});
		for (int i=1;i<=n+m;i++)
			if (!p[i].id) G.insert(p[i].x),O.insert(p[i].y);
		assert(G.size()==n);
		for (int i=1,top=0,l,r,mid;i<=n+m;i++) {
			if (p[i].id) {
				assert(G.find(p[i].x)==G.end());
				assert(O.find(p[i].y)==O.end());
				if (top) {
					Q o=p[i];
					l=1,r=top;
					while (l!=r) {
						mid=(l+r)>>1;
						if (K(cur[mid],o)<K(cur[mid+1],o)) r=mid;
						else l=mid+1;
					}
					ans[o.id]=K(cur[l],o);
				} else ans[p[i].id]=1;
			} else {
				Q t=p[i];
				while (top>1&&(t-cur[top-1])*(cur[top]-cur[top-1])<=0) top--;
				cur[++top]=t;
			}
		}
	}
}T0,T1;
int main()
{
	int i;lod ans;
	cin>>n;
	assert(n<=5e4);
	for (i=1;i<=n+m;i++) {
		scanf("%d%d",&T0.p[i].x,&T0.p[i].y);
		if (i<=n) {
			assert(-1e9<=T0.p[i].x&&T0.p[i].x<=1e9);
			assert(-1e9<=T0.p[i].y&&T0.p[i].y<=1e9);
		} else {
			assert(-2e9<=T0.p[i].x&&T0.p[i].x<=2e9);
			assert(-2e9<=T0.p[i].y&&T0.p[i].y<=2e9);
		}
		T1.p[i].x=-T0.p[i].x;
		T1.p[i].y=-T0.p[i].y;
		if (i>n)
			T0.p[i].id=T1.p[i].id=i-n;
		if (i==n)
			cin>>m,assert(m<=5e4);
	}
	T0.work();
	T1.work();
	for (i=1;i<=m;i++) {
		ans=min(T0.ans[i],T1.ans[i]);
		ans*=-1;
		if (ans<=0) puts("No cross");
		else printf("%.15Lf\n",ans);
	}
	return 0;
}
