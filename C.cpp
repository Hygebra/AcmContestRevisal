#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=4e6+10,K=1e6;
int n,k,a[N],ans;
int tot[M],b[M],c[M];
int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]+=K*2,tot[a[i]]++;
    for(int i=1;i<=n;i++) {
        int x=a[i];
        b[x]++;
        c[x-k]=min(c[x-k],b[x-k]-b[x]);
        ans=max(ans,tot[x+k]+b[x]-b[x+k]-c[x]);
    }printf("%d",ans);
}