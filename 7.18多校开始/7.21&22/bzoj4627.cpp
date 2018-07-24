/**************************************************************
????Problem: 4627
????User: Wavator
????Language: C++
????Result: Accepted
????Time:1800 ms
????Memory:58716 kb
****************************************************************/
?
#pragma GCC optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#define debug(...) fprintf(stderr, __VA_ARGS__), fprintf(stderr, "\n"), fflush(stderr)
#else
#define debug(...) 99
#endif
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;typedef unsigned long long ull;typedef double db;
//template <typename T> using pqmin = priority_queue<T, vector<T>, greater<T> >;template <typename T> using pqmax = priority_queue<T>;
//template <typename T> using V = vector<T>;typedef V<int> vi;typedef pair<int,int> pii;
inline char gc() { static char buf[1<<20],*h=buf,*t=buf;return (h==t&&(t=(h=buf)+fread(buf,1,1<<20,stdin),h==t)?-1:*h++);}
template <typename T> inline bool read(T &x){static int f;static char c;for(c=gc(),f=1;!isdigit(c);c=gc()){if(c==-1)return false;else if(c==45)f=-1;}for(x=c-48;isdigit(c=gc());x=x*10+c-48);return x*=f,true; }
template <typename A, typename B> inline bool read(A&x, B&y) {return read(x) && read(y);}
template <typename A, typename B, typename C> inline bool read(A&x,B&y,C&z){return read(x)&&read(y)&&read(z);}
/*
?*
?*/
template <typename T>
struct seg_tree_val {
????static const int N = 100005, LOG = 21;
????int ls[N*LOG], rs[N*LOG], tot;
????int root;
????T l[N*LOG], r[N*LOG];
????int sum[N*LOG];
????void change(int &rt, T L, T R, const T &pos) {
????????if (!rt) {
????????????rt = ++tot;
????????????l[rt]=L;r[rt]=R;
????????}
????????sum[rt]++;
????????if(L==R)return;
????????T mid = L + R >> 1;
????????if(pos<=mid)change(ls[rt],L,mid,pos);
????????else change(rs[rt],mid+1,R,pos);
????}
?
????int ask(int x,T L,T R) {
????????if(!x) return 0;
????????if(r[x] < L || l[x] > R) return 0;
????????if(L<=l[x] && r[x]<=R) return sum[x];
????????return ask(ls[x],L,R)+ask(rs[x],L,R);
????}
};
?
seg_tree_val<ll> tree;
const ll inf = 1ll<<55ll;
int main() {
#ifdef Wavator
????freopen("test.in", "r", stdin);
#endif
????ll s = 0, res = 0;
????ll n, L, R;
????scanf("%lld%lld%lld",&n,&L,&R);
????for(int i=1,x;i<=n;i++) {
????????scanf("%d",&x);
????????tree.change(tree.root,-inf,inf,s);
????????s+=x;
????????res+=tree.ask(tree.root,max(-inf,s-R),min(inf,s-L));
????}
????printf("%lld\n",res);
????return 0;
}