#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    ll n;
    cin >> n;
    puts((n & 1)? "Alice":"Bob");
    return 0;
}