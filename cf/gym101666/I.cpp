#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <bitset>
#include <memory>
#include <cstdio>
#include <utility>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
int p, q,d[500],n;
/*int dfs(int cha, int np, int nq,bool me,bool black) {
	int i, j;
	if (np == 0 || nq == 0) {
		/*printf("wo:%d,sis:%d\n", waa, wab);
		for (i = 0; i < n; i++) {
			printf("%d ", d[i]);
		}
		printf("\n");
		return cha;
	}
	if (me) {
		for (i = 1; i <= nq; i++) {
			int t=0;
			if (i & 1) {
				if (black)t = 1;
				else t = -1;
			}
			dfs(cha+t, np, nq - i, 0, black ^ (i & 1));
		}
	}
	else{
		for (i = 1; i <= np; i++) {
			int t = 0;
			if (i & 1) {
				if (!(black^(np&1)))t = 1;
				else t = -1;
			}
			dfs(cha-t, np-i, nq, 1, black);
		}
	}
}*/
int main() {
	scanf("%d%d", &p, &q);
	if (p == 1) {
		if (q & 1)printf("1\n");
		else printf("2\n");
		return 0;
	}
	else {
		if (p % 2 == 1 && q %2 == 1)
			return !printf("1\n");
		if (p % 2 == 0)
			return !printf("0\n");
		if (p < q)
			return !printf("2\n");
		puts("0");
	}
}
