#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=1e6;
int T,pr[N],vis[N],c[N],d[N],b[N],rt[N];
struct edge {int u,v,w;}e[N];
vector<int>t[N];
int root(int x) {
    if(rt[x]==x)return x;
    return rt[x]=root(rt[x]);
}
bool cmp(edge x,edge y){return x.w<y.w;}
int cal(int x,int y) {
    int res=t[x].size();
    for(int i=0;i<t[y].size();i++)if(x%t[y][i]!=0)res++;
    return res;
}
int main() {
    for(int i=2;i<=M;i++) {
        if(!vis[i])pr[++pr[0]]=i,vis[i]=i;
        for(int j=1;j<=pr[0]&&i*pr[j]<=M;j++) {
            int k=i*pr[j];
            vis[k]=pr[j];
            if(!(i%pr[j]))break;
        }
    }vis[1]=1;
    for(int i=1;i<=M;i++) {
        int x=i;b[i]=1;
        while(x>1) {
            int j=vis[x];
            t[i].push_back(j),b[i]*=j;
            while(x%j==0)x/=j;
        }
    }
    scanf("%d",&T);
    while(T--) {
        int l,r,ans=0,tmp=0;
        scanf("%d%d",&l,&r);
        if(l==1) {
            for(int i=1;i<=r;i++)ans+=t[i].size();
            printf("%d\n",ans);continue;
        }for(int i=l;i<=r;i++)if(t[i].size()==1){tmp=vis[i];break;}
        if(!tmp) {
            int cnt=0;
            for(int i=l;i<=r;i++)rt[i]=i;
            for(int i=l;i<r;i++)for(int j=i+1;j<=r;j++)
                e[++cnt].u=i,e[cnt].v=j,e[cnt].w=cal(i,j);
            sort(e+1,e+cnt+1,cmp);
            for(int i=1;i<=cnt;i++) {
                int ru=root(e[i].u),rv=root(e[i].v);
                if(ru==rv)continue;
                rt[ru]=rv,ans+=e[i].w;
            }printf("%d\n",ans);continue;
        }
        for(int i=1;i<=r;i++)c[i]=d[i]=0;
        for(int i=l;i<=r;i++)c[b[i]]++;
        for(int i=r;i>=1;i--)if(c[i])
            for(int j=i;j<=r;j+=i)d[j]++;
        for(int i=1;i<=r;i++)if(c[i]) {
            ans+=t[i].size()*c[i];
            if(d[i]==1)ans++;
            if(i==tmp)ans-=2;
        }printf("%d\n",ans);
    }
}