#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,siz,a[N],b[N],c[N],t[N];
long long ans[N],d[N];
int lowbit(int x){return x&-x;}
int query(int x,int res=0){while(x)res+=t[x],x-=lowbit(x);return res;}
void update(int x){while(x<=siz)t[x]++,x+=lowbit(x);}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=a[i];
    sort(b+1,b+n+1),siz=unique(b+1,b+n+1)-b-1;
    for(int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+siz+1,a[i])-b;
    for(int i=1;i<=n;i++)c[a[i]]++,d[a[i]]+=b[a[i]];
    for(int i=1;i<=siz;i++)c[i]+=c[i-1],d[i]+=d[i-1];
    for(int i=1,x;i<=n;i++)x=a[i],ans[i]=1ll*b[x]*c[x]-d[x];
    for(int i=1,x;i<=n;i++)x=a[i],ans[i]+=query(x),update(x);
    for(int i=1;i<=n;i++) {
        if(ans[i]>=m-1)puts("-1");
        else printf("%lld\n",ans[i]);
    }
}