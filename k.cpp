//
// Created by Layn on 24-12-4.
//
#include <algorithm>
#include <cstdio>
const int S=200005;
int n,h[S],u[S],v[S],nx[S],eg=1,m,fa[S],st[S];
void egadd(int uu,int vv) {
    nx[++eg]=h[uu];h[uu]=eg;
    v[eg]=vv;
}
bool fg = false,vis[S],is[S];
void dfs(int x,int fat) {
    vis[x]=true;is[x]=true;//printf("x=%d\n",x);

    for (int i=h[x];i && !fg;i=nx[i]) {
        if (v[i]!=fat) {
            if (is[v[i]]) {
                fg=true;
                st[++st[0]]=i/2;
                std::sort(st+1,st+1+st[0]);
                for (int j=1;j<st[0];++j)
                    printf("%d ",st[j]);
                printf("%d\n",st[st[0]]);
                //printf("i=%d %d %d\n",i/2,x,v[i]);
                break;
            } else if (!vis[v[i]]) {
                st[++st[0]]=i/2;
                dfs(v[i],x);
                --st[0];
            }
        }
    }
    is[x]=false;
}
inline int fd(int x){return fa[x]==x?x:fa[x]=fd(fa[x]);}
int main() {
    int T;scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);
        fg=false;
        eg=1;
        for (int i=1;i<=n;++i) fa[i]=i,h[i]=0,vis[i]=is[i]=false;
        for (int i=1,uu,vv;i<=m;++i) {
            scanf("%d%d",&uu,&vv);
            egadd(uu,vv);egadd(vv,uu);
            if (fd(uu) == fd(vv)) {
                if (!fg) {
                    st[0]=0;
                    dfs(uu,0);
                }
            } else {
                fa[fd(uu)] = fd(vv);
            }
        }
        if (!fg) puts("-1");
    }
}