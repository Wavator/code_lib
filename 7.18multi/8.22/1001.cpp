#pragma optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#include "local_debug.h"
#else
#define debug(...)
#endif
typedef long long LL;
const int mod=998244353, G=3;
inline int add(int x,int y) {return (x+y>=mod) ? (x+y-mod) : (x+y);}
inline int dec(int x,int y) {return (x-y<0) ? (x-y+mod) : (x-y);}
inline int mul(int x,int y) {return (LL)x*y%mod;}
inline int power(int a,int b,int rs=1) {for(;b;b>>=1,a=mul(a,a)) if(b&1) rs=mul(rs,a); return rs;}

const int N=1<<20|1;
const int inv6=power(6,mod-2), inv2=(mod+1)/2, inv24=mul(inv2,mul(inv2,inv6));
int n,k,w[N],pos[N],A[N],B[N],tp[N],tp2[N],tp3[N];
inline void init(int nn) {
    for(k=1;k<=nn;k<<=1);
    for(int i=1;i<k;i++) pos[i]=(i&1) ? ((pos[i>>1]>>1)^(k>>1)) : (pos[i>>1]>>1);
}
inline void dft(int *a,int o=1) {
    for(int i=1;i<k;i++) if(pos[i]>i) swap(a[pos[i]],a[i]);
    for(int bl=1;bl<k;bl<<=1) {
        int tl=bl<<1, wn=power(G,(mod-1)/tl);
        w[0]=1; for(int i=1;i<bl;i++) w[i]=mul(w[i-1],wn);
        for(int bg=0;bg<k;bg+=tl)
            for(int j=0;j<bl;j++) {
                int &t1=a[bg+j], &t2=a[bg+j+bl], t=mul(t2,w[j]);
                t2=dec(t1,t); t1=add(t1,t);
            }
    }
    if(!~o) {
        const int inv=power(k,mod-2); reverse(a+1,a+k);
        for(int i=0;i<k;i++) a[i]=mul(a[i],inv);
    }
}
inline void solve(int l,int r) {
    if(l==r) {
        if(!l) A[l]=1;
        else A[l]=add(A[l],((l%3==1) ? mul(2,A[l/3]) : 0)), A[l]=mul(A[l],inv6);
        return;
    }
    int mid=(l+r)>>1, len=r-l;
    solve(l,mid); init(len*2+mid-l);
    memset(tp,0,sizeof(int)*k);
    memset(tp2,0,sizeof(int)*k);
    memset(tp3,0,sizeof(int)*k);
    memcpy(tp,A+l,sizeof(int)*(mid-l+1));
    memcpy(tp2,A,sizeof(int)*len);
    for(int i=0,j;(j=i*2)<=len;i++) tp3[j]=A[i];

    dft(tp); dft(tp2); dft(tp3);
    for(int i=0;i<k;i++) tp2[i]=mul(tp2[i],mul(tp2[i],tp[i]));
    dft(tp2,-1);
    if(!l) {
        for(int i=mid+1;i<=r;i++) A[i]=add(A[i],tp2[i-l-1]);
    } else {
        for(int i=mid+1;i<=r;i++) A[i]=add(A[i],mul(tp2[i-l-1],3));
    }
    for(int i=0;i<k;i++) tp[i]=mul(tp[i],tp3[i]);
    dft(tp,-1);
    for(int i=mid+1;i<=r;i++) A[i]=add(A[i],mul(tp[i-l-1],3));
    solve(mid+1,r);
}
namespace Quick_in {
    const int LEN=(1<<21)+1; char ibuf[LEN],*iH,*iT;int f,c;
#define gc() (iH==iT?(iT=(iH=ibuf)+fread(ibuf,1,LEN,stdin),(iH==iT?EOF:*iH++)):*iH++)
    inline char nc(){
        while((c=gc())<=32)if(c==-1)return -1;
        return (char)c;
    }
    template<class T> inline void sc(T&x) {
        for (f=1,c=gc();c<'0'||c>'9';c=gc()) if (c=='-') f=-1;
        for (x=0;c<='9'&&c>='0';c=gc()) x=x*10+(c&15); x*=f;
    }
    template<class T> inline bool read(T&x) {
        for (f=1,c=gc();c<'0'||c>'9';c=gc()){ if(c==-1)return 0;if(c=='-') f=-1; }
        for(x=c-48;;x=x*10+(c&15)){ if(!isdigit(c=gc()))break;}x*=f; return 1;
    }
    inline int gline(char*s) {
        int l=-1;
        for (c=gc();c<=32;c=gc())if(c==-1)return c;
        for (;c>32||c==' ';c=gc()){
            s[++l]=c;
        }
        s[l+1]=0;
        return l;
    }
    inline int gs(char *s) {
        int l=-1;
        for (c=gc();c<=32;c=gc())if(c==-1)return c;
        for (;c>32;c=gc()){
            s[++l]=c;
        }
        s[l+1]=0;
        return l;
    }
    template <typename A, typename B> inline void sc(A&x,B&y){sc(x),sc(y);};
    template <typename A, typename B> inline bool read(A&x,B&y){return read(x)&&read(y);};
}

using Quick_in::sc;
using Quick_in::read;
using Quick_in::gline;
using Quick_in::gs;
using Quick_in::nc;

namespace Quick_out {
    static const int BUFFER_MAX_SIZE = 1<<18;
    char buf[BUFFER_MAX_SIZE], *ph = buf, *pt = buf + BUFFER_MAX_SIZE;
    char tmp[100];
    const double dx[15] = {5e-1,5e-2,5e-3,5e-4,5e-5,5e-6,5e-7,5e-8,5e-9,5e-10,5e-11,5e-12,5e-13,5e-14,5e-15};
    inline void my_flush() {
        fwrite(buf, sizeof(char), ph - buf, stdout);
        ph = buf;
    }
    inline void oc(char c) {
        *(ph++) = c;
        if (ph == pt) my_flush();
    }
    inline void os(const char *s) {
        for (int i = 0; s[i]; ++i) oc(s[i]);
    }
    inline void os(const string&s) {
        os(s.c_str());
    }
    template<class T>
    inline void oi(T x, char ec = '\n') {
        if (x < 0) oc('-'), x = -x;
        int len = 0;
        if (!x) tmp[len++] = '0';
        for(;x;) tmp[len++] = x % 10 + '0', x /= 10;
        for(;len;)  oc(tmp[--len]);
        oc(ec);
    }
    inline void od(double x, int fix = 8, char bc = '\n') {
        x += dx[fix];
        if (x < 0) oc('-'), x = -x;
        oi((long long)x, '.');
        x -= (long long)x;
        for(;fix--;) {
            x *= 10;
            oc('0' + (int)x);
            x -= (int)x;
        }
        oc(bc);
    }
    struct Quick_{~Quick_(){my_flush();}}oooOoooOO;
}

using Quick_out::oi;
using Quick_out::oc;
using Quick_out::os;
using Quick_out::od;
const int L=1e5;
int main() {
    solve(0,n=L); init(L*4);
    memset(tp,0,sizeof(int)*k);
    memset(tp2,0,sizeof(int)*k);
    memset(tp3,0,sizeof(int)*k);
    for(int i=0;i<=n;i++) tp[i]=A[i];
    for(int i=0;i*2<=n;i++) tp2[i*2]=A[i];
    for(int i=0;i*3<=n;i++) tp3[i*3]=A[i];
    dft(tp); dft(tp2); dft(tp3);
    for(int i=0;i<k;i++) {
        int s=0;
        s=add(s,power(tp[i],4));
        s=add(s,mul(6,mul(tp2[i],power(tp[i],2))));
        s=add(s,mul(3,power(tp2[i],2)));
        s=add(s,mul(8,mul(tp3[i],tp[i])));
        tp[i]=s;
    } dft(tp,-1);
    for(int i=0;i<=n;i++)
        B[i]=add(tp[i],(!(i%4)) ? mul(6,A[i/4]) : 0), B[i]=mul(B[i],inv24);
    for(int i=n;i;i--) B[i]=B[i-1]; B[0]=0;
    for(int i=0;i<=n;i+=2) B[i]=add(B[i],A[i/2]);
    memset(tp,0,sizeof(int)*k);
    for(int i=1;i<=n;i++) tp[i]=A[i];
    dft(tp);
    for(int i=0;i<k;i++) tp[i]=mul(tp[i],tp[i]);
    dft(tp,-1);
    for(int i=1;i<=n;i++) B[i]=dec(B[i],mul(tp[i],inv2));
    for(int i=2;i<=n;i+=2) B[i]=dec(B[i],mul(A[i/2],inv2));
    int T;
    for(sc(T);T;T--)
    {
        static int x;
        sc(x);
        oi(B[x], ' ');
        oi(A[x]);
    }
    return 0;
}