#pragma optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#include "local_debug.h"
#else
#define debug(...)
#endif
#define pb push_back
#define rep(i,a,n) for(int i=(a);i<(n);++i)
#define per(i,a,n) for(int i=(n)-1;i>=(a);--i)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
const ll mod = 998244353;
ll pow_mod(ll a, ll b, ll mod = ::mod) {
    assert(b >= 0); ll res = 1;
    for (a %= mod; b; b >>= 1, a = a * a % mod) if (b & 1) res = res * a % mod;
    return res;
}
 
string s;
vector<int> cnt[26];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while (T--)
    {
        rep(i,0,26)cnt[i].clear();
        int n;
        cin>>n;
        string ans;
        ans.clear();
        rep(nn, 0, n)
        {
            cin>>s;
            int f = 1,x=-1;
            rep(i,0,SZ(s))
            {
                int c=s[i]-'a';
                if(cnt[c].empty())
                {
                    f=0;
                    ans.pb(s[i]);
                    cnt[c].push_back(SZ(ans)-1);
                    continue;
                }
                if(f)
                {
                    auto it = upper_bound(all(cnt[c]), x);
                    if (it==cnt[c].end()){
                        f=0;
                        ans.pb(s[i]);
                        cnt[c].push_back(SZ(ans)-1);
                    }else
                        x=*it;
                } else {
                    ans.pb(s[i]);
                    cnt[c].push_back(SZ(ans)-1);
                }
            }
            //puts("");
        }
        cout<<ans<<'\n';
    }
    return 0;
}
