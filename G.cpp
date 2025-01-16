#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int T,n,a[N],pre[N];
int gcd(int x,int y) {
    if(!y)return x;
    return gcd(y,x%y);
}
int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        int cnt=0,cur=1,C;
        bool flag=0;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        pre[0]=a[0]=1,pre[n+1]=0;
        for(int i=1;i<=n;i++)pre[i]=pre[i-1]+(a[i]==1);
        C=pre[n];
        for(int i=1;i<=n;i++)pre[i]=(i+3)/2-pre[i];
        for(int i=n;i>=1;i--)pre[i]=max(pre[i+1],pre[i]);
        for(int i=1;i<=n;i++) {
            if(a[i]==1)cur++;
            if(a[i]==0) {
                if(cnt<pre[i])cnt++,cur++;
                else cur--;
                if(cur<=0){flag=1;break;}
            }
            if(a[i]==-1) {
                cur--;
                if(cur<=0){flag=1;break;}
            }
        }
        if(flag)puts("-1");
        else {
            cnt+=C;
            int x=cnt,y=cnt*2-n-1,g=gcd(x,y);
            x/=g,y/=g;
            printf("%d %d\n",x,y);
        }
    }

}