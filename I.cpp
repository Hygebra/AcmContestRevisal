#include<bits/stdc++.h>
using namespace std;
const int N=2010,mod=1e9+7;
int n,sum,siz[N],a[N],p[N],ans[N],F[N][N],f[N][N],G[N][N],g[N][N];
vector<int>t[N];
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
void dfs(int u,int fa) {
    siz[u]=1;
    f[u][0]=(1-p[u]+mod)%mod,f[u][1]=p[u];
    g[u][1]=a[u],g[u][0]=0;
    for(auto v:t[u])if(v!=fa) {
        dfs(v,u);
        for(int i=1;i<=siz[u];i++)for(int j=0;j<=siz[v];j++)
            F[u][i+j]=add(F[u][i+j],mul(f[u][i],f[v][j])),
            G[u][i+j]=add(G[u][i+j],mul(g[u][i],f[v][j])),
            G[u][i+j]=add(G[u][i+j],mul(f[u][i],g[v][j]));
        siz[u]+=siz[v];
        for(int i=1;i<=siz[u];i++)
            f[u][i]=F[u][i],g[u][i]=G[u][i],F[u][i]=G[u][i]=0;
    }
    for(int i=1;i<=siz[u];i++)ans[i]=add(ans[i],mul(g[u][i],(1-p[fa]+mod)%mod));
}
int main() {
    scanf("%d",&n);
    for(int i=1,u,v;i<n;i++)
        scanf("%d%d",&u,&v),t[u].push_back(v),t[v].push_back(u);
    for(int i=1,x,y;i<=n;i++)
        scanf("%d%d%d",&a[i],&x,&y),p[i]=mul(x,qpow(y,mod-2)),sum+=a[i];
    for(int i=1;i<=n;i++)
        a[i]=mul(a[i],qpow(sum,mod-2));
    dfs(1,0);
    for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
    return 0;
}