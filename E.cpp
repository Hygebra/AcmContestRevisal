#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int T,n,a[N];
int highbit(int x) {
    for(int i=30;i>=0;i--)if((x>>i)&1)return (1<<i);
    return 1;
}
int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)a[i]=0;
        for(int i=1,c;i<=n;i++)scanf("%d",&c),a[c]++;
        int mx=0,ans=0;
        for(int i=1;i<=n;i++)if(a[mx]<a[i])mx=i;
        for(int i=1;i<=n;i++)if(i!=mx)
            ans=max(ans,a[i]|a[mx]|(highbit(a[i]&a[mx])-1));
        printf("%d\n",max(ans,a[mx]));
    }
}