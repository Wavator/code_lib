#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
template<class T>inline void print(T x){if(x/10!=0)print(x/10);putchar(x%10+'0');}
template<class T>inline void writeln(T x){if(x<0)putchar('-');x=abs(x);print(x);putchar('\n');}
template<class T>inline void write(T x){if(x<0)putchar('-');x=abs(x);print(x);}
/*================Header Template==============*/
int T,n,m,p,g[1005],h[10005],f[1005];
int main() {
    read(T);
    while(T--) {
        read(n);
        for(int i=n-1;~i;--i)
            read(g[i]);
        read(m);
        for(int i=m-1;~i;--i)
            read(h[i]);
        p=m-n+1;
        for(int i=p-1;~i;--i) {
//			cout<<i<<" "<<i+n-1<<" "<<g[n-1]<<" "<<h[i+n-1]<<endl;
            f[i]=h[i+n-1]/g[n-1];
            for(int j=0;j<n;++j)
                h[j+i]-=f[i]*g[j];
//			for(int j=0;j<m;++j)
//				printf("%d ",h[j]);
//			puts("");
        }
        printf("%d\n",p);
        for(int i=p-1;~i;--i)
            printf("%d ",f[i]);
        puts("");
    }
}