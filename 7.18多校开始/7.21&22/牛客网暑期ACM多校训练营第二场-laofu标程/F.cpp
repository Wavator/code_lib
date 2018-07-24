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

int qpow(int x,int y) {
	int ans=1;
	while (y) {
		if (y&1) ans=1LL*ans*x%mod;
		x=1LL*x*x%mod;y>>=1;
	}
	return ans;
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

typedef double db;
#define dbformat "%lf"
const db eps=1e-8;

inline int dcmp(const db &x) { return (x>eps)-(x<-eps); }

struct P{
	db x,y;
	inline db mo2() { return x*x+y*y; }
	inline db mo() { return sqrt(mo2()); }
	inline db angle() { return atan2(y,x); }
	inline void readint() { gi(x),gi(y); }
	inline void readdb() { scanf(dbformat dbformat,&x,&y); }
	inline P rot90() { return (P){-y,x}; }
	inline P rot(db r) {
		db Sin=sin(r),Cos=cos(r);
		return (P){x*Cos-y*Sin,x*Sin+y*Cos};
	}
	inline void uni() {
		db d=mo();
		if (dcmp(d))
			x/=d,y/=d;
	}
};
inline bool operator < (const P &a,const P &b) { return dcmp(a.x-b.x)?a.x<b.x:a.y<b.y; }
inline bool operator == (const P &a,const P&b) { return !dcmp(a.x-b.x)&&!dcmp(a.y-b.y); }
inline bool operator != (const P &a,const P &b) { return dcmp(a.x-b.x)||dcmp(a.y-b.y); }
inline P operator + (const P &a,const P &b) { return (P){a.x+b.x,a.y+b.y}; }
inline P operator - (const P &a,const P &b) { return (P){a.x-b.x,a.y-b.y}; }
inline P operator * (const P &p,const db &t) { return (P){p.x*t,p.y*t}; }
inline P operator / (const P &p,const db &t) { return (P){p.x/t,p.y/t}; }
inline db operator * (const P &a,const P &b) { return a.x*b.y-a.y*b.x; }
inline db dot(const P &a,const P&b) { return a.x*b.x+a.y*b.y; }
inline db dis_point2(const P &a,const P &b) { return (a-b).mo2(); }
inline db dis_point(const P &a,const P &b) { return (a-b).mo(); }

struct line{
	P a,b;
	inline db angle() { return (b-a).angle(); }
};

inline bool in_point_line(const P &p,const line &l) {//判点在直线上
	return dcmp((p-l.a)*(l.b-l.a))==0;
}

inline bool in_halfplane(const P &p,const line &l) {//判点在半平面内
	return (p-l.a)*(l.b-l.a)<=eps;
}

inline bool in_point_segment(const P &p,const line &l) {//判点在线段上
	return in_point_line(p,l)&&dcmp(dot(p-l.a,l.b-l.a))>=0&&dcmp(dot(p-l.b,l.a-l.b))>=0;
}

inline db dis_point_line(const P &p,const line &l) {//点到直线距离
	return fabs((p-l.a)*(l.b-l.a))/dis_point(l.a,l.b);
}

inline bool cross_segment_segment(const line &a,const line &b) {//判断两线段是否相交
	return dcmp((b.a-a.a)*(a.b-a.a))*dcmp((b.b-a.a)*(a.b-a.a))!=1&&
		dcmp((a.a-b.a)*(b.b-b.a))*dcmp((a.b-b.a)*(b.b-b.a))!=1;
}

inline P cross_line_line(const line &a,const line &b) {//直线交点
	db s1=(b.a-a.a)*(a.b-a.a);
	db s2=(a.b-a.a)*(b.b-a.a);
	return b.a+(b.b-b.a)*(s1/(s1+s2));
}

inline db dis_point_segment(const P &p,const line &l) {//点到线段距离
	if (dot(p-l.a,l.b-l.a)<=0) return dis_point(p,l.a);
	if (dot(p-l.b,l.a-l.b)<=0) return dis_point(p,l.b);
	return dis_point_line(p,l);
}

inline db dis_segment_segment(const line &a,const line &b) {//线段与线段距离
	if (cross_segment_segment(a,b))
		return 0;
	return min(min(dis_point_segment(a.a,b),dis_point_segment(a.b,b))
			   ,min(dis_point_segment(b.a,a),dis_point_segment(b.b,a)));
}

inline P proj_point_line(const P &p,const line &l) {//点在直线上的投影
	return l.a+(l.b-l.a)*(dot(p-l.a,l.b-l.a)/dis_point2(l.b,l.a));
}

struct circle{ P o; db r; };

inline int in_point_cirlce(const P &p,const circle &c) {//点在圆的位置 1:外部 0:圆上 -1:圆内
	return dcmp(dis_point(p,c.o)-c.r);
}

inline int in_line_circle(const line &l,const circle &c) {//直线在圆的位置 1:相离 0:相切 -1:相交
	return dcmp(dis_point_line(c.o,l)-c.r);
}

inline int in_circle_circle(const circle &a,const circle &b) {//两圆的位置关系：
	//0:内含 1:内切 2:相交 3:外切 4:外离
	if (a.r<b.r) return in_circle_circle(b,a);
	db dis=dis_point(a.o,b.o);
	if (dcmp(a.r+b.r-dis)>=0) return dcmp(a.r+b.r-dis)+3;
	return dcmp(dis+b.r-a.r)+1;
}

inline pair<P,P> cross_line_circle(const line &l,const circle &c) {//求直线和圆的交点
	P o=proj_point_line(c.o,l);
	P d=(l.b-l.a);d.uni();
	db len=sqrt(c.r*c.r-dis_point2(c.o,o));
	d=d*len;
	return mp(o-d,o+d);
}

inline pair<P,P> cross_circle_circle(const circle &a,const circle &b) {//求两圆的交点
	db len=dis_point2(a.o,b.o);
	db t=a.r*a.r+len-b.r*b.r;
	P e=a.o+(b.o-a.o)*(t/2/len);
	db p=sqrt(a.r*a.r-t);
	P d=(b.o-a.o).rot90()*(p/sqrt(len));
	return mp(e+d,e-d);
}

inline pair<P,P> proj_point_circle(P p,const circle &c) {//求点到圆的切点
	db dis2=dis_point2(p,c.o);
	db h=c.r*c.r*(dis2-c.r*c.r)/dis2;
	db w=sqrt(c.r*c.r-h);h=sqrt(h);
	p=p-c.o;p.uni();
	return mp(c.o+p*w+p.rot90()*h,c.o+p*w-p.rot90()*h);
}

inline pair<line,line> proj_circle_circle_out(const circle &a,const circle &b) {//求两个圆的外公切线
	if (!dcmp(a.r-b.r)) {
		P p=(b.o-a.o).rot90();p.uni();
		return mp((line){a.o+p*a.r,b.o+p*b.r},(line){a.o-p*a.r,b.o-p*b.r});
	}
	if (a.r<b.r)
		return proj_circle_circle_out(b,a);
	pair<P,P>p=proj_point_circle(b.o,(circle){a.o,a.r-b.r});
	P d1=(p.first-a.o)*(b.r/(a.r-b.r));
	P d2=(p.second-a.o)*(b.r/(a.r-b.r));
	return mp((line){p.first+d1,b.o+d1},(line){p.first+d2,b.o+d2});
}

inline pair<line,line> proj_circle_circle_in(const circle &a,const circle &b) {//求两个圆的内公切线
	if (a.r<b.r)
		return proj_circle_circle_in(b,a);
	pair<P,P>p=proj_point_circle(b.o,(circle){a.o,a.r+b.r});
	P d1=(p.first-a.o)*(b.r/(a.r+b.r));
	P d2=(p.first-a.o)*(b.r/(a.r+b.r));
	return mp((line){p.first-d1,b.o-d1},(line){p.second-d2,b.o-d2});
}

namespace dinic{
	
	const int N=1e5+100,M=3e6+100;
	
	typedef LL flow_type;
	const flow_type flow_oo=1e18;
	int head[N],nxt[M],to[M],tot=1;flow_type w[M];
	int S,T,dep[N],cur[N],q[N];
	void init(int _T) {
		S=0,T=_T;
		for (int i=S;i<=T;i++) head[i]=0;
		tot=1;
	}
	void link(int a,int b,flow_type _w) {
		to[++tot]=b,nxt[tot]=head[a],head[a]=tot,w[tot]=_w;
		to[++tot]=a,nxt[tot]=head[b],head[b]=tot,w[tot]=0;
	}
	bool bfs() {
		int i,k,l,r;
		for (i=S;i<=T;i++) dep[i]=0;
		for (l=0,dep[q[r=1]=T]=1;l!=r;)
			for (i=head[k=q[++l]];i;i=nxt[i])
				if (w[i^1]&&!dep[to[i]])
					dep[q[++r]=to[i]]=dep[k]+1;
		return dep[S];
	}
	flow_type dfs(int k,flow_type low) {
		if (k==T) return low;
		flow_type s=0,x;
		for (int &i=cur[k];i;i=nxt[i])
			if (w[i]&&dep[to[i]]==dep[k]-1)
				if (x=dfs(to[i],min(low-s,w[i]))) {
					s+=x,w[i]-=x,w[i^1]+=x;
					if (s==low) return s;
				}
		return s;
	}
	LL solve() {
		LL ans=0;
		while (bfs()) {
			for (int i=S;i<=T;i++) cur[i]=head[i];
			ans+=dfs(S,flow_oo);
		}
		return ans;
	}
}

const int N=1010;
P a[N],b[20];
int rid[20];
bitset<N>bit[N];
int main()
{
	int n,m,T,i,x,t,lim,s,k,id;P o;
	gi(n),gi(m),gi(T);
	dinic::init(n+m+1);
	for (i=1;i<=n;i++) a[i].readint(),gi(x),dinic::link(0,i,x),bit[i][i]=1;
	for (i=1;i<=T;i++) b[i].readint(),gi(rid[i]);
	for (id=1;id<=m;id++) {
		o.readint();t=0;gi(s);gi(lim);
		while (s--) {
			gi(k);
			for (i=1;i<=T;i++)
				if (dis_point_segment(b[i],(line){o,a[k]})<=rid[i]+eps)
					break;
			if (i>T) {
				if (t) bit[k]|=bit[t];
				t=k;
			}
		}
		if (t) {
			for (k=bit[t]._Find_first();k<N;k=bit[t]._Find_next(k))
				dinic::link(k,n+id,OO);
			dinic::link(n+id,n+m+1,lim);
		}
	}
	print(dinic::solve());
	return 0;
}
