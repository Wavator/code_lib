#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B> inline ostream& operator << (ostream&os, const pair<A, B> &v) {
    return os << v.first << ' ' << v.second;
}
template <typename T> inline ostream& operator << (ostream&os, const vector<T> &v) {
    for (auto it = v.begin(); it != v.end(); os << (*it++)) if (it != v.cbegin()) os << ' ';
    return os;
}
#ifdef Wavator
#define debug(...) cerr << #__VA_ARGS__ << " = \n[ ", _debug(__VA_ARGS__), cerr << "]" << endl
#else
#define debug(...) 98
#define cerr if (false) cout
#endif
void _debug(){}
template <typename H, typename...T>
void _debug(H head, T...tail) {
    cerr << head << " ";
    _debug(tail...);
}
#define rep(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define per(i, a, b) for (int (i) = (b) - 1; (i) >= (a); --(i))
#define REP(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int oo = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

class AC_automata {
public:
    static const int N = 151 * 70, sigma_sz = 26;
    int ch[N][sigma_sz], val[N], f[N], last[N], sz;

    unsigned ch_sz;

    AC_automata(){ch_sz = sizeof(ch[0]);}

    void init() {
        sz = 1;
        memset(ch[0], 0, ch_sz);
        val[0]=0;
    }

    void insert(char* s, int v) {
        int n = strlen(s), u = 0;
        rep(i, 0, n) {
            int c = s[i] - 'a';
            if(!ch[u][c]) {
                ch[u][c] = sz;
                memset(ch[sz], 0, ch_sz);
                val[sz++] = 0;
            }
            u = ch[u][c];
        }
        val[u]=v;
    }

    void get_fail() {
        queue<int> q;
        last[0] = f[0]=0;
        rep(i, 0, sigma_sz) {
            int u = ch[0][i];
            if(u) {
                f[u] = last[u] = 0;
                q.push(u);
            }
        }
        for(;!q.empty(); q.pop()) {
            int r = q.front();
            rep(i, 0, sigma_sz) {
                int u = ch[r][i];
                if(u==0)continue;
                q.push(u);
                int v = f[r];
                for(;v && ch[v][i]==0; v = f[v]);
                f[u] = ch[v][i];
                last[u] =  val[f[u]]?f[u]:last[f[u]];
            }
        }
    }

    virtual void print(int i) { // give the index of vertexes which have the same suffix with i
        if(i) {
            printf("%d\n",i);
            print(last[i]);
        }
    }

    void find(char * s) {
        int n=strlen(s),j=0;
        rep(i, 0, n) {
            int id = s[i]-'a';
            for(;j && ch[j][id]==0; j=f[j]);
            j = ch[j][id];
            if(val[j]) print(j);
            else if(last[j]) print(last[j]);
        }
    }


};

class my_ac: public AC_automata {
    int cnt[N];
    char p[151][75];
    void print(int i) {
        if (i) {
            cnt[val[i]]++;
            print(last[i]);
        }
    }

public:
    void work(int n) {
        int best = *max_element(cnt + 1, cnt + n + 1);
        printf("%d\n", best);
        REP(i, 1, n) if (cnt[i] == best) puts(p[i]);
    }
    void init(int n) {
        AC_automata::init();
        memset(cnt, 0, sizeof(cnt));
        REP(i, 1, n) {
            scanf("%s", p[i]);
            insert(p[i], i);
        }
    }
};

my_ac ac;

char t[1000002];

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int n;
    while (scanf("%d", &n) && n) {
        ac.init(n);
        ac.get_fail();
        scanf("%s", t);
        ac.find(t);
        ac.work(n);
    }
    return 0;
}