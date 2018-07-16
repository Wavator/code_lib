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
#define debug(...) cerr << #__VA_ARGS__ << "[", _debug(__VA_ARGS__)
#else
#define debug(...) 98
#define cerr if (false) cout
#endif

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

//map<size_t , int> mp, pm;
string ans[100001], sna[100001];

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string line, a;
    int c = 0;
    while (getline(cin, line) && line != "@END@") {
//        int i;
//        for (i = 1; line[i] != ']'; sna[c].push_back(line[i++]));
//        //mp.insert({hash<string>() (sna[c]), c});
//        while (line[i] == ' ' || line[i] == ']')i++;
//        for (; i < line.size(); ++i) ans[c].push_back(line[i]);
//        //pm.insert({hash<string>() (ans[c]), c});
//        //cerr << ans[c] << ' ' << sna[c] << endl;
//        c++;
        sna[c] = line.substr(0, line.find(']',0) + 1);
        ans[c++] = line.substr(line.find(']',0)+2);
    }
    int n;
    cin >> n >> ws;
    while (n--) {
        getline(cin, a);
        if (a[0] == '[') {
            //reverse(all(a));
            //if(a.back()=='[') a.pop_back();
            //reverse(all(a));
            //if(a.back()==']') a.pop_back();
            rep(i, 0, c) {
                if (sna[i] == a) {
                    cout << ans[i] << '\n';
                    goto tag;
                }
            }
            cout << "what?\n";
        } else {
            rep(i, 0, c) {
                if (ans[i] == a) {
                    cout << sna[i].substr(1, sna[i].size() - 2) << '\n';
                    goto tag;
                }
            }
            cout << "what?\n";
        }
        tag:{};
    }
    return 0;
}