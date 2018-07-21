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
template <typename T>
class KMP {
public:
    vector<int> get_next(const T &a) {
        int n = a.size();
        vector<int> nxt(n + 1, 0);
        nxt[0] = nxt[1] = 0;
        for(int i=1;i<n;i++)
        {
            int j=nxt[i];
            while(j && a[i]!=a[j])
                j=nxt[j];
            nxt[i+1] = (a[i]==a[j])?j+1:0;
        }
        return nxt;
    }
    int kmp_single(const T &a, const T &b) { // a is pattern
        int n = a.size();
        vector<int> nxt = get_next(a);
        int m = b.size();
        for(int i = 0,j = 0; i < m; ++i) {
            if(j < n && b[i] == a[j])
                j++;
            else {
                while(j){
                    j = nxt[j];
                    if(b[i] == a[j]) {
                        j++;
                        break;
                    }
                }
            }
            if(j == n)
                return i - n + 1; // in 0 base
        }
        return -1;
    }

    vector<int> kmp(const T &a, const T &b) { // a is pattern
        int n = a.size();
        vector<int> nxt = get_next(a);
        vector<int> p;
        int m = b.size();
        for(int i = 0,j = 0; i < m; ++i) {
            if(j < n && b[i] == a[j])
                j++;
            else {
                while(j){
                    j = nxt[j];
                    if(b[i] == a[j]) {
                        j++;
                        break;
                    }
                }
            }
            if(j == n)
                p.push_back(i - n + 1); // in 0 base
        }
        return p;
    }

    int kmp_times(const T &a, const T &b) {
        int n = a.size();
        vector<int> nxt = get_next(a);
        int match = 0;
        int m = b.size();
        for(int i = 0,j = 0; i < m; ++i) {
            if(j < n && b[i] == a[j])
                j++;
            else {
                while(j){
                    j = nxt[j];
                    if(b[i] == a[j]) {
                        j++;
                        break;
                    }
                }
            }
            if(j == n)
                match++;
        }
        return match;
    }

    int kmp_and_del(const T &a, const T &b) {
        int n = a.size();
        vector<int> nxt = get_next(a);
        int match = 0;
        int m = b.size();
        for(int i = 0,j = 0; i < m; ++i) {
            if(j < n && b[i] == a[j])
                j++;
            else {
                while(j){
                    j = nxt[j];
                    if(b[i] == a[j]) {
                        j++;
                        break;
                    }
                }
            }
            if(j == n) {
                match++;
                j=0;
            }
        }
        return match;
    }

};
KMP<string> s;
char ss[100010];
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%s", ss);
        int n = strlen(ss);
        vector<int> nxt = ::s.get_next(ss);
        int len = n - nxt[n];
        if(nxt[n] == 0)
            printf("%d\n", n);
        else if (n % len == 0)
            printf("0\n");
        else
            printf("%d\n", len - n % len);
    }
    return 0;
}