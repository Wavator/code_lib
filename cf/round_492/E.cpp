#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#define debug(...) fprintf(stderr, __VA_ARGS__);
#else
#define debug(...) 42;
#define cerr if (false) cout
#endif
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b - 1); i >= a; --i)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define fi first
#define se second
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
int mod;
inline int pow_mod(int a, int b) {
    assert(b >= 0);
    int res = 1;
    for (a %= mod; b; b >>= 1, a = 1ll * a * a % mod) {
        if (b & 1) {
            res = 1ll * res * a % mod;
        }
    }
    return res;
}

inline int add(int u) {
    u++;
    if (u >= mod)
        return u - mod;
    return u;
}

inline int sub(int u) {
    u--;
    if (u < 0)
        return u + mod;
    return u;
}

inline int power(int u) {
    return pow_mod(u, mod - 2);
}

int u, v;

map<pii,pii> worked;

void print(int x){
    vi res;
    pii now;
    now = mp(x, 0);
    while (now.fi != v){
        int u = worked[now].fi;
        if (add(u) % mod == now.fi)
            res.pb(1);
        else if (sub(u) % mod == now.fi)
            res.pb(2);
        else
            res.pb(3);
        now = worked[now];
    }
    reverse(all(res));
    vi rev;
    now = mp(x, 1);
    while (now.fi != u){
        int nxt = worked[now].fi;
        if (add(now.fi) % mod == nxt)
            rev.pb(1);
        else if (sub(now.fi) % mod == nxt)
            rev.pb(2);
        else
            rev.pb(3);
        now = worked[now];
    }
    res.insert(res.end(), all(rev));
    printf("%d\n", SZ(res));
    for (auto &it : res)
        printf("%d ", it);
    puts("");
    exit(0);
}
void bfs() {
    worked.clear();
    queue<pii> q;
    q.push(mp(v, 0));
    worked[mp(v, 0)] = mp(v, 0);
    q.push(mp(u, 1));
    worked[mp(u, 1)] = mp(u, 1);
    while (!q.empty()){
        auto it = q.front();
        q.pop();
        int w = add(it.fi);
        if (!worked.count(mp(w, it.se))){
            worked[mp(w, it.se)] = it;
            if (worked.count(mp(w, it.se ^ 1))){
                print(w);
            }
            q.push(mp(w, it.se));
        }
        w = sub(it.fi);
        if (!worked.count(mp(w, it.se))){
            worked[mp(w, it.se)] = it;
            if (worked.count(mp(w, it.se ^ 1))){
                print(w);
            }
            q.push(mp(w, it.se));
        }
        w = power(it.fi);
        if (!worked.count(mp(w, it.se))){
            worked[mp(w, it.se)] = it;
            if (worked.count(mp(w, it.se ^ 1))){
                print(w);
            }
            q.push(mp(w, it.se));
        }
    }
}

int main() {
#ifdef Wavator
    u = 1, v = 3, mod = 5;
#else
    cin >> u >> v >> mod;
#endif
    if (u == v)
        return !printf("0\n");
    swap(u, v);
    bfs();
    return -1; // RE if no solution
}