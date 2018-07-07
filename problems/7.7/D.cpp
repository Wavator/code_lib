#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
typedef long long ll;
#define int long long
ll sum[N], num[N];
int p[N];
bool is[N];
const ll mod = 998244353;
signed main() {
    int tot=0;
    memset(is,true,sizeof is);
    is[0]=is[1]=false;
    for(int i=2;i<N;++i) {
        if (is[i]) {
            p[tot++]=i;
            for (int j =2*i;j<N;j+=i) {
                is[j]=false;
            }
        }
    }
    //cerr << tot << endl;
    int T;
    for (scanf("%lld",&T); T--; ) {
        ll l, r, k;
        scanf("%lld%lld%lld", &l, &r, &k);
        for(int i = 0; i <= r - l; i++){
            sum[i] = 1;
            num[i] = i + l;
        }
        for(int i = 0; i < tot; i++){
            ll a = (l + p[i] - 1) / p[i] * p[i];
            for(ll j = a; j <= r; j += p[i]) {
                ll cnt = 0;
                while(num[j - l] % p[i] == 0) {
                    cnt++;
                    num[j - l] /= p[i];
                }
                sum[j - l] = sum[j - l] * (cnt * k + 1 % mod);
                if(sum[j - l] >= mod) sum[j - l] %= mod;
            }
        }
        ll sol = 0;
        for(int i = 0; i <= r - l; i++){
            if(num[i] != 1) sum[i] = sum[i] * (k + 1);
            sol += sum[i];
            if(sol >= mod) sol %= mod;
        }
        printf("%lld\n", sol);
    }
    return 0;
}