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
typedef long long ll;



const int N = 2e7 + 100;
int prime[N],phi[N];
bool is_prime[N];

int sieve(int n) {
    int p = 0;
    fill(is_prime + 2, is_prime + n + 1, true);
    for(int i = 2; i <= n; i++) {
        if(is_prime[i])
            prime[p++] = i;
        for(int j = 0; j < p; j++) {
            if(prime[j] * i > n)
                break;
            is_prime[prime[j] * i] = false;
            if(i % prime[j] == 0)
                break;
        }
    }
    return p;
}

void gen_phi(int n) {
    int p = 0;
    fill(phi, phi + n + 1, 0);
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i]) {
            p++;
            phi[i] = i - 1;
        }
        for (int j = 0; j < p; j++)
        {
            if (prime[j] * i > n)
                break;
            phi[i * prime[j]] = phi[i] * (i % prime[j]? prime[j] - 1: prime[j]);
            if (i % prime[j] == 0)
                break;
        }
    }
}
ll dp[N];
int main()
{
    sieve((int)2e7 + 5);
    gen_phi((int)2e7 + 5);
    for (int i = 1; i < N; i += 2) phi[i] >>= 1;
    for (int i = 1; i < N; i++) dp[i] = dp[i - 1] + phi[i];
    int T;
    for (scanf("%d", &T); T--; )
    {
        int n;
        scanf("%d", &n);
        printf("%lld\n", dp[n]);
    }
    return 0;
}