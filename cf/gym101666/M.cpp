#include<iostream>
#include<string.h>
#include<algorithm>
#include<cstdio>
#include<math.h>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<functional>
using namespace std;
typedef long long LL;
struct haha
{
	int x, y;
}a[100010];
int i, n, j, k, dp[100010], d[100010],l;
haha s, f;
bool cmp1(const haha aa, const haha bb) {
	if (aa.x == bb.x)return aa.y < bb.y;
	return aa.x < bb.x;
}
bool cmp2(const haha aa, const haha bb) {
	if (aa.x == bb.x)return aa.y < bb.y;
	return aa.x > bb.x;
}
int main() {
	scanf("%d", &n);
	scanf("%d%d%d%d", &s.x, &s.y, &f.x, &f.y);
	int tx, ty;
	for (i = 0; i < n; i++) {
		scanf("%d%d", &tx, &ty);
		if (tx<min(s.x, f.x) || tx>max(s.x, f.x) || ty<min(s.y, f.y) || ty>max(s.y, f.y)) {
			n--;
			i--;
			continue;
		}
		a[i].x = tx;
		a[i].y = ty;
	}
	if (!((s.x > f.x) ^ (s.y > f.y)))sort(a, a + n, cmp1);
	else sort(a, a + n, cmp2);
	memset(dp, 0, sizeof(dp));
	memset(d, 0, sizeof(d));
	l = 1;
	for (i = 0; i < n; i++) {
		int pos = upper_bound(d, d + l, a[i].y) - d;
		if (pos >= l)l++;
		d[pos] = a[i].y;
	}
	printf("%d\n", l - 1);
}
