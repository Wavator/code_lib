#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int val[1<<20];
int a[500005];
void change(int num,int l,int r,int x)
{
    if (l==r-1)
    {
        val[num]=1;
        return;
    }
    int mid=(l+r)/2;
    if (x<mid)
    {
        change(num*2+1,l,mid,x);
    }
    else
    {
        change(num*2+2,mid,r,x);
    }
    val[num]=val[num*2+1]|val[num*2+2];
}
bool query(int num,int l,int r,int l0,int r0)
{
    if (l0>=r0) return false;
    if ((l0<=l)&&(r<=r0))
    {
        return val[num];
    }
    int mid=(l+r)/2;
    bool ans=false;
    if (l0<mid) ans|=query(num*2+1,l,mid,l0,r0);
    if (mid<r0) ans|=query(num*2+2,mid,r,l0,r0);
    return ans;
}
int main()
{
    int k,n;
    scanf("%d%d",&n,&k);
    int d;
    scanf("%d",&d);
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    change(0,0,n+1,0);
    for (i=0;i<n;i++)
    {
        bool ans=query(0,0,n+1,lower_bound(a,a+n,a[i]-d)-a,i-k+2);
        if (ans)
        {
            if (i==n-1)
            {
                puts("YES");
                return 0;
            }
            change(0,0,n+1,i+1);
        }
    }
    puts("NO");
    return 0;
} 
