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

LL d[N];
bool o[N];
int main()
{
	int T,n,i,s2;
	gi(T);assert(0<T&&T<=5);
	LL s1;
	while (T--) {
		gi(n);
		assert(0<n&&n<=100000);
		for (i=1;i<=n;i++) gi(d[i]),assert(0<=d[i]&&d[i]<(1LL<<31));
		s1=s2=0;
		for (i=1;i<n;i++) {
			o[i]=d[i+1]>d[i];
			if (o[i])
				s1+=d[i+1]-d[i];
		}
		for (i=2;i<n;i++)
			o[i]|=o[i-1]&&d[i+1]==d[i];
		for (i=n-2;i>0;i--)
			o[i]|=o[i+1]&&d[i+1]==d[i];
		for (i=1;i<n;i++)
			s2+=o[i]&&!o[i-1];
		print(s1);putc(' ');print(s2*2);putc('\n');
	}
	return 0;
}
