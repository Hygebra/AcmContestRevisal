#include <cstdio>
#include <algorithm>
using namespace std;
const int S=100005;
int n,a[S],p[S],b[S],st[S];
int main() {
    int T;scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;++i)
            scanf("%d",&a[i]),p[a[i]]=i;
        for (int i=1;i<=n;++i) {
            scanf("%d",b+i);
            a[p[b[i]]]=i;
        }
        //for (int i=1;i<=n;++i) printf("%d ",a[i]);puts("a");
        int tot=0;
        int fr = 1;
        if (a[n]!=n) {
            while (a[fr]!=n) putchar('1'),fr=fr%n+1;
            putchar('1');fr=fr%n+1;
        }//putchar('c');
        for (int i=n-1;i>=1;--i) {
            bool fg = true;
            for (int j=fr;j%n+1!=fr && fg;j=j%n+1)
                if (a[j]>a[j%n+1])
                    fg = false;
            if (fg) break;
            for (int j=1;j<=i;++j)
                if (a[fr]>a[fr%n+1]) {
                    putchar('2');
                    swap(a[fr],a[fr%n+1]);
                    fr=fr%n+1;
                } else {
                    putchar('1');
                    fr=fr%n+1;
                }
            for (int j=i+1;j<=n;++j)
                putchar('1'),fr=fr%n+1;
        }
        while (a[fr]!=1) putchar('1'),fr=fr%n+1;
        puts("");
    }
    return 0;
}