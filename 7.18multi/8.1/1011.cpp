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
const ll mod = (ll)1e9 + 7;
ll pow_mod(ll a, ll b) {
    assert(b >= 0);ll res=1;
    for (a %= mod; b; b >>= 1, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}
const int N = 1200;

char s[N];
inline bool ast(const char & c){
    return c == '+' || c == '*';
}
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int T;
    scanf("%d",&T);
    while (T--) {
        memset(s, 0, sizeof(s));
        scanf("%s",s);
        int m = strlen(s);
        bool ok = true;
        if (ast(s[0])) {
            puts("IMPOSSIBLE");
            continue;
        }
        for (int i=1;i < m;i++) {
            if (ast(s[i]) && ast(s[i - 1])) {
                ok=false; break;
            }
        }
        if (s[m-1]=='+'||s[m-1]=='*') ok=false;
        if (!ok) {
            puts("IMPOSSIBLE");
            continue;
        }
        int curr=-1;
        for (int i=0;i < m;i++) {
            if (s[i]<='9'&&s[i]>='0') {
                if (curr==-1)
                    curr=(s[i]!='0');
                else if (curr==0) {
                    ok=false; break;
                }
            }
            else {
                if (ast(s[i])) curr=-1;
                else {
                    if (curr==0) curr=-1;
                    else curr=1;
                }
            }
        }
        if (!ok) {
            puts("IMPOSSIBLE");
            continue;
        }
        curr=-1;
        for (int i=0;i < m;i++) {
            if (s[i]<='9'&&s[i]>='0') {
                if (curr==-1)
                    curr=(s[i]!='0');

            }
            else {
                if (s[i]=='?') {

                    if (curr) {
                        s[i]='1'; curr=1;
                    }
                    else {
                        if (ast(s[i + 1])||s[i+1]=='\0') {
                            ok=false; break;
                        }
                        else {
                            s[i]='+'; curr=-1;
                        }
                    }
                }
                else curr=-1;
            }
        }
        printf("%s\n", ok?s: "IMPOSSIBLE");
    }
    return 0;
}