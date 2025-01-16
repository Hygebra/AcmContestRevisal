#include <cstdio>
const int S=100004;
int n;
struct node {
    int x,y;
}a[S],st[S],p[S];
int top;
bool compare(node a,node b,node c) {
    int x,y,xx,yy;
    x=b.x-a.x;
    y=b.y-a.y;
    xx=c.x-b.x;
    yy=c.y-b.y;
    return 1ll*xx*y==1ll*yy*x;
}
inline int gcd(int a,int b) {
    if (a==0) return b;
    if (b==0) return a;
    return gcd(b,a%b);
}
int main() {
    int T;scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;++i)
            scanf("%d%d",&a[i].x,&a[i].y);
        if (n<5) {
            puts("NO");
            continue;
        }
        top=2;
        st[1]=a[1];st[2]=a[2];
        for (int i=3;i<=n;++i) {
            if (top<4) {
                if (compare(st[top-1],st[top],a[i])) {
                    st[++top]=a[i];
                }
                else {
                    for (int j=i;j<=n && top<5;++j)
                        st[++top]=a[j];
                    break;
                }
            } else {
                if (!compare(st[top-1],st[top],a[i])) {
                    st[++top]=a[i];
                    break;
                }
            }
        }
        if (top!=5) {
            puts("NO");
        } else {
            puts("YES");
            for (int i=1;i<=top;++i) {
                bool fg = true;
                for (int j=1;j<=5;++j)
                    if (j!=i)
                    for (int k=1;k<=5;++k)
                        if (k!=i && k!=j) {
                            int g;
                            int x=st[j].x-st[i].x,y=st[j].y-st[i].y;
                            int xx=st[k].x-st[i].x,yy=st[k].y-st[i].y;
                            g=gcd(x,y);if (g<0) g=-g;
                            x/=g;y/=g;
                            g=gcd(xx,yy);if (g<0) g=-g;
                            xx/=g;yy/=g;
                            if (x==xx && y==yy) fg=false;
                        }
                if (fg) {
                    printf("%d %d\n",st[i].x,st[i].y);
                    for (int j=1;j<=5;++j)
                        if (j!=i) printf("%d %d\n",st[j].x,st[j].y);
                    break;
                }
            }
        }
    }
    return 0;
}