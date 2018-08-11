#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC target("avx,sse3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
template<class T>inline void print(T x){if(x/10!=0)print(x/10);putchar(x%10+'0');}
template<class T>inline void writeln(T x){if(x<0)putchar('-');x=abs(x);print(x);putchar('\n');}
template<class T>inline void write(T x){if(x<0)putchar('-');x=abs(x);print(x);}
/*================Header Template==============*/
#define int long long
const int base=48271,maxn=400005;
int rt,seed=233,cnt;
inline int Rand() {
    return seed=(int)(1ll*seed*base%INT_MAX);
}
struct node {
    int ls,rs,val,sz,tag,id,fix;
    node(int _ls=0,int _rs=0,int _val=0,int _sz=0,int _tag=0,int _id=0):ls(_ls),rs(_rs),val(_val),sz(_sz),tag(_tag),id(_id){fix=Rand();}
}tr[maxn];
inline void update(int o) {
    tr[o].sz=tr[tr[o].ls].sz+tr[tr[o].rs].sz+1;
}
inline void Pushdown(int o) {
    if(tr[o].tag) {
        tr[o].val+=tr[o].tag;
        if(tr[o].ls)
            tr[tr[o].ls].tag+=tr[o].tag;
        if(tr[o].rs)
            tr[tr[o].rs].tag+=tr[o].tag;
        tr[o].tag=0;
    }
}
inline int Merge(int a,int b) {
    if(!a||!b)
        return a|b;
    Pushdown(a),Pushdown(b);
    if(tr[a].fix<tr[b].fix) {
        tr[a].rs=Merge(tr[a].rs,b);
        update(a);
        return a;
    }
    else {
        tr[b].ls=Merge(a,tr[b].ls);
        update(b);
        return b;
    }
}
inline pair<int,int> Split(int o,int k) {
    if(!o)
        return make_pair(0,0);
    Pushdown(o);
    if(tr[tr[o].ls].sz==k) {
        int pre=tr[o].ls;
        tr[o].ls=0;
        update(o);
        return make_pair(pre,o);
    }
    if(tr[tr[o].ls].sz+1==k) {
        int pre=tr[o].rs;
        tr[o].rs=0;
        update(o);
        return make_pair(o,pre);
    }
    if(tr[tr[o].ls].sz>k) {
        pair<int,int> tmp=Split(tr[o].ls,k);
        tr[o].ls=tmp.second;
        update(o);
        return make_pair(tmp.first,o);
    }
    pair<int,int> tmp=Split(tr[o].rs,k-tr[tr[o].ls].sz-1);
    tr[o].rs=tmp.first;
    update(o);
    return make_pair(o,tmp.second);
}
inline int Rank(int o,int k) {
    int res=0,t=1e9;
    while(o) {
        Pushdown(o);
        if(tr[o].val==k)
            t=min(t,res+tr[tr[o].ls].sz+1);
        if(tr[o].val<k)
            res+=tr[tr[o].ls].sz+1,o=tr[o].rs;
        else
            o=tr[o].ls;
    }
    return t==1e9?res:t-1;
}
inline void Insert(int o,int num,int id) {
    int rnk=Rank(o,num);
    pair<int,int>tmp=Split(o,rnk);
    tr[++cnt]=node(0,0,num,1,0,id);
    rt=Merge(tmp.first,cnt);
    rt=Merge(rt,tmp.second);
}
inline void Sub1(int o,int num,int d) {
    int rnk=Rank(o,num+1);
    pair<int,int>tmp=Split(o,rnk);
    tr[tmp.first].tag-=d;
    rt=Merge(tmp.first,tmp.second);
}
inline void Add1(int o,int num,int d) {
    int rnk=Rank(o,num);
    pair<int,int>tmp=Split(o,rnk);
    tr[tmp.second].tag+=d;
    rt=Merge(tmp.first,tmp.second);
}
inline void Solve1(int o,int d) {
    if(!o)
        return;
    Pushdown(o);
    Insert(rt,tr[o].val-d,tr[o].id);
    Solve1(tr[o].ls,d);
    Solve1(tr[o].rs,d);
//	Recycle(o);
}
inline void Sub2(int o,int num,int d) {
    int rnk=Rank(o,num+1);
    pair<int,int>tmp=Split(o,rnk);
    rt=tmp.second;
    Solve1(tmp.first,d);
}
inline void Solve2(int o,int d) {
    if(!o)
        return;
    Pushdown(o);
    Insert(rt,tr[o].val+d,tr[o].id);
    Solve2(tr[o].ls,d);
    Solve2(tr[o].rs,d);
//	Recycle(o);
}
inline void Add2(int o,int num,int d) {
    int rnk=Rank(o,num);
    pair<int,int>tmp=Split(o,rnk);
    rt=tmp.first;
    Solve2(tmp.second,d);
}
int n,q,T,num[maxn];
inline void Dfs(int o) {
    if(!o)
        return;
    Pushdown(o);
    num[tr[o].id]=tr[o].val;
    Dfs(tr[o].ls);
    Dfs(tr[o].rs);
}
inline void Print(int o) {
    if(!o)
        return ;
    Print(tr[o].ls);
    cout<<tr[o].id<<" "<<tr[o].val<<" "<<tr[o].tag<<endl;
    Print(tr[o].rs);
}
signed main() {
    read(T);
    while(T--) {
        rt=cnt=0;
        read(n),read(q);
        for(int i=1,x;i<=n;++i)
            read(x),Insert(rt,x,i);
        while(q--) {
            int op,x,y;
            read(op),read(x),read(y);
            if(op==1)
                if(y>0)
                    Sub1(rt,x,y);
                else
                    Sub2(rt,x,y);
            else
            if(y>0)
                Add1(rt,x,y);
            else
                Add2(rt,x,y);
//			cerr<<"Once Opera:"<<endl;
//			Print(rt);
        }
        Dfs(rt);
        for(int i=1;i<=n;++i)
            printf("%lld ",num[i]);
        puts("");
        for(int i=1;i<=cnt;++i)
            tr[i]=node();
    }
}