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
int n, a[500], i, j,waa,wab;
int main() {
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	waa = 0;
	wab = 0;
	bool ok = 0;
	for (i = n - 1; i >= 0; i--) {
		if (!ok)waa += a[i];
		else wab += a[i];
		ok = !ok;
	}
	printf("%d %d\n", waa, wab);
}
