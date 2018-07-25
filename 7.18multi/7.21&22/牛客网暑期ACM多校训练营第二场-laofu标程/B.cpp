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
const LL OO=1LL<<62;
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

int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}

namespace io {
	const int L=(1<<21)+1;
	char ibuf[L],*iS,*iT,obuf[L],*oS=obuf,*oT=obuf+L-1,c,st[55];int f,tp;
#define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,L,stdin),(iS==iT?EOF:*iS++)):*iS++)
	inline char getc() {
		return gc();
	}
	inline void flush() {
		fwrite(obuf,1,oS-obuf,stdout);
		oS=obuf;
	}
	inline void putc(char x) { *oS++=x; if (oS==oT) flush(); }
	template<class I> inline void gi(I&x) {
		for (f=1,c=gc();c<'0'||c>'9';c=gc()) if (c=='-') f=-1;
		for (x=0;c<='9'&&c>='0';c=gc()) x=x*10+(c&15); x*=f;
	}
	template<class I> inline void print(I x) {
		if (!x) putc('0');
		if (x<0) putc('-'),x=-x;
		while (x) st[++tp]=x%10+'0',x/=10;
		while (tp) putc(st[tp--]);
	}
	inline void gs(char*s, int&l) {
		for (c=gc();c<'a'||c>'z';c=gc());
		for (l=0;c<='z'&&c>='a';c=gc()) s[l++]=c;
		s[l]=0;
	}
	inline void ps(const char*s) { for (int i=0,n=strlen(s);i<n;i++) putc(s[i]); }
	struct IOFLUSHER{ ~IOFLUSHER() { flush(); } } _ioflusher_;
};
using io::getc;
using io::putc;
using io::gi;
using io::gs;
using io::ps;
using io::print;

int p[N],d[N],f[N],st[N];
int vis[N];bool in[N];
LL dp[N][2],g[N][2];VI e[N];
//0:子树都买完最小代价
//1:子树都买完最小代价，且根是原价购买的
void dfs(int k) {
	dp[k][0]=p[k]-d[k];
	dp[k][1]=p[k];
	for (int t:e[k]) {
		dfs(t);
		dp[k][0]+=dp[t][0];
		dp[k][1]+=dp[t][0];
	}
	for (int t:e[k])
		upmin(dp[k][0],dp[k][1]-p[k]-dp[t][0]+dp[t][1]);
}
int main()
{
	int n,i,k,t=0,top;LL ans=0,cur;
	gi(n);
	assert(1<=n&&n<=1e5);
	for (i=1;i<=n;i++) gi(p[i]),assert(0<=p[i]&&p[i]<=1e9);
	for (i=1;i<=n;i++) gi(d[i]),assert(0<=d[i]&&d[i]<=p[i]);
	for (i=1;i<=n;i++) gi(f[i]),assert(1<=f[i]&&f[i]<=n);
	for (i=1;i<=n;i++)
		if (!vis[i]) {
			++t;
			for (k=i;!vis[k];k=f[k]) vis[k]=t;
			if (vis[k]==t)
				for (++t;vis[k]!=t;k=f[k]) vis[k]=t,in[k]=true;
		}
	for (i=1;i<=n;i++) if (!in[i]) e[f[i]].pb(i);
	for (i=1;i<=n;i++)
		if (in[i]) {
			top=0;
			for (k=i;in[k];k=f[k]) dfs(st[++top]=k),in[k]=false;

			if (top==1)
				ans+=dp[i][0];
			else {
				g[1][0]=dp[st[1]][0];g[1][1]=dp[st[1]][1];
				for (k=2;k<=top;k++) {
					g[k][1]=g[k-1][0]+dp[st[k]][1];
					g[k][0]=min(g[k-1][1]+dp[st[k]][1]-p[st[k]],g[k-1][0]+dp[st[k]][0]);
				}
				cur=g[top][0];
				g[1][0]=dp[st[1]][1]-p[st[1]];g[1][1]=OO;
				for (k=2;k<=top;k++) {
					g[k][1]=g[k-1][0]+dp[st[k]][1];
					g[k][0]=min(g[k-1][1]+dp[st[k]][1]-p[st[k]],g[k-1][0]+dp[st[k]][0]);
				}
				ans+=min(cur,g[top][1]);
			}
		}
	print(ans);
	return 0;
}
