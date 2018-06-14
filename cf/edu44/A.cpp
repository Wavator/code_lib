#include <bits/stdc++.h>
#ifdef Wavator

#define Debug(...) fprintf(stderr, __VA_ARGS__);

#else

#define Debug(...) 98;

#define cerr if (false) cout

#endif

#define pb push_back

#define fi firse

#define se second

using namespace std;

template <typename T> inline bool read(T &x) {
    char c = getchar();
    bool f = false;
    for (x = 0; !isdigit(c); c = getchar()) {
        if (c == EOF)
            return false;
        if (c == '-') {
            f = true;
        }
    }
    for (; isdigit(c); c = getchar()) {
        x = x * 10 + c - '0';
    }
    if (f) {
        x = -x;
    }
    return true;
}

template <typename A, typename B> inline bool read(A &x, B&y) {
    return read(x) && read(y);
}

template <typename A, typename B, typename C> inline bool read(A &x, B &y, C &z) {
    return read(x) && read(y) && read(z);
}

template <typename A, typename B, typename C, typename D> inline bool read(A &a, B &b, C &c, D &d) {
    return read(a) && read(b) && read(c) && read(d);
}


int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int n;
    while (read(n)) {
        n /= 2;
        vector<int> in(static_cast<unsigned int>(n));
        for (auto &v: in)   read(v);
        sort(in.begin(), in.end());
        int pos = 1;
        int ans1 = 0, ans2 = 0;
        for (auto &v: in) {
            ans1+=abs(pos-v);
            pos+=2;
        }
        pos = 2;
        for (auto &v: in) {
            ans2 += abs(pos - v);
            pos+=2;
        }
        cout << min(ans1, ans2) << endl;
    }
    return 0;
}
