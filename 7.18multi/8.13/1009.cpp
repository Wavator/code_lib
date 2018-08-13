#include <iostream>
#include <cstdio>
#pragma optimize("-O3")
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
    inline void ps(const std::string&s) {
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
const int N = 200005;
using namespace std;
using namespace std;
struct node{
    int ch[2],fa,rev,Size;
}tree[N];
int sta[N],n,m;
inline bool isroot(int x) {
    return tree[tree[x].fa].ch[0]!=x&&tree[tree[x].fa].ch[1]!=x;
}
inline void pushup(int x) {
    tree[x].Size=tree[tree[x].ch[0]].Size+tree[tree[x].ch[1]].Size+1;
}
inline void pushdown(int x) {
    if(tree[x].rev) {
        tree[tree[x].ch[0]].rev^=1;
        tree[tree[x].ch[1]].rev^=1;
        swap(tree[x].ch[0],tree[x].ch[1]);
        tree[x].rev=0;
    }
}
inline void rot(int x) {
    int y=tree[x].fa,z=tree[y].fa;
    bool l=(tree[y].ch[0]==x ? 0 :1 );
    bool r=l^1;
    if(isroot(y)==0){
        if(tree[z].ch[0]==y) tree[z].ch[0]=x;
        else tree[z].ch[1]=x;
    }
    tree[x].fa=z;tree[y].fa=x;
    tree[tree[x].ch[r]].fa=y;
    tree[y].ch[l]=tree[x].ch[r];
    tree[x].ch[r]=y;
    pushup(y);pushup(x);
}
inline void splay(int x) {
    int y,z;
    int top=0;sta[++top]=x;
    for(int i=x;isroot(i)==0;i=tree[i].fa) sta[++top]=tree[i].fa;
    for(int i=top;i>=1;i--) pushdown(sta[i]);
    while(isroot(x)==0) {
        y=tree[x].fa;z=tree[y].fa;
        if(isroot(y)==0) {
            if((tree[y].ch[0]==x)^(tree[z].ch[0]==y)) rot(x);
            else rot(y);
        }
        rot(x);
    }
}
inline void access(int x) {
    int y=0;
    while(x) {
        splay(x);
        tree[x].ch[1]=y;
        pushup(x);
        y=x;
        x=tree[x].fa;
    }
}
inline void make_root(int x) {
    access(x);
    splay(x);
    tree[x].rev^=1;
}
inline void link(int x,int y) {
    make_root(x);
    tree[x].fa=y;
}
inline void cut(int x,int y) {
    make_root(x);
    access(y);
    splay(y);
    tree[x].fa=tree[y].ch[0]=0;
}
inline int query(int x) {
    access(x);splay(x);
    return tree[tree[x].ch[0]].Size;
}
int dep[N];
int first[N],des[N*2],nxtt[N*2],tot;
int nowfa[N];
int st[N][20];
inline void addEdge(int x,int y){
    tot ++;
    des[tot] = y;
    nxtt[tot] = first[x];
    first[x] = tot;
}
void dfs(int u,int fa){
    st[u][0] = fa;
    for (int i=1;i<17 && st[u][i-1];i++){
        st[u][i] = st[st[u][i-1]][i-1];
    }
    dep[u] = dep[fa]+1;
    for (int t = first[u];t;t=nxtt[t]){
        int v = des[t];
        if (v == fa)continue;
        dfs(v,u);
    }
}
int calc_anc(int u,int dept){
    if (dep[u]<dept){
        return n+1;
    }
    for (int i=0;i<17 && u ;i++){
        if (dept&(1<<i)){
            u = st[u][i];
        }
    }
    if (u == 0){
        u = n+1;
    }
    return u;
}
void solve(){
    sc(n);
    for(int i=1;i<=n+1;i++) {
        tree[i].fa=tree[i].ch[0]=tree[i].ch[1]=0;
        tree[i].Size=1;
        first[i] = 0;
    }
    tot =0;
    dep[n+1] = 0;
    dep[0] = 0;
    for (int i=2;i<=n;i++){
        int fa;
        sc(fa);
        addEdge(fa,i);
        addEdge(i,fa);
    }
    dfs(1,0);
    for (int i=1;i<=n;i++){
        int k;
        sc(k);
        nowfa[i] = calc_anc(i,k);
        link(i,nowfa[i]);
    }

    tree[n+1].Size=1;
    sc(m);
    while(m--) {
        int op;
        sc(op);
        if(op==1) {
            int x;
            sc(x);
            make_root(n+1);
//            printf("%d\n",query(x));
            pi(query(x));
        }
        else {
            int x,val;
            sc(x);
            sc(val);
            cut(x,nowfa[x]);
            nowfa[x]=calc_anc(x,val);
            link(x,nowfa[x]);
        }
    }
}
int main()
{
    //freopen("test.in", "r", stdin);
    int Case;
    sc(Case);
    while (Case --){
        solve();
    }
    return 0;
}