#pragma optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i,a,n) for(int i=(a);i<(n);++i)
#define per(i,a,n) for(int i=(n)-1;i>=(a);--i)
#define all(x) (x).begin(), (x).end()
#ifdef Wavator
#define dbg(...) fprintf(stderr, __VA_ARGS__), fprintf(stderr, "\n"), fflush(stderr)
#else
#define dbg(...) 99
#endif
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int mod = (int)1e9+7;
ll pow_mod(ll a,ll b=mod-2){
    assert(b>=0);ll res=1;for(a%=mod;b;b>>=1,a=a*a%mod)if(b&1)res=res*a%mod;
    return res;
}
inline int idx(char a) {
    return a>'9'?a-'A'+10:a-'0';
}
const int N = 100005;

int power[17];
const int base = 1021;
struct node {
    int a[16];
    node(){
        memset(a,0,64);
    }
    node(int x){
        *this = node();
        a[x] = 1;
    }
    inline int operator()()const{
        int x=0;
        rep(i,0,16){
            (x+=static_cast<int>((ll)a[i]*power[i]%mod))%=mod;
        }
        return x;
    }
    inline int& operator [](const int &x) {
        return a[x];
    }
    friend node operator + (node l, node r) {
        node ret;
        rep(i,0,16)
            ret[i]=(l[i]+r[i])%mod;
        rep(i,0,16){
            rep(j,0,16){
                int k=(i+j)%15;
                if(k==0&&(i+j))k=15;
                ret[k]= static_cast<int>((ret[k]+1ll*l[i]*r[j])%mod);
            }
        }
        return ret;
    }
};
char S[N];
node s[N<<2];

inline void push_up(int x) {
    s[x]=s[x<<1]+s[x<<1|1];
}
void build(int l, int r, int rt) {
    if(l==r){
        s[rt]=node(idx(S[l]));
        return;
    }
    int mid=l+r>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    push_up(rt);
}

void change(const char &val, const int &pos, int l, int r, int rt) {
    if (l==r){
        s[rt]=node(idx(val));
        return;
    }
    int mid=l+r>>1;
    if(pos<=mid)change(val,pos,l,mid,rt<<1);
    else change(val,pos,mid+1,r,rt<<1|1);
    push_up(rt);
}

node query(const int &L, const int &R, int l, int r, int rt) {
    if(l >= L && r <= R)return s[rt];
    int mid = l + r >> 1;
    if(L > mid)return query(L, R, mid + 1, r, rt << 1 | 1);
    if(R <= mid) return query(L, R, l, mid, rt << 1);
    return query(L, R, l, mid, rt << 1) + query(L, R, mid + 1, r, rt << 1 | 1);
}


int main() {
#ifdef Wavator
    freopen("test.in","r",stdin);
#endif
    power[0]=1;
    rep(i,1,17)power[i]=static_cast<int>((ll)power[i-1]*base%mod);
    int n,q;
    scanf("%d%d%s",&n,&q,&S[1]);
    build(1,n,1);
    static char ch[5];
    for(int tp,l,r;q--;){
        scanf("%d", &tp);
        if (tp==1){
            scanf("%d%s",&l,ch);
            change(ch[0],l,1,n,1);
        } else{
            scanf("%d%d",&l,&r);
            printf("%d\n",query(l,r,1,n,1)());
        }
    }
    return 0;
}