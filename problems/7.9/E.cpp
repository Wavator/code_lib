#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
inline ostream& operator << (ostream&os, const pair<A, B> &v) {
    return os << v.first << ' ' << v.second;
}
template <typename T>
inline ostream& operator << (ostream&os, const vector<T> &v) {
    auto it = v.begin(); os << *it; for (++it; it != v.end(); ++it) os << ' ' << *it;
    return os;
}
#ifdef Wavator
#define debug(...) cerr << #__VA_ARGS__ << " = [ ", _debug(__VA_ARGS__), cerr << "]" << endl;
#else
#define debug(...) 98;
#define cerr if (false) cout
#endif
void _debug(){}
template <typename H, typename...T>
void _debug(H head, T...tail) {
    cerr << head << " ";
    _debug(tail...);
}
#define rep(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, pii> pip;
const int N = 50;
bool dp[N][N];

map<string, int> mp;
string remap[N];
bool vis[N];
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int n, m;
    int cs = 1;
    while ((cin >> n >> m)) {
        if (n == 0 && m == 0)
            return 0;
        if (cs != 1)
            cout << '\n';
        cout << "Calling circles for data set "<< cs << ":\n";
        cs++;
        memset(dp,false,sizeof(dp));
        memset(remap,0,sizeof(remap));
        mp.clear();
        int pid = 0;
        rep(i,0,m) {
            string a, b;
            cin >> a >> b;
            if (!mp.count(a)) {
                mp[a] = (++pid);
                remap[pid] = a;
            }
            if (!mp.count(b)) {
                mp[b] = (++pid);
                remap[pid] = b;
            }
            dp[mp[a]][mp[b]] = true;
        }
        //debug(vector<string>(remap,remap+1+n))
        //debug(remap[n]);
        rep(k,1,n+1)rep(i,1,n+1)rep(j,1,n+1) dp[i][j]|=(dp[i][k]&&dp[k][j]);
        memset(vis,false,sizeof(vis));
        rep(i,1,n+1){
            if(vis[i])
                continue;
            //vis[i] = true;
            cout << remap[i];
            //int head = i;
            rep(j,i+1,n+1){
                if(!vis[j] && dp[i][j] && dp[j][i]) {
                    //debug(remap[head], remap[j])
                    vis[j] = true;
                    //head = j;
                    cout << ", " << remap[j];
                }
            }
            cout << '\n';
        }
        //puts("");
    }
    return 0;
}
