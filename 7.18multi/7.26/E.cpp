#pragma optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
template <typename T> using V = vector<T>;
template <typename T> using pqmax = priority_queue<T>;
template <typename T> using pqmin = priority_queue<T, V<T>, greater<T> >;
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define SZ(x) ((int)(x).size())
#define pb push_back
#define gc getchar
template <typename T> inline bool read(T& x) {
    static int ch;
    static int f;
    for (f = 1, ch = gc(); !isdigit(ch); ch = gc()) {
        if (ch == -1) return false;
        if (ch == 45) f = -1;
    }
    for (x = ch - 48; ;x = x * 10 + ch - 48)
        if (!isdigit(ch = gc())) break;
    x *= f;
}
typedef unsigned long long ll;
typedef unsigned long long ull;
typedef double db;
const ll mod = (ll)1e9+7;
ll pow_mod(ll a, ll b = mod - 2) {
    assert(b >= 0); ll res = 1; for (a %= mod; b; b >>= 1, a = a * a % mod) if (b & 1) res = res * a % mod;
    return res;
}
class print_writer {
public:
    template<class T>
    inline void p(T x) {
        static int a[30], cnt;
        if (x==0)pc(48);
        else {
            if(x<0)pc(45),x=-x;
            for(cnt=0;x;x/=10)a[++cnt]=x%10+48;
            for(;cnt;) pc(a[cnt--]);
        }
    }
    template <typename T>inline void p(T*b, const T*e){ if(e-b>0)for (p(*b++);b!=e;b++)p(' '),p(*b);}
    inline void p(const char * s){static int i;for (i=0;s[i];++i)pc(s[i]);}
    inline void p(char c){pc(c);}
    inline void p(const string &s){for (const auto&c:s)pc(c);}
    template <typename T> inline void pl(const T&x){p(x),pc(10);}
    template <typename T> inline void ps(const T &x){p(x), pc(' ');}
    inline void flush(){fwrite(_, 1, O, stdout), oh = _;fflush(stdout);}
    inline void pc(char c){if (oh == _ + O)fwrite(_, 1, O, stdout), oh = _;*oh++ = c;}
    ~print_writer(){fwrite(_, 1, oh - _, stdout);}
    static const int O = 1<<20;
    char _[O], *oh = _;
}o;
 
const int N = 2000005;
char s[N], t[N];
unordered_map<ll, int> idx;
vector<vector<int> > ans;
int id[N];
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    cin >> s;
    int n = strlen(s);
    ll pw = 1;
    for (int i = 1; i < n; i ++)
        pw *= 131;
    strcpy(t, s);
    strcat(s, t);
    ll val = 0;
    for (int i = 0, l = 0, r = 0; i < n; i ++) {
        while (l < i) val -= pw * s[l++];
        while (r < i + n) val = val * 131 + s[r++];
        if (!idx.count(val)) {
            idx[val] = ans.size();
            ans.push_back(vector<int>());
        }
        ans[idx[val]].push_back(i);
    }
    for (int i = 0; i < (int)ans.size(); i ++)
        id[ans[i][0]] = i + 1;
printf("%d\n", (int)ans.size());
    for (int i = 0; i < n; i ++) if (id[i])
    {
        printf("%d", (int)ans[id[i] - 1].size());
        for (auto j : ans[id[i] - 1])
            printf(" %d", j);
        printf("\n");
    }
 
    return 0;
}