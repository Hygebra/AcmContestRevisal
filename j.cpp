//
// Created by Layn on 24-11-13.
//
#include <cstdio>
const int S=200005;
int n,a[S],pre[S];
int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",a+i);
        if (pre[i-1]>a[i]) pre[i]=pre[i-1];
        else pre[i]=a[i];
    }
    int res=0;
    for (int i=n;i>=1;--i)
        if (a[i]+pre[i-1]>res) res=a[i]+pre[i-1];
    printf("%d\n",res);
    return 0;
}