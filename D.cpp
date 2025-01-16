#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,a[N],b[N],p[N];
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),p[a[i]]=i,a[i+n]=a[i];
    for(int i=1;i<=m;i++)scanf("%d",&b[i]);
    bool flag=true;
    int pos=p[b[1]];
    for(int i=pos;i<=pos+m-1;i++)if(a[i]!=b[i-pos+1]){flag=false;break;}
    if(flag){printf("1");return 0;}
    for(int i=1;i<=n/2;i++)swap(a[i],a[n-i+1]);
    for(int i=1;i<=n;i++)p[a[i]]=i,a[i+n]=a[i];
    pos=p[b[1]],flag=true;
    for(int i=pos;i<=pos+m-1;i++)if(a[i]!=b[i-pos+1]){flag=false;break;}
    if(flag)printf("1");
    else printf("0");
}