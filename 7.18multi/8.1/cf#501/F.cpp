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
struct mm {
    int x, y, z;
    mm(int x, int y, int z):x(x), y(y), z(z){}
    inline void print() const{
        printf("%d %d %d\n",x,y,z);
    }
};
const int mod = 1e9+7;
const int N = 255;
int n,m;
char s[N];
int pre[N];
int dp[N][N][N];
void ssub(int&x,int y){
    x += y;
    x %= mod;
}
csl nb(){
    scanf("%d%s",&n,s+1);
    m=strlen(s+1);
    pre[1]=0;
    for (int i = 2; i <= m; ++i){
        int k=pre[i-1];
        while(k&&s[k+1]!=s[i]) k=pre[k];
        if(s[k+1]==s[i]) pre[i]=k+1;
    }
    dp[0][0][0]=1;
    int aa = n * 2;
    for (int i = 0; i < aa; ++i) {
        int bb = min(i, n);
        for(int j = (i + 1) / 2; j <= bb; ++j) {
            int cc = min(i, m);
            for (int  k = 0; k <= cc; ++k){
                int now=dp[i][j][k];
                if(!now) continue;
                if(k==m){
                    if(j + j >= i+1)
                        ssub(dp[i+1][j][m],now);
                    ssub(dp[i+1][j+1][m],now);
                    continue;
                }
                int x=k;
                for(;x&&s[x+1]!='(';x=pre[x]) ;
                if(s[x+1]=='(') ++x;
                ssub(dp[i+1][j+1][x],now);
                if(2*j==i) continue;
                x=k;
                for(;x&&s[x+1]!=')'; x=pre[x]);
                if(s[x+1]==')') ++x;
                ssub(dp[i+1][j][x],now);
            }
        }
    }
    cout << dp[aa][n][m] << endl;
    return 0;
}