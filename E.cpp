#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int n,k,cnt,a[N],b[N],f[N],t1[N],t2[N];
int lowbit(int x){return x&-x;}
int query1(int x,int res=0){while(x)res=max(res,t1[x]),x-=lowbit(x);return res;}
int query2(int x,int res=0){while(x<=cnt)res=max(res,t2[x]),x+=lowbit(x);return res;}
void update(int x,int y) {
    for(int cur=x;cur<=cnt;cur+=lowbit(cur))t1[cur]=max(t1[cur],y);
    for(int cur=x;cur;cur-=lowbit(cur))t2[cur]=max(t2[cur],y);
}
int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[++cnt]=a[i],b[++cnt]=a[i]+k,b[++cnt]=a[i]-k;
    sort(b+1,b+cnt+1),cnt=unique(b+1,b+cnt+1)-b-1;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) {
        int x;
        x=lower_bound(b+1,b+cnt+1,a[i]-k)-b;
        f[i]=max(f[i],query1(x)+1);
        x=lower_bound(b+1,b+cnt+1,a[i]+k)-b;
        f[i]=max(f[i],query2(x)+1);
        x=lower_bound(b+1,b+cnt+1,a[i])-b;
        update(x,f[i]);
    }int ans=0;
    for(int i=1;i<=n;i++)ans=max(ans,f[i]);
    printf("%d",ans);
}