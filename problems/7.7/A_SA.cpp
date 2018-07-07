#include <bits/stdc++.h>
using namespace std;
class SA {
public:
    static const int N = 40000 + 500;
    int t1[N],t2[N],c[N],sa[N],rk[N],h[N];
    char s[N];
    int n,m;
    void read() {
        scanf("%s",s);
    }
    void init(char * s) {
        memcpy(this->s, s, sizeof(this->s));
        init();
    }
    void init() {
        n=strlen(s);
        for(int i=0;i<n;++i)
            s[i] = s[i]-'a' + 1;
        m=27;
        n++;
        int i,j,p,*x=t1,*y=t2;
        for(i=0;i<m;i++)c[i]=0;
        for(i=0;i<n;i++)c[x[i]=s[i]]++;
        for(i=1;i<m;i++)c[i]+=c[i-1];
        for(i=n-1;i>=0;i--)sa[--c[x[i]]]=i;
        for(j=1;j<=n;j<<=1) {
            p=0;
            for(i=n-j;i<n;i++)y[p++]=i;
            for(i=0;i<n;i++)if(sa[i]>=j)y[p++]=sa[i]-j;
            for(i=0;i<m;i++)c[i]=0;
            for(i=0;i<n;i++)c[x[y[i]]]++;
            for(i=1;i<m;i++)c[i]+=c[i-1];
            for(i=n-1;i>=0;i--)sa[--c[x[y[i]]]]=y[i];
            swap(x,y);
            p=1;x[sa[0]]=0;
            for (i = 1; i < n; ++i) {
                x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + j] == y[sa[i] + j]? p - 1:p++;
            }
            if(p>=n)break;
            m=p;
        }
        n--;



        // if get height and rank
        int k = 0;
        for(i=0;i<=n;i++)rk[sa[i]]=i;
        for(i=0;i<n;i++) {
            if(k)k--;
            j=sa[rk[i]-1];
            while(s[i+k]==s[j+k])k++;
            h[rk[i]]=k;
        }

    }
//    inline int cmp(char * pt, int p) {
//        return strncmp(pt,s+sa[p],m);
//    }
//    inline int find(char* p) {
//        m = strlen(p);
//        if (cmp(p,0) < 0 || cmp(p,n-1) > 0)
//            return -1;
//        int l = 0, r = n - 1;
//        while (r >= l) {
//            static int mid;
//            mid = l + r >> 1;
//            int res = cmp(p,mid);
//            if (!res)
//                return mid;
//            if (res < 0)
//                r = mid - 1;
//            else
//                l = mid + 1;
//        }
//        return -1;
//    }



};
class LCP: public SA {
public:
    int pos;
    int check(int Len) {
        int cnt = 1,flag = 0, tmp = 0;
        for(int i = 1; i <= n; i++) {
            if(h[i] >= Len) {
                cnt++;
                tmp = max(tmp,(max(sa[i - 1], sa[i])));
                if(cnt>=m) {
                    if(!flag)
                        pos = tmp;
                    else
                        pos = max(pos,tmp);
                    flag=1;
                }
            }
            else cnt=1, tmp=0;
        }
        return flag;
    }
    bool lcp(int m) {
        if (m == 1)
            return printf("%d 0\n", n), true;
        this->m = m;
        pos = 0;
        int l=1, r = n;
        while(l <= r) {
            int mid=l+r>>1;
            if(check(mid))
                l = mid+1;
            else r = mid-1;
        }
        if(l==1)
            return false;
        else
            return printf("%d %d\n",l-1,pos), true;
    }
};
LCP vince;
int main() {
    int n;
    while (scanf("%d",&n)&&n) {
        vince.read();
        vince.init();
        if (!vince.lcp(n))
            puts("none");
    }
    return 0;
}