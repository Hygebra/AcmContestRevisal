#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct Layn{int x,y;}q[N],Q[N];
int T,n,m,a[N],b[N];
bool cmp(Layn u,Layn v){return u.x<v.x;}
int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=m;i++)scanf("%d%d",&q[i].x,&q[i].y);
        sort(a+1,a+n+1),sort(q+1,q+m+1,cmp),q[0].x=-1,q[0].y=0;
        for(int i=0;i<=m;i++)Q[i]=q[i];
        int cnt=0,M=m;m=0;
        for(int i=1;i<=M;i++)if(!Q[i].y||Q[i].x==q[m].x+1)q[++m]=Q[i];
        for(int i=0;i<=m;i++)if(!q[i].y)b[++cnt]=i;
        long long sum=0;
        for(int i=1,j=0,k=1;i<=n;i++) {
            while(k<=cnt&&q[b[k]].x<a[i])k++;k--;
            j=max(j,b[k]+1);
            while(j<=m&&q[j].x<=a[i]&&!q[j].y)j++;
            if(j<=m&&q[j].x<=a[i]&&q[j].y) {
                sum+=(a[i]-q[j].x);
                q[j].y--;
            }
            else sum+=(a[i]-q[j-1].x-1);
        }
        if(sum&1)puts("Pico");
        else puts("FuuFuu");
    }
}