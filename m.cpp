//
// Created by Layn on 24-11-4.
//
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int S=1000005,mod=1e9+7;
int i4[S];
int n,m,k;
char a[S],b[S];
inline int ksm(int a,int x) {
    int s=1;
    while (x) {
        if (x&1) s=1ll*s*a%mod;
        a=1LL*a*a%mod,x>>=1;
    }
    return s;
}
int main() {
    i4[0]=1;
    for (int i=1;i<S;++i)
        i4[i]=(i4[i-1]*4ll+1)%mod;
    //printf("%d %d\n",i4[14],i4[13]);
    int T;scanf("%d",&T);
    while (T--) {
        scanf("%s%s%d",a,b,&k);--k;
        n=strlen(a);m=strlen(b);
        for (int i=0;i<n;++i) a[i]-='0';
        for (int i=0;i<m;++i) b[i]-='0';
        for (int i=0,j=n-1;i<j;++i,--j)
            swap(a[i],a[j]);
        for (int i=0,j=m-1;i<j;++i,--j)
            swap(b[i],b[j]);
        if (m>n) {
            for (int i=n;i<m;++i)
                a[i]=0;
            n=m;
        }
        for (int i=0;i<m;++i) a[i]^=b[i];
        int s=2e9+4;
        for (int i=0;i<n;++i)
            if (a[i]) {s=i;break;}
        //printf("s=%d\n",s);
        if (s<1e8 && k+1>s/2+1) {
            puts("-1");
            continue;
        }
        //for (int i=0;i<n;++i) putchar(a[i]^48);puts("xor");
        int su = 0;
        if (n&1) {
            a[n]=0;
        }
        for (int i=(n-1)|1;i>s-1;i-=2) {
            //puts("c");
            int base = i4[i/2];
            switch(a[i]<<1|a[i-1]) {
                case 2: su=(su+base)%mod;
                case 3: su=(su+base)%mod;
                case 1: su=(su+base)%mod;
                case 0: break;
                default: break;
            }
        }
        int id = min(k,s/2);
        su=(su+(ksm(4,id+1)-1ll)*ksm(3,mod-2)%mod+mod - 1ll)%mod;
        printf("%d\n",su);
    }
    return 0;
}