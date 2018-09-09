#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
#include<bits/stdc++.h>
const int N = 15000005;
const int M = N - 5;
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
bool is_prime[N + 10];
int cnt,miu[N + 10],prime[N + 10],p;
ll n,m,f[N + 10];
map<ll,ll> mp;
void genmiu(int n)
{
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    memset(miu,0,sizeof(miu));
    miu[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) {prime[p++]=i; miu[i]=-1;}
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            miu[i*prime[j]]=i%prime[j]?-miu[i]:0;
            if(i%prime[j]==0) break;
        }
    }
    for(int i=1;i<=n;i++) f[i]=f[i-1]+miu[i];
}
ll calc(ll x)
{
    if(x<=M) return f[x];
    if(mp.find(x)!=mp.end()) return mp[x];
    ll ans=1;
    for(ll i=2,r;i<=x;i=r+1)
    {
        r=x/(x/i);
        ans-=calc(x/i)*(r-i+1);
    }
    return mp[x]=ans;
}
typedef pair<ll,ll> PLL;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;


typedef pair<ll,ll> pp;
//map<pp,ll> sv;

vector<ll> fact__;
ll solve(ll n, ll m) {
    //cerr << n << ' ' << m << endl;
    // if (sv.count(pp(n, m))) {
    //     return sv[pp(n, m)];
    // }
    if (n == 1)return calc(m);
    if (m == 0)return 0;
    //Factor::_factor(n);
    vector<ll> fact;
    for(auto&v: (::fact__)) {
        if (n % v == 0) {
            fact.pb(v);
        }
    }
    int sz = SZ(fact);
    ll res = ((sz & 1) ? 1 : -1), ans = 0;
    int up = (1 << sz);
    for (int i = 0; i < up; ++i) {
        ll c = 0;
        ll s = 1;
        for (ll j = 0; j < fact.size(); ++j) {
            if ((i >> j) & 1) {
                ++c;
                s *= fact[j];
            }
        }
        ans += res * ((c & 1) ? 1 : -1) * solve(s, m / s);
    }
    return ans;
}

void fact_(ll n) {
    for(int i=0;i<p&&prime[i]*prime[i]<=n;++i){
        ll c=0;
        if(n==1)break;
        if(n<=M&&is_prime[n]){
            fact__.pb(n);
            return;
        }
        while (n%prime[i]==0){
            n/=prime[i];
            ++c;
        }
        if(c){
            fact__.pb(prime[i]);
        }
        if(c>1){
            puts("0");
            exit(0);
        }
    }
    if(n)fact__.pb(n);
}

void ensure(ll n) {
    vector<ll> real;
    for(auto&v: fact__) if (n % v == 0) real.push_back(v);
    fact__ = real;
}

int main()
{
    genmiu(M);
    //cerr<<p<<endl;
    ll m, n;
    scanf("%lld%lld",&m,&n);
    fact_(n);
    //for(ll&v:fact)cerr<<v<<endl;
    //ensure(n);
    cout << solve(n, m);
    return 0;
}
