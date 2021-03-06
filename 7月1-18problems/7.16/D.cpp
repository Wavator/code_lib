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
namespace Manacher {

    vector<int> a;

    int manacher(const string &s, int len) {
        a.resize((unsigned int)len);
        a[0]=0;
        int ans = 0, j;
        for(int i=0;i<len;) {
            while(i-a[i]>0&&s[i+a[i]+1]==s[i-a[i]-1])
                a[i]++;
            if(ans<a[i])
                ans=a[i];
            j = i+1;
            while(j<=i+a[i] && i-a[i]!=i+i-j-a[i+i-j]){
                a[j]=min(a[i+i-j],i+a[i]-j);
                j++;
            }
            a[j]=max(i+a[i]-j,0);
            i=j;
        }
        return ans;
    }

    int getMax(const char * s) {
        auto len = strlen(s);
        string str;
        str.resize(len<<1|1);
        for(int i=0;i<len;++i) {
            str[i<<1]='$';
            str[i<<1|1]=s[i];
        }
        str[len<<1]='$';
        return manacher(str,2*len+1);
    }

    int getMax(const string &s) {
        auto len = s.size();
        string str;
        str.resize(len<<1|1);
        for(int i=0;i<len;++i){
            str[i<<1]='$';
            str[i<<1|1]=s[i];
        }
        str[len<<1]='$';
        return manacher(str,len<<1|1);
    }

    vector<int> getMatch(const char * s) {
        getMax(s);
        return a;
    }

    vector<int> getMatch(const string &s) {
        getMax(s);
        return a;
    }

}
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    while (n--) {
        cin >> s;
        printf("%d\n", Manacher::getMax(s));
    }
    return 0;
}