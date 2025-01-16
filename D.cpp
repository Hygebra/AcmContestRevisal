#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,m,e,head[N],fa[N],f[N],son[N],dep[N],k[N],DEP[N],link[N*2],to[N*2];
bool vis[N];
vector<int>s[N],g[N];
void add(int u,int v){to[++e]=v,link[e]=head[u],head[u]=e;}
void dfs(int u) {
    son[u]=0;
    for(int i=head[u];i;i=link[i])if(to[i]!=fa[u])son[u]++;
    if(u==n)f[u]=u;
    else {
        if(son[fa[u]]>1)f[u]=fa[u];
        else f[u]=f[fa[u]];
        dep[u]=dep[f[u]]+1;
        DEP[u]=DEP[fa[u]]+1;
    }
    for(int i=head[u];i;i=link[i])if(to[i]!=fa[u])fa[to[i]]=u,dfs(to[i]);
}
void dfs1(int u) {
    for(auto v:g[u]) {
        dfs1(v);
        if(!s[v].size())continue;
        for(auto x:s[v])s[u].push_back(x);
    }sort(s[u].begin(),s[u].end());
}
bool dfs2(int u,int d) {
    for(int i=1;i<s[u].size();i++)if(s[u][i]-s[u][i-1]!=d)return 1;
    int cnt=0,tmp=0;
    for(auto v:g[u])if(s[v].size())cnt++;
    if(!cnt)return 0;
    if(s[u].size()%cnt!=0)return 1;
    for(auto v:g[u])if(s[v].size()) {
        if(s[v].size()!=s[u].size()/cnt)return 1;
        if(v<=m)continue;
        if(!tmp)tmp=DEP[v];
        else if(DEP[v]!=tmp)return 1;
    }
    int x=dep[u];
    if(!k[x])k[x]=cnt;
    else if(k[x]!=cnt)return 1;
    for(auto v:g[u])if(s[v].size()&&dfs2(v,d*cnt))return 1;
    return 0;
}
int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m),e=0,k[0]=0;
        for(int i=1;i<=n;i++)vis[i]=head[i]=k[i]=0,g[i].clear(),s[i].clear();
        for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),add(u,v),add(v,u);
        DEP[n]=0,dep[n]=0,fa[n]=n,dfs(n);
        bool flag=0;
        for(int i=1;i<m;i++)if(dep[i]!=dep[i+1]){flag=1;break;}
        if(flag){puts("Tie");continue;}
        for(int i=1;i<n;i++)g[f[i]].push_back(i);
        for(int i=1;i<=m;i++)s[i].push_back(i);
        dfs1(n);
        if(dfs2(n,1))puts("Tie");
        else puts("Doddle");
    }
}
// 1
// 7 4
// 7 6
// 7 5
// 5 1
// 3 5
// 2 6
// 6 4