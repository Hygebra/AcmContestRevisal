#include <cstdio>
#include <algorithm>
using namespace std;
const int S=200005;
const long long inf=(1ll<<60)-1;
int n,h[S],nx[S],v[S],eg=1,a[S],t[S],fa[S];
long long f[S],g[S],sg[S],p[S];
void egadd(int uu,int vv) {
    nx[++eg]=h[uu];h[uu]=eg;
    v[eg]=vv;
}
void dfs(int x) {
    g[x]=0;
    long long ma1=-inf,ma2=-inf;
    for (int i=h[x];i;i=nx[i]) {
        if (v[i]!=fa[x]) {
            fa[v[i]]=x;
            dfs(v[i]);
            g[x]+=f[v[i]];
            if (p[v[i]]>=ma1) {
                ma2=ma1;ma1=p[v[i]];
            } else if (p[v[i]]>=ma2) {
                ma2=p[v[i]];
            }
        }
    }
    f[x]=max(ma1,0ll);
    for (int i=h[x];i;i=nx[i])
        if (v[i]!=fa[x]) {
            if (t[v[i]]==3) {
                long long o = (p[v[i]]==ma1)?ma2:ma1;
                f[x]=max(f[x], a[v[i]]+max(o,0ll));
            } else {
                f[x]=max(f[x], a[v[i]]*1ll);
            }
        }
    f[x]+=g[x];
    p[x]=a[x]+g[x]-f[x];
}
int main() {
    int T;scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;++i) scanf("%d",a+i);
        for (int i=1;i<=n;++i) scanf("%d",t+i);
        for (int i=1;i<=n;++i) h[i]=fa[i]=f[i]=g[i]=p[i]=0;
        eg=1;
        for (int i=1,uu,vv;i<n;++i) {
            scanf("%d%d",&uu,&vv);
            egadd(vv,uu);
            egadd(uu,vv);
        }
        dfs(1);
        printf("%lld\n",f[1]+a[1]);
    }
    return 0;
}