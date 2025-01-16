//
// Created by Layn on 24-10-16.
//
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int N=5005,S=N*2;
int n,k,W;
struct node {
    int p,v;
}a[S];
priority_queue<int> pq;
const long long inf=1ll<<60;
long long f[N][S],res,su;
inline bool cmp(const node &a, const node &b) {
    return a.p<b.p;
}
int main() {
    scanf("%d%d%d",&n,&W,&k);
    for (int i=1;i<=n;++i) {
        scanf("%d%d",&a[i].p,&a[i].v);
    }
    sort(a+1,a+1+n,cmp);
    for (int i=1;i<=n;++i) {
        for (int j=0;j<a[i].p;++j)
            f[i][j]=f[i-1][j];
        for (int j=a[i].p;j<=W;++j) {
            f[i][j]=max(f[i-1][j], f[i-1][j-a[i].p] + a[i].v);
        }
        for (int j=1;j<=W;++j)
            f[i][j]=max(f[i][j],f[i][j-1]);
    }
    su=0;
    res=0;
    for (int i=n;i>=0;--i) {
        res=max(res,f[i][W] + su);
        su+=a[i].v;
        pq.push(-a[i].v);
        if (n-i+1>k) {
            su += pq.top();
            pq.pop();
        }
    }
    printf("%lld\n",res);
    return 0;
}