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
    #define debug(fmt, ...) fprintf(stderr, "func[%s]: %s = " fmt "\n", \
                __func__, #__VA_ARGS__, __VA_ARGS__), fflush(stderr)
    #define err(x) cerr << "func[" << __func__ << "]: " \
                    << #x << " = " << x << endl << flush
#else
    #define debug(...) 0
    #define err(x) 0
#endif
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 100005;
int ans[N], cnt[N], id[N];

const int mod = 1e9 + 7;

inline void my_add(int &a, int b){
    a += b; if(a >= mod) a -= mod;
}
inline void my_sub(int &a, int b){
    a -= b; if(a < 0) a += mod;
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    for(int i = 0; i < (1 << 12); i++) {
        id[i] = 0;
        for(int j = 0; j < 12; j++) if(i & (1 << j)) id[i]++;
        id[i] >>= 1;
    }
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        int  lb = n >> 1, sz = (1 << (n + 1));
        for(int i = 0; i < sz; i++) ans[i] = cnt[i] = 0;
        cnt[0] = 1;
        while(m--) {
            static char opt[100];
            int u, v; scanf("%s%d%d", opt, &u, &v); u--; v--;
            int cur = (1 << u) + (1 << v);
            if(opt[0] == '-') {
                for(int i = 0; i < sz; i++) if((i & cur) == 0) {
                        my_sub(cnt[i | cur], cnt[i]);
                        my_sub(ans[id[i | cur]], cnt[i]);
                    }

            } else {
                for(int i = 0; i < sz; i++) if((i & cur) == 0) {
                        my_add(cnt[i | cur], cnt[i]);
                        my_add(ans[id[i | cur]], cnt[i]);
                    }
            }
            for(int i = 1; i <= lb; i++) printf("%d%c", ans[i], i == lb ? '\n' : ' ');
        }

    }
    return 0;
}