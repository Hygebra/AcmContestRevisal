#include<bits/stdc++.h>
using namespace std;
const int S=100003;
int n,k;
long long c[S],a[S],b[100],d[100];
bool pd(long long mid) {
    for (int i=1;i<=n;++i)
        c[i]=a[i]*mid;
    for (int i=0;i<k;++i)
        d[i]=b[i];
    int id = k-1,done = 0;
    for (int o=52;o>=0;--o) {
    /*    if (mid<=10 && o<=6) {
            for (int i=1;i<=n;++i) printf("%lld ",c[i]);puts("c");
        }*/
        while (id>=0 && !d[id]) --id;
        long long s=0;
        for (int i=1;i<=n;++i)
            if ((c[i]>>o)&1) ++s;
        s<<=o-id;
        while (s>0) {
            if (id<0) return false;
            long long can = min(s, d[id]);
            d[id]-=can;
            s-=can;
            while (id>=0 && !d[id]) {
                --id;
                s<<=1;
            }
            //printf("%lld %d %lld\n",s,id,can);
        }
        if (s==0) {
            for (int i=n;i;--i)
                if (c[i]>>o) {
                    c[i]^=1ll<<o;
                }
            if (id==o) {
                sort(c+1,c+1+n);
                for (int i=n;d[id] && i>=1;--i)
                    if (c[i]) {
                        c[i]=0;
                        --d[id];
                    }
                --id;
            }
        }
    }
    done = 0;
    for (int i=1;i<=n;++i)
        if (!c[i]) ++done;
    return done == n;
}
int main() {
    int T;scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&k);
        long long l=0,r=0,sa=0;
        for(int i=1,x;i<=n;i++) {
            scanf("%lld",&a[i]);
            sa+=a[i];
            /*,a[i].clear();
            for(int j=0;j<30;j++)if((x>>j)&1)a[i].push_back(j);
            */
        }
        sort(a+1,a+1+n);
        for(int i=0;i<k;i++)scanf("%lld",&b[i]),r+=b[i]<<i;
        r=r/sa+10;
        while(l<r) {
            long long mid=(l+r+1)>>1;
            //printf("%lld %lld\n",l,r);
            // for(int i=1;i<=n;i++)for(int j=0;j<a[i].size();j++)
            if (pd(mid)) l=mid;
            else r=mid-1;
        }
        //printf("%d\n",pd(3));
        printf("%lld\n",l);
    }
    return 0;
}