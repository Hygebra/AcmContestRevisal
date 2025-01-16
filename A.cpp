#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int T,n,e,head[N],siz[N],mn[N],mx[N],link[N*2],to[N*2];
void add(int u,int v){to[++e]=v,link[e]=head[u],head[u]=e;}
void dfs(int u,int fa) {
    siz[u]=1;
    for(int i=head[u];i;i=link[i]) {
        int v=to[i];
        if(v==fa)continue;
        mn[v]=mn[u]+1;
        dfs(v,u);
        siz[u]+=siz[v];
    }mx[u]=n-siz[u]+1;
}
int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n),e=0;
        for(int i=1;i<=n;i++)head[i]=0;
        for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),add(u,v),add(v,u);
        mn[1]=mx[1]=1,dfs(1,0);
        for(int i=1;i<=n;i++)printf("%d %d\n",mn[i],mx[i]);
    }
}