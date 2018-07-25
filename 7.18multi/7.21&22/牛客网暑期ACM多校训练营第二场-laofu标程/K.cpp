#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<assert.h>
using namespace std;
int gi() {
	int w;char c;
	while (((c=getchar())<'0'||'9'<c)&&c!='-');
	w=c-'0';
	while ('0'<=(c=getchar())&&c<='9') w=(w<<3)+(w<<1)+c-'0';
	return w;
}
const int seed=131;
const int mod=1e9+7;
const int N=1e6+100;
int h[N],L[N],nxt[N];
inline int kmp(int *a,int n) {
	nxt[0]=0;
	int i,c,p;
	for (i=1;i<n&&a[i]==a[i+1];i++);i--;
	nxt[2]=i;c=2,p=2+nxt[2]-1;
	if (nxt[2]==n-1) return 1;
	for (i=3;i<=n;i++) {
		if (p<i||p-i+1<=nxt[i-c+1]) {
			nxt[i]=max(p-i+1,0);
			while (a[nxt[i]+i]==a[nxt[i]+1]) nxt[i]++;
			if (i+nxt[i]>n) return i-1;
			c=i,p=i+nxt[i]-1;
		}
		else nxt[i]=nxt[i-c+1];
	}
	return n;
}
int Val[N],Q[N];
#define val(x,y) Val[((x)-1)*m+(y)]
#define q(x,y) Q[((x)-1)*m+(y)]
int l[N],r[N],n,m;
int qq[N],w[N];
int key[26];
char s[N];
int main() {
	int i,j,a,b,ll,rr;char c;int ans=2147483647;
	n=gi(),m=gi();
	assert(0<n*m&&n*m<=1e6);
	for (i=0;i<26;i++) key[i]=rand();
	for (i=1;i<=n;i++) {
		scanf("%s",s+1);
		assert(strlen(s+1)==m);
		for (j=1;j<=m;j++) {
			c=s[j];assert('a'<=c&&c<='z');
			h[i]=(1LL*h[i]*seed+key[c-'a'])%mod;
			L[j]=(1LL*L[j]*seed+key[c-'a'])%mod;
		}
	}
	a=kmp(h,n);
	b=kmp(L,m);
	for (i=1;i<=n;i++) for (j=1;j<=m;j++) val(i,j)=gi(),assert(0<=val(i,j)&&val(i,j)<=1e9);
	for (i=1;i<=n;i++) l[i]=1,r[i]=0;
	for (j=1;j<b;j++)
		for (i=1;i<=n;i++) {
			while (l[i]<=r[i]&&val(i,j)>=val(i,q(i,r[i]))) r[i]--;
			q(i,++r[i])=j;
		}
	for (j=b;j<=m;j++) {
		ll=1,rr=0;
		for (i=1;i<a;i++) {
			if (l[i]<=r[i]&&q(i,l[i])<=j-b) l[i]++;
			while (l[i]<=r[i]&&val(i,j)>=val(i,q(i,r[i]))) r[i]--;
			q(i,++r[i])=j;
			while (ll<=rr&&val(i,q(i,l[i]))>=qq[rr]) rr--;
			qq[++rr]=val(i,q(i,l[i])),w[rr]=i;
		}
		for (i=a;i<=n;i++) {
			if (l[i]<=r[i]&&q(i,l[i])<=j-b) l[i]++;
			while (l[i]<=r[i]&&val(i,j)>=val(i,q(i,r[i]))) r[i]--;
			q(i,++r[i])=j;
			if (ll<=rr&&w[ll]<=i-a) ll++;
			while (ll<=rr&&val(i,q(i,l[i]))>=qq[rr]) rr--;
			qq[++rr]=val(i,q(i,l[i])),w[rr]=i;
			ans=min(ans,qq[ll]);
		}
	}
	cout<<1LL*(a+1)*(b+1)*ans<<endl;
	return 0;
}
