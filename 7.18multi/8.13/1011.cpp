#include <bits/stdc++.h>
using namespace std;
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
template <size_t N>
struct seg_tree
{
    static const int INF=0x3f3f3f3f;
    struct sg
    {
        int val, id;
    } s[N<<2];
    inline void push_up(int x)
    {
        s[x].val = -INF;
        if (s[x << 1].val > s[x].val)
            s[x] = s[x << 1];
        if (s[x << 1 | 1].val > s[x].val)
            s[x] = s[x << 1 | 1];
    }
    void build(int left, int right, int x)
    {
        s[x].val = 0;
        s[x].id = left;
        if (left == right) return;
        int mid = (left + right) / 2;
        build(left, mid, x << 1);
        build(mid + 1, right, x << 1 | 1);
    }
    void change(int pos, int v, int l, int r, int x) {
        if (l == r) {
            s[x].val += v;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) change(pos, v, l, mid, x << 1);
        else change(pos, v, mid + 1, r, x << 1 | 1);
        push_up(x);
    }
    int q(int n, int k)
    {
        if (s[1].val != k) return -1;
        int ret = s[1].id;
        change(s[1].id, -INF, 1, n, 1);
        return ret;
    }

};
const int K=10,N=100005;
struct node{
    int v,id;
    inline bool operator < (const node&o)const{
        return v<o.v;
    }
}a[K][N];

int b[N][K],v[K],ans[K];

seg_tree<N> s;

int main()
{
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int T;
    for(sc(T);T--;){
        int n,k;
        sc(n,k);
        for(int i=1;i<=k;++i)sc(v[i]);
        for(int i=1;i<=n;++i){
            for(int j=1;j<=k;++j)sc(a[j][i].v),a[j][i].id=i;
            for(int j=1;j<=k;++j)sc(b[i][j]);
        }
        //fprintf(stderr, "finish read\n");
        for(int i=1;i<=k;++i)sort(a[i]+1,a[i]+1+n);
        for(int i=1;i<=k;++i)ans[i]=1;
        s.build(1,n,1);
        //cerr<<s.s[1].id<<endl;
        //fprintf(stderr, "finish build\n");
        for (int i=1;i<=k;i++){
            while(ans[i] <= n && a[i][ans[i]].v <= v[i]) {
                s.change(a[i][ans[i]].id, 1, 1, n, 1);
                ans[i]++;
            }
        }
        //for(int i=0;i<20;++i)cerr<<s.s[i].v<<' ';cerr<<endl;
        //fprintf(stderr, "finish pre work\n");
        int res=0;
        for(;;){
            int remain=s.q(n,k);
            //cerr<<remain<<endl;
            if(remain==-1)
                break;
            ++res;
            for (int i=1;i<=k;i++) {
                v[i]+=b[remain][i];
                //cerr<<b[remain][i]<<endl;
                while(ans[i]<=n&&a[i][ans[i]].v<=v[i]) {
                    s.change(a[i][ans[i]].id,1,1,n,1);
                    ans[i]++;
                }
            }
        }
        pi(res);
        for(int i=1;i<=k;++i)pi(v[i]," \n"[i==k]);
    }
    return 0;
}