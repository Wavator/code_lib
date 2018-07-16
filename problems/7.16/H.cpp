#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#define debug(...) fprintf(stderr, __VA_ARGS__), fprintf(stderr, "\n")
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
const ull hash_base = 19260817;
const int N = 30005, M = 250;
template <typename T>
class KMP
{
public:
    vector<int> get_next(const T &a) {
        int n = a.size();
        vector<int> nxt(n + 1, 0);
        for(int i = 1; i < n; ++i) {
            for (int j = i; j; ){
                j = nxt[j];
                if(a[j] == a[i]) {
                    nxt[i + 1] = j + 1;
                    break;
                }
            }
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
KMP<vi> kmp;
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    if (m == 1) return !printf("%d\n", n);
    vi a(n, 0), b(m, 0), c(n, 0), d(m, 0);
    rep(i, 0, n) scanf("%d", &a[i]);
    rep(i, 0, m) scanf("%d", &b[i]);
    rep(i, 0, n - 1) a[i] = a[i + 1] - a[i];
    a[n - 1] = oo;
    rep(i, 0, m - 1) b[i] = b[i + 1] - b[i];
    b.pop_back();
    cout << kmp.kmp_times(b, a) << '\n';
    return 0;
}s