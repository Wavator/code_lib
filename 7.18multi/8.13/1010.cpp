#pragma optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i,a,n) for(int i=(a);i<(n);++i)
#define per(i,a,n) for(int i=(n)-1;i>=(a);--i)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
#ifdef Wavator
#define debug(fmt, ...) fprintf(stderr, "func[%s] line %d: %s = " fmt "\n", \
                __func__, __LINE__, #__VA_ARGS__, __VA_ARGS__), fflush(stderr)
#define err(x) cerr << "func[" << __func__ << "] line " << __LINE__ << ": " \
                    << #x << " = " << x << endl << flush
#else
#define debug(...) 99
    #define err(x) 99
#endif
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int mod = (int) 1e9 + 7;

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
namespace Quick_out {
    static const int BUFFER_MAX_SIZE = 1<<18;
    char buf[BUFFER_MAX_SIZE], *ph = buf, *pt = buf + BUFFER_MAX_SIZE;
    char tmp[100];
    const double dx[15] = {5e-1,5e-2,5e-3,5e-4,5e-5,5e-6,5e-7,5e-8,5e-9,5e-10,5e-11,5e-12,5e-13,5e-14,5e-15};
    inline void my_flush() {
        fwrite(buf, sizeof(char), ph - buf, stdout);
        ph = buf;
    }
    inline void pc(char c) {
        *(ph++) = c;
        if (ph == pt) my_flush();
    }
    inline void ps(const char *s) {
        for (int i = 0; s[i]; ++i) pc(s[i]);
    }
    inline void ps(const string&s) {
        ps(s.c_str());
    }
    template<class T>
    inline void pi(T x, char ec = '\n') {
        if (x < 0) pc('-'), x = -x;
        int len = 0;
        if (!x) tmp[len++] = '0';
        for(;x;) tmp[len++] = x % 10 + '0', x /= 10;
        for(;len;)  pc(tmp[--len]);
        pc(ec);
    }
    inline void pd(double x, int fix = 8, char bc = '\n') {
        x += dx[fix];
        if (x < 0) pc('-'), x = -x;
        pi((long long)x, '.');
        x -= (long long)x;
        for(;fix--;) {
            x *= 10;
            pc('0' + (int)x);
            x -= (int)x;
        }
        pc(bc);
    }
    struct Quick_{~Quick_(){my_flush();}}oooOoooOO;
}
using Quick_in::sc;
using Quick_in::read;
using Quick_in::gline;
using Quick_in::gs;
using Quick_in::nc;
using Quick_out::pi;
using Quick_out::pc;
using Quick_out::ps;
using Quick_out::pd;
struct mat{
    long long mp[10][10];  //¾ØÕó
    int n,m;
    mat(int _n,int _m){
        n=_n,m=_m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                mp[i][j]=0;
    }
    mat operator+(const mat &b)const{
        mat tmp(n,m);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                tmp.mp[i][j]=mp[i][j]+b.mp[i][j];
                tmp.mp[i][j]%=mod;
            }
        return tmp;
    }

    mat operator*(const mat &b)const{
        mat ret(n,b.m);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                for(int k=0;k<m;k++){
                    ret.mp[i][j]+=mp[i][k]*b.mp[k][j];
                    ret.mp[i][j]%=mod;
                }
        return ret;
    }

    mat operator^(long long k)const{
        mat ret(n,m),b(n,m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                b.mp[i][j]=mp[i][j];
            ret.mp[i][i]=1;
        }
        while(k){
            if(k&1)
                ret=ret*b;
            b=b*b;
            k>>=1;
        }
        return ret;
    }
    long long *operator[](const int m) {
        return mp[m];
    }
};




signed main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int T;
    sc(T);
    while (T--) {
        int A,B,C,D,P,n;
        sc(A,B);
        sc(C,D);
        sc(P,n);
        if (n==1) {
            pi(A);
            continue;
        }
        if (n==2) {
            pi(B);
            continue;
        }
        mat a=mat(3,1);
        a[0][0]=B; a[1][0]=A; a[2][0]=1;
        mat base=mat(3,3);
        base[0][0]=D; base[0][1]=C; base[1][0]=1; base[2][2]=1;
        int tmp=(int)sqrt(P);
        mat b=a;
        for (int i=3;i<=min(tmp,n);i++)
        {
            base[0][2]=P/i;
            b=base*b;
        }
        if (tmp>=n)
        {
            pi(b[0][0]);
            continue;
        }
        int L=1,R=tmp;
        for (int i=(int)sqrt(P);i>=0;i--) {
            L=max(L,R+1);
            if (i==1) R=P;
            else if (i==0) R=n;
            else {
                R=P/i;
            }
            L=max(3,L);
            base[0][2]=i;
            R=min(R,n);
            if (L>R) continue;
            b=(base^(R-L+1))*b;
            if (R==n) break;
        }
        pi(b[0][0]);
    }
    return 0;
}