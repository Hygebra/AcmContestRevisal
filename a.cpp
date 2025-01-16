#include <cstdio>
int n,a,b;
inline int mi(int a,int b) {return a<b?a:b;}
int main() {
    scanf("%d%d%d",&n,&a,&b);
    for (int i=1;i<n;++i) putchar(a<=n/2?'U':'D');
    for (int i=1;i<n;++i) putchar(b<=n/2?'L':'R');
    for (int i=1;i<mi(a,n-a+1);++i)
        putchar(a<=n/2?'D':'U');
    for (int i=1;i<mi(b,n-b+1);++i)
        putchar(b<=n/2?'R':'L');
    return 0;
}