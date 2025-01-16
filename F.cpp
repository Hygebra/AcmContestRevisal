#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,e,hd,in[N],IN[N],head[N],link[N*2],to[N*2],c[N],U[N],V[N];
bool vis[N],VIS[N];
long long ans;
queue<int>q;
void add(int u,int v){to[++e]=v,link[e]=head[u],head[u]=e,in[v]++;}
void dfs(int u){
    if(vis[u])return;
    vis[u]=1;
    for(int i=head[u];i;i=link[i])dfs(to[i]);
}
int main() {
    scanf("%d",&n);
    for(int i=1,u,v;i<=n;i++)scanf("%d%d",&u,&v),add(u,v),add(v,u),U[i]=u,V[i]=v;
    dfs(1);
    for(int i=1;i<=n;i++)if(!vis[i]||in[i]>5) {
        puts("0");
        return 0;
    }
    for(int i=1;i<=n;i++)vis[i]=0,IN[i]=in[i];
    for(int i=1;i<=n;i++)if(in[i]==1)q.push(i),vis[i]=1;
    while(!q.empty()) {
        int u=q.front();q.pop();
        for(int i=head[u];i;i=link[i]) {
            int v=to[i];
            if(vis[v])continue;
            --in[v];
            if(in[v]==1)q.push(v),vis[v]=1;
        }
    }
    for(int i=1;i<=n;i++)c[IN[i]]++;
    for(int i=1;i<=n;i++) {
        int u=U[i],v=V[i];
        if(vis[u]||vis[v])continue;
        c[IN[u]]--,c[IN[v]]--;
        c[IN[u]-1]++,c[IN[v]-1]++;
        if(!c[5])ans+=(c[0]+c[1]+c[2]+c[3]);
        c[IN[u]]++,c[IN[v]]++;
        c[IN[u]-1]--,c[IN[v]-1]--;
    }
    printf("%lld",ans);
}