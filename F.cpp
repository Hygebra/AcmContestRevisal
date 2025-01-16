#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int T,n,a[N],t[N],b[N],vis[N];
int lowbit(int x){return x&-x;}
void update(int x){while(x<=n)t[x]++,x+=lowbit(x);}
int query(int x,int y=0) {
    if(x<0)return 0;
    while(x)y+=t[x],x-=lowbit(x);return y;
}
int main(){
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[a[i]]=i,vis[i]=0;
        for(int i=n;i>=1;i--) {
            if(vis[i])continue;
            if(b[i-1]>b[i])vis[i]=i-1,vis[i-1]=i;
            else vis[i]=i;
        }
        for(int i=1;i<=n;i++)t[i]=0;
        long long ans=0;
        for(int i=n;i>=1;i--) {
            ans+=query(vis[a[i]]-1);
            update(a[i]);
        }
        printf("%lld\n",ans);
    }
}