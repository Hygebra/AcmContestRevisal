#include<bits/stdc++.h>
using namespace std;
const int S=100005;
int n,top;
struct node {
    long long l,r;
}a[S];
inline bool cmp(const node &a,const node &b) {
    if (a.l==b.l) return a.r>b.r;
    return a.l<b.l;
}
int main() {
    int T;scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        top=0;
        long long L=LLONG_MAX,R=LLONG_MIN;
        for(int i=1,t,x,k;i<=n;i++) {
            scanf("%d%d%d",&t,&k,&x);
            long long fl = floor((x*2.0-(k-1.0)*k)/(2.0*k));
            long long ce = ceil((x*2.0+(k-1.0)*k)/(2.0*k));
            //printf("ce, fl = %lld %lld\n",ce,fl);
            if (t==1) {
                L=min(L,fl);
                R=max(R,ce);
            } else {
                a[++top] = (node){fl,ce};
            }
        }
        if (L<=0) {puts("0");continue;}
        sort(a+1,a+1+top,cmp);
        int _=0;
        for (int i=1;i<=top;++i) {
            while (_ && a[_].r>=a[i].r) --_;
            a[++_]=a[i];
        }
        top=_;
        if (a[top].l<L) {
            puts("-1");
            continue;
        }
        long long res=0;
        a[0]=(node){0ll,0ll};
        for (int i=1;i<=top;++i) {
            if (a[i].r>R) {
                res+=max(0ll,L-max(0ll,a[i-1].l))*(a[i].r-max(R,a[i-1].r));
            }
            //printf("%lld %lld\n",a[i].l,a[i].r);
        }
        printf("%lld\n",res);
    }
}