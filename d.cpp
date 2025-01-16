//
// Created by Layn on 24-10-27.
//
#include <bits/stdc++.h>
using namespace std;
const int S=200005;
int n,k,m,c,d,tot;
long long a[S];
bool is[S];
vector<int> ve[S];
int pd(long long mid) {
    /*
     * i-st>=0
     * st<=i
     * a[i] + c + d*(i - st) >=mid
     * -st*d >= mid-a[i]-c-d*i
     * st*d <= a[i]+c+d*i-mid
     * st <=
     * i-st+1<=m
     * st>=i+1-m
     */
    //printf("mid = %lld\n",mid);
    for (int i=1;i<=n;++i)
        is[i]=false,ve[i].clear();
    long long s=0;
    tot=0;
    for (int i=1;i<=n;++i) {
        if (a[i]>=mid) {
            ve[1].push_back(i);
            continue;
        }
        int r = i;
        if (a[i]+c<mid) {
            if (!d) continue;
            r = min(1ll*r, max(0ll,(a[i]+c+d*1ll*i-mid)/d));
        }
        int l = max(i+1-m, 1);
        if (l<=r) {
            ve[l].push_back(i);
            //printf("%d : %d %d\n",i,l,r);
            if (r<n) ve[r+1].push_back(i);
        }
    }
    int su=0,res=0;
    for (int i=1;i+m-1<=n;++i) {
        for (int o:ve[i]) {
            if (!is[o]) {
                ++su;
            } else {
                --su;
            }
            is[o]^=1;
        }
        //printf("su[%d] = %d\n",i,su);
        if (su>res) res=su;
    }
    return res;
}
int main() {
    scanf("%d%d%d%d%d",&n,&k,&m,&c,&d);
    for (int i=1;i<=n;++i) {
        scanf("%lld",a+i);
    }
    //for (int i=1;i<=10;++i) printf("%d ",pd(i));
    long long l=0,r=3e15,mid;
    while (l<r) {
        mid=(l+r+1)>>1;
        if (pd(mid)>=k) l=mid;
        else r=mid-1;
    }
    printf("%lld\n",l);
    return 0;
}