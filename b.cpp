#include <cstdio>
const int S=100005;
int n;
long long s,a;
bool remain;
int main () {
    scanf("%d",&n);
    s=0;remain = false;
    for (int i=1;i<=n;++i) {
        scanf("%lld",&a);
        if (s&1) remain = true;
        if (s>=0) s=s/2;
        else {
            if (s%2==0) s/=2;
            else s=(s-1)/2;
        }
        s+=a;
        if (s==0 && !remain) putchar('0');
        else if (s==0 && remain) putchar('+');
        else if (s>0) putchar('+');
        else putchar('-');
    }
    return 0;
}
