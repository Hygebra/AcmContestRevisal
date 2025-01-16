#include<bits/stdc++.h>
using namespace std;
const int N=1e7+4,mod=1000000009;
int n,m,a[N],pre[N],suf[N],inv[N],f[N],g[N];
int mul(int x,int y){return 1ll*x*y%mod;}
int add(int x,int y) {
    int z=x+y;
    if(z<mod)return z;
    return z-mod;
}
int qpow(int x,int y,int res=1) {
    for(int cur=x;y;y>>=1,cur=mul(cur,cur))if(y&1)res=mul(res,cur);
    return res;
}
int main() {
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++)a[i]=i*m-i+1;
    pre[0]=1,suf[n+1]=1;
    for(int i=1;i<=n;i++)pre[i]=mul(pre[i-1],a[i]);
    for(int i=n;i>=1;i--)suf[i]=mul(suf[i+1],a[i]);
    int INV=qpow(pre[n],mod-2);
    for(int i=1;i<=n;i++)inv[i]=mul(mul(pre[i-1],suf[i+1]),INV);
    for(int i=1;i<=n;i++)
        g[i]=add(g[i-1],mul(m,inv[i])),f[i]=add(f[i-1],mul(g[i-1]+1,m));
    printf("%d",f[n]);
}