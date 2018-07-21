#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
 
using namespace std;
const int N = 205;

int n;
struct node {
    double l, r, y;
	int d;
} a[N];
bool inline cmp(const node& a, const node& b)
{
	return a.y < b.y;
}

int cnt[4 * N]; 
double sum[4 * N], x[N];

void update(int k, int l, int r, int L, int R, int v) 
{
    if(L <= l && r <= R) 
        cnt[k] += v;
    else 
    {
    	 int mid = (l + r) >> 1;
	    if(L <= mid) 
			update(k << 1, l, mid, L, R, v);
	    if(R > mid) 
			update(k << 1 | 1, mid + 1, r, L, R, v);
	}
    if(cnt[k]) 
		sum[k] = x[r + 1] - x[l];
    else if(l == r) 
		sum[k] = 0;
    else 
		sum[k] = sum[k << 1] + sum[k << 1 | 1];
}
 
int main() 
{
	int T = 0;
    while(~scanf("%d", &n)) {
    	if (n == 0)
    		break;
        for(int i = 1; i <= n; ++i) 
		{
            double x1, y1, x2, y2;
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            a[i] = (node){x1, x2, y1, 1};
            a[i + n] = (node){x1, x2, y2, -1};
            x[i] = x1; x[i + n] = x2;
        }
        n <<= 1;
        sort(a + 1, a + 1 + n, cmp);
        sort(x + 1, x + 1 + n);
        int m = unique(x + 1, x + 1 + n) - x - 1;
 
        memset(cnt, 0, sizeof(cnt));
        memset(sum, 0, sizeof(sum));
 
        double ans = 0;
        for(int i = 1; i < n; ++i) {
            int l = lower_bound(x + 1, x + 1 + m, a[i].l) - x;
            int r = lower_bound(x + 1, x + 1 + m, a[i].r) - x;
            if(l < r) 
				update(1, 1, m , l, r - 1, a[i].d);
            ans += sum[1] * (a[i + 1].y - a[i].y);
        }
        printf("Test case #%d\nTotal explored area: %.2f\n\n", ++T, ans);
    }
    return 0;
}