#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,T,lst[N],mx[N],ans[N],t[N*4],L[N],R[N];
vector<int>f[N],b[N];
inline int read() {
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x;
}
inline int pushup(int x,int y) {
    if(x)return x;
    return y;
}
void build(int l,int r,int p) {
    if(l==r)return (void)(t[p]=l);
    int mid=(l+r)>>1;
    build(l,mid,p<<1),build(mid+1,r,p<<1|1);
    t[p]=pushup(t[p<<1],t[p<<1|1]);
}
void update(int l,int r,int p,int x) {
    if(l==r)return (void)(t[p]=0);
    int mid=(l+r)>>1;
    if(mid>=x)update(l,mid,p<<1,x);
    else update(mid+1,r,p<<1|1,x);
    t[p]=pushup(t[p<<1],t[p<<1|1]);
}
int query(int l,int r,int p,int ql,int qr) {
    if(ql>qr)return 0;
    if(l>=ql&&r<=qr)return t[p];
    int mid=(l+r)>>1;
    if(mid>=qr)return query(l,mid,p<<1,ql,qr);
    if(mid<ql)return query(mid+1,r,p<<1|1,ql,qr);
    return pushup(query(l,mid,p<<1,ql,qr),query(mid+1,r,p<<1|1,ql,qr));
}
int main() {
    scanf("%d",&T);
    while(T--) {
        n=read(),m=read();
        for(int i=1;i<=n+1;i++)b[i].clear(),f[i].clear();
        for(int i=0;i<=n*4;i++)t[i]=0;
        for(int i=1;i<=m;i++)lst[i]=0,mx[i]=0;
        int f1=0,f2=0;
        for(int i=1;i<=n;i++) {
            int cnt;
            cnt=read();
            for(int j=1,x;j<=cnt;j++)
                x=read(),b[i].push_back(x),mx[x]=i;
        }
        for(int i=1;i<=n;i++) {
            L[i]=0,R[i]=n+1;
            for(auto j:b[i]) {
                if(mx[j]==i)L[i]=max(L[i],lst[j]);
                else R[i]=min(R[i],mx[j]);
            }
            f[R[i]].push_back(i);
        }
        build(1,n,1);
        //for(int i=1;i<=n;i++)printf("--%d %d %d\n",i,L[i],R[i]);
        for(int i=1;i<=n;i++) {
            for(auto j:f[i])update(1,n,1,j);
            int tmp=query(1,n,1,L[i]+1,i-1);
            if(tmp) {
                f1=tmp,f2=i;
                break;
            }
        }if(!f1)puts("No");
        else {
            puts("Yes");
            //printf("--%d %d\n",f1,f2);
            for(int i=1;i<=n;i++)ans[i]=i;
            swap(ans[f1],ans[f2]);
            for(int i=1;i<n;i++)printf("%d ",ans[i]);
            printf("%d\n",ans[n]);
        }
    }
}