//
// Created by Layn on 24-11-13.
//
//
// Created by Layn on 24-11-13.
//
#include <bits/stdc++.h>
    using namespace std;
    const int N = 305;
int n = 0, m = 0, c = 0, d = 0, ne = 0;
char s[N][N];
const int S=200005,inf=(1<<30)-1;
int ss,tt,h[S],nx[S],v[S],w[S],eg=1,g[S],dis[S],gap[S];
bool vis[S];
void add(int uu,int vv,int cc) {
    nx[++eg]=h[uu];h[uu]=eg;
    v[eg]=vv; w[eg]=cc;
    nx[++eg]=h[vv];h[vv]=eg;
    v[eg]=uu; w[eg]=0;
}
queue<int> q;
void bfs()
{
    for (int i=1;i<=tt;i++)
        dis[i]=tt+1;
    dis[tt]=1;
    gap[1]++;
    q.push(tt);
    while (!q.empty()) {
        int x = q.front();q.pop();
        for (int i=h[x];i;i=nx[i])
            if (dis[v[i]]==tt+1)
            {
                dis[v[i]]=dis[x]+1;
                gap[dis[v[i]]]++;
                q.push(v[i]);
            }
    }
}
inline int mi(int a,int b){return a<b?a:b;}
int dfs(int x,int mx)
{
    if (x==tt) return mx;
    int used=0,fl;
    for (int &i=g[x];i;i=nx[i])
        if (dis[x]==dis[v[i]]+1)
        {
            fl=dfs(v[i],mi(mx-used,w[i]));
            w[i]-=fl;
            w[i^1]+=fl;
            used+=fl;
            if (mx==used)
                return mx;
        }
    if (!(--gap[dis[x]]))
        dis[ss]=tt+1;
    ++gap[++dis[x]];
    g[x]=h[x];
    return used;
}
int maxflow()
{//printf("%d\n",0);
    bfs();int res=0;
    for (int i=1;i<=tt;++i) g[i]=h[i];
    do res+=dfs(ss,inf);
    while (dis[ss]<=tt);
    return res;
}
vector<int> mark;
int main() {
    scanf("%d%d%d%d", &n, &m, &c, &d);
    int tot = 0;
    ss=n+m+1;tt=n+m+2;
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= m; j++)
            if (s[i][j] == '.') tot++, add(i,n+j,1);
    }
    for (int i=1;i<=n;++i) {
        mark.push_back(eg+1);
        add(ss,i,0);
    }
    for (int i=1;i<=m;++i) {
        mark.push_back(eg+1);
        add(n+i, tt, 0);
    }
    long long ans = (long long)d * tot;

    for (int k = 1, z = tot; z>0; ++k) {
        for (int id: mark) w[id]++;
        //puts("c");
        int o = maxflow();
        z -= o;
        ans = min(ans, (long long)c * k + (long long)d * z);
        if (o==0) break;
        //printf("z = %d\n",z);
    }
    printf("%lld\n", ans);
    return 0;
}
/*
3 4
.***
*..*
**..
 */