#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n;
long long k,g[N][2],f[N][2];
struct Layn{int c,w,f;}a[N];
bool cmp(Layn x,Layn y){return x.f==y.f?x.w>y.w:x.f<y.f;}
long long Div(long long x,long long y) {
    if(x<0)return 0;
    return x/y+(x%y!=0);
}
int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d%lld",&n,&k);
        for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i].c,&a[i].w,&a[i].f);
        sort(a+1,a+n+1,cmp);
        f[n+1][0]=g[n+1][0]=0;
        f[n+1][1]=1e15,g[n+1][1]=0;
        long long F=0;
        for(int i=n;i>=1;i--) {
            long long f0,g0,f1,g1;
            long long tmp=a[i].c*a[i].w,cur;
            cur=Div(tmp-g[i+1][0],k),f0=f[i+1][0]+cur*a[i].f,g0=g[i+1][0]+cur*k-tmp;
            cur=Div(tmp+1-g[i+1][1],k),f1=f[i+1][1]+max(0ll,cur-1)*a[i].f+F,g1=g[i+1][1]+cur*k-tmp-1;
            if(f0==f1) {
                if(g0>g1)f[i][0]=f0,g[i][0]=g0;
                else f[i][0]=f1,g[i][0]=g1;
            }else {
                if(f0<f1)f[i][0]=f0,g[i][0]=g0;
                else f[i][0]=f1,g[i][0]=g1;
            }
            if(a[i].w==2) {
                cur=Div(tmp-g[i+1][1],k);
                f[i][1]=f[i+1][1]+cur*a[i].f,g[i][1]=g[i+1][1]+cur*k-tmp;
            }else {
                cur=Div(tmp-1-g[i+1][0],k);
                f[i][1]=f[i+1][0]+cur*a[i].f,g[i][1]=g[i+1][0]+cur*k-(tmp-1);
                F=a[i].f;
            }
        }printf("%lld\n",f[1][0]);
        // for(int i=n;i>=1;i--) {
        //     printf("%d: f:%lld %lld g:%lld %lld\n",i,f[i][0],f[i][1],g[i][0],g[i][1]);
        // }
    }
}