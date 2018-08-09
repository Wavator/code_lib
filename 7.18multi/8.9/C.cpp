#pragma optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#define tr(x) cerr << #x << (x) << endl;
#else
#define tr(x)
#endif
typedef long long ll;
int n;
ll dfs(const string &s)
{
    //tr(s);
    int cnt_of_1 = 0;
    for(const char &c: s)
        if(c=='1')
            ++cnt_of_1;
    if(cnt_of_1==0)
        return 0;
    if(cnt_of_1==s.size())
        return s.size();
    if(s.length()==1)
        return s[0] - 48;
    unsigned len=s.size()>>1;
    string string_xor(len,0);
    string string_or(len,0);
    string string_and(len,0);
    for(int i=0;i<s.length();i+=2) {
        string_xor[i >> 1] = (s[i] != s[i+1])+'0';
        string_or[i >> 1] = (s[i]=='1' || s[i+1]=='1')+'0';
        string_and[i >> 1] = (s[i]=='1' && s[i+1]=='1')+'0';
    }
    int f1 = (string_xor == string_or);
    int f2 = (string_or == string_and);
    int f3 = (string_xor == string_and);
    if(f1 && f2)
        return  3 * dfs(string_xor);
    else if(f1)
        return 2 * dfs(string_xor) + dfs(string_and);
    else if(f2)
        return dfs(string_xor) + 2 * dfs(string_and);
    else if(f3)
        return 2 * dfs(string_xor) + dfs(string_or);
    return dfs(string_xor) + dfs(string_or) + dfs(string_and);
}


int main()
{
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    string s;
    cin >> n >> s;
    cout << dfs(s) << endl;
    return 0;
}