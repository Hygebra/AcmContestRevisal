#include <cstdio>
const int S=2000002;
int n,f[S],su,l2;
long long x;
inline long long gcd(long long a,long long b) {
    if (a==0) return b;
    if (b==0) return a;
    return gcd(b,a%b);
}
long long cal(long long x) {
    if (!x) return 0;
    return (x/l2) * f[l2] + f[x&(l2-1)];
}
int main() {
    scanf("%lld%d",&x,&n);
    l2=1;
    while (l2<=x) l2<<=1;
    for (int i=1;i<=l2;++i) {
        f[i]=f[i-1] + (1==gcd((i*x)^x,x));
    }
    long long l,r;
    while (n--) {
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",cal(r)-cal(l-1));
    }
    return 0;
}