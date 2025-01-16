//
// Created by Layn on 24-11-2.
//
#include <cstdio>
#include <cmath>
long long p,q;
long long gcd(long long a,long long b) {
    if (!b) return a;
    return gcd(b,a%b);
}
int main() {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%lld%lld",&p,&q);
        long long g = gcd(p,q);
        p/=g;q/=g;
        p+=2*q;
        long long o = sqrt(p);
        if (o*o!=p && (o+1)*(o+1)!=p) {
            puts("0 0");
            continue;
        }
        if (o*o!=p) ++o;
        //o=a+b;
        //q=ab
        long long delta = sqrt(o*o-4*q);
        if (delta*delta!=o*o-4*q && (delta+1)*(delta+1)!=o*o-4*q) {
            puts("0 0");
            continue;
        }
        if (delta*delta!=o*o-4*q) ++delta;
        if ((o+delta)%2!=0) {
            puts("0 0");
            continue;
        }
        long long a = (o-delta)/2,b=(o+delta)/2;
        if (a<0 || b<0) puts("0 0");
        else printf("%lld %lld\n",a,b);
    }
    return 0;
}