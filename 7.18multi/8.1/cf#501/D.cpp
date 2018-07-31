#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<time.h>
#include<math.h>
#include<memory>
#include<vector>
#include<bitset>
#include<fstream>
#include<stdio.h>
#include<utility>
#include<assert.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define nb main
#define csl signed

csl nb() {
#ifdef cubercsl
    freopen("test.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n, k, s;
    cin >> n >> k >> s;
    if (s>(n-1)*k)
    {
        cout << "NO" << endl;
        return 0;
    }
    if (s < k) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    long long fsts = 1;
    for (int i=1;i<=k;i++) {
        long long temp = min(n - 1,s - (k-i));
        s -= temp;
        if (fsts == 1) fsts+=temp;
        else fsts-=temp;
        cout << fsts << ' ';
    }
    return 0;
}