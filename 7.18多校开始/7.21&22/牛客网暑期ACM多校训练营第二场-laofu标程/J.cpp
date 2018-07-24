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
const LL OO=1e18;
const int mod=1e9+7;

const int N=1e6+100;

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
using io::putc;
using io::gi;
using io::gs;
using io::ps;
using io::print;

int a[N],s[N],f[N];
#define y1 y_1
int x1[N],y1[N],x2[N],y2[N],tp[N];
int n,m;
bool die[N];
#define id(x,y) (((x)-1)*m+(y))
void add(int k,int *f) {
	++f[id(x1[k],y1[k])];
	if (x2[k]<n) --f[id(x2[k]+1,y1[k])];
	if (y2[k]<m) --f[id(x1[k],y2[k]+1)];
	if (x2[k]<n&&y2[k]<m) ++f[id(x2[k]+1,y2[k]+1)];
}
void work(int *s) {
	int i,j,t;
	for (i=t=1;i<=n;i++)
		for (j=1;j<=m;j++,t++) {
			if (i>1) s[t]+=s[t-m];
			if (j>1) s[t]+=s[t-1];
			if (i>1&&j>1) s[t]-=s[t-m-1];
		}
}
int main()
{
	int i,v,T;
	gi(n),gi(m),gi(T);
	for (i=1;i<=n*m;i++)
		gi(a[i]);
	for (i=1;i<=T;i++) {
		gi(x1[i]),gi(y1[i]),gi(x2[i]),gi(y2[i]),gi(tp[i]);
		add(i,s);
	}
	work(s);
	for (v=0;v<20;v++) {
		for (i=1;i<=n*m;i++) f[i]=0;
		for (i=1;i<=T;i++)
			if (tp[i]>>v&1) {
				add(i,f);
			}
		work(f);
		for (i=1;i<=n*m;i++)
			if (a[i]>>v&1) {
				if (f[i]!=s[i]) {
					die[i]=true;
				}
			} else {
				if (f[i]) {
					die[i]=true;
				}
			}
	}
	v=0;
	for (i=1;i<=n*m;i++) {
		v+=die[i];
	}
	print(v);putc('\n');
	return 0;
}
