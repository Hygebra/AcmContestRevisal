#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,mod=998244353;
int n,e,head[N],f[N],g[N],link[N*2],to[N*2],siz[N],fac[N],inv[N],ifac[N],F[N];
int mul(int x,int y){return 1ll*x*y%mod;}
int add(int x,int y) {
    int z=x+y;
    if(z<mod)return z;
    return z-mod;
}
void add_edge(int u,int v){to[++e]=v,link[e]=head[u],head[u]=e;}
int C(int x,int y){return mul(fac[x],mul(ifac[y],ifac[x-y]));}
void dfs(int u,int fa) {
    siz[u]=1,f[u]=1;
    int cnt=0;
    for(int i=head[u];i;i=link[i]) {
        int v=to[i];
        if(v==fa)continue;
        dfs(v,u),siz[u]+=siz[v],f[u]=mul(f[u],f[v]);
        if(siz[v]&1)cnt++;
    }
    if(cnt&1)cnt--,f[u]=mul(f[u],F[cnt]),f[u]=mul(f[u],cnt+1);
    else f[u]=mul(f[u],F[cnt]);
}
int main() {
    fac[0]=1,inv[0]=inv[1]=1,ifac[0]=1;
    scanf("%d",&n);
    F[0]=1,F[1]=1;
    for(int i=2;i<=n+1;i+=2)F[i]=mul(i-1,F[i-2]);
    for(int i=2;i<=n+1;i++)inv[i]=mul(inv[mod%i],mod-mod/i);
    for(int i=1;i<=n+1;i++)fac[i]=mul(fac[i-1],i),ifac[i]=mul(ifac[i-1],inv[i]);
    for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),add_edge(u,v),add_edge(v,u);
    dfs(1,0);
    printf("%d",f[1]);
}