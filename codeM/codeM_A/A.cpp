#include <bits/stdc++.h>
using namespace std;
const int posx[]={1,1,1,2,2,2,0,0,0,1,1,1,2,2,2,0,0,0,0,1,1,1,2,2,2,2};
const int posy[]={0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2};
inline int s(int x,int y,int b){
    return abs(x-posx[b])+abs(y-posy[b]);
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T-- > 0) {
        int ans=0;
        string ss;
        cin >> ss;
        int curx=0,cury=0;
        for (char &c: ss){
            ans+=s(curx,cury,c-'A');
            curx=posx[c-'A'];
            cury=posy[c-'A'];
        }
        printf("%d\n", ans);
    }
}