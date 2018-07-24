#include <bits/stdc++.h>

#define debug(...) fprintf(stderr,__VA_ARGS__)
#define pb push_back
#define fi first
#define se second

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair <int, int> pi;

namespace io {
	const int L = 1 << 20 | 1;
	char ibuf[L], *iS, *iT, c, obuf[L], *oS = obuf, *oT = obuf + L - 1, qu[55]; int f, qr;
#ifdef whzzt
	#define gc() getchar()
#else
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, L, stdin), iS == iT ? EOF : *iS ++) : *iS ++)
#endif
	template <class I>
	inline void gi (I &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
	}
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
	}
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush (), oS = obuf;
	}
	template <class I>
	void print (I x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0', x /= 10;
		while (qr) putc (qu[qr --]);
	}
	struct io_ff { ~io_ff() { flush(); } } _io_ff_;
}
using io :: gi;
using io :: putc;
using io :: print;

template <class T> bool chkmin (T &a, T b) { return a > b ? a = b, true : false; }
template <class T> bool chkmax (T &a, T b) { return a < b ? a = b, true : false; }

const int N = 400005;

int n, w[N];
ll f[N][4], g[N][4];
vector <int> e[N];

void dfs (int u, int fa = 0) {
	ll a[4][3] = {0}, b[4][3] = {0}, c[4][3] = {0};
	int x, y, p, q;
	for (int v : e[u]) if (v != fa) {
		dfs(v, u);
		memset (b, 0, sizeof(b));
		for (x = 0; x <= 3; x ++) b[x][0] = f[v][x], b[x][1] = g[v][x];
		memset (c, 0, sizeof(c));
		for (x = 0; x <= 3; x ++) for (y = 0; x + y <= 3; y ++)
			for (p = 0; p <= 2; p ++) for (q = 0; p + q <= 2; q ++)
				chkmax(c[x + y][p + q], a[x][p] + b[y][q]);
		memcpy (a, c, sizeof(c));
	}
	for (x = 0; x <= 3; x ++) chkmax(f[u][x], a[x][0]);
	for (x = 1; x <= 3; x ++) for (y = 0; y <= 2; y ++) chkmax(f[u][x], a[x - 1][y] + w[u]);
	for (x = 0; x <= 3; x ++) for (y = 0; y <= 1; y ++) chkmax(g[u][x], a[x][y] + w[u]);
}

int main () {
	int i, u, v;
	gi(n);
	for (i = 1; i <= n; i ++) gi(w[i]);
	for (i = 1; i < n; i ++) gi(u), gi(v), e[u].pb(v), e[v].pb(u);
	dfs(1);
	printf ("%lld\n", f[1][3]);
	return 0;
}
