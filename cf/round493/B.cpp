#include <bits/stdc++.h>
using namespace std;
const long long add = 49;
long long n;
set<int> s;
inline long long count(int n = 11) {
    for(int a=0;a<=n;a++)
        for(int b=0;a+b<=n;b++)
            for(int c=0;a+b+c<=n;c++) {
                int d=n-a-b-c;
                s.insert(a+5*b+10*c+50*d);
            }
    return (long long)(s.size());
}
int main() {
    cin >> n;
    if(n <= 11) {
        cout << count(n) << endl;
        return 0;
    }
    cout << add * (n - 11) + count();
    return 0;
}