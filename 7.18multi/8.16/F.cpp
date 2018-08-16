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


int ch[1<<18][26], fail[1<<18], val[1<<18];
int sz, rt;
int newnode() {
    memset(ch[sz], -1, sizeof(ch[sz])), val[sz] = 0;
    return sz++;
}
void init() { sz = 0, rt = newnode(); }
#define idx(x) ((x)-'a')
void insert(const char* s, int id) {
    int u = 0, n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        int c = idx(s[i]);
        if (ch[u][c] == -1) ch[u][c] = newnode();
        u = ch[u][c];
    }
    val[u] |= 1 << id;
}
void get_fail() {
    queue<int> q;
    fail[rt] = rt;
    for (int c = 0; c < 26; c++) {
        if (~ch[rt][c])
            fail[ch[rt][c]] = rt, q.push(ch[rt][c]);
        else
            ch[rt][c] = rt;
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        val[u] |= val[fail[u]];
        for (int c = 0; c < 26; c++)
        {
            if (~ch[u][c])
                fail[ch[u][c]] = ch[fail[u]][c], q.push(ch[u][c]);
            else
                ch[u][c] = ch[fail[u]][c];
        }
    }
}
int d[1<<18];
vector<int> G[1<<18];
void solve(const char* op) {
    rep(u,0,sz)
        rep(c,0,26)
            if (~ch[u][c])
                G[ch[u][c]].push_back(u);
    memset(d, -1, sizeof(d));
    queue<int> q;
    rep(i,0,sz)
        if (val[i]) q.push(i), d[i] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto& v : G[u])
        {
            if (~d[v]) continue;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
    stack<int> s;
    int u = rt;
    s.push(u);
    printf("%d\n", d[u]);
    for (int i = 0; op[i]; i++)
    {
        if (op[i] == '-')
        {
            s.pop();
            if (!s.empty())
                u = s.top();
            else
                s.push(0);
            printf("%d\n", d[u]);
        }
        else {
            u = ch[u][op[i] - 'a'];
            s.push(u);
            printf("%d\n", d[u]);
        }
    }
}

string s;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    init();
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        insert(s.c_str(), i);
    }
    get_fail();
    cin >> s;
    solve(s.c_str());
    return 0;
}
