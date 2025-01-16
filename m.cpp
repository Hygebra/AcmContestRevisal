#include <cstdio>
const int S=2002;
int n;
struct node {
    char op;
    int x,y,l,r;
    char ch[3];
}a[S];
int tot;
int main() {
    scanf("%d",&n);
    char op[20];
    while (n--) {
        scanf("%s",op);
        if (op[2] == 'r') {
            // Circle
            //puts("cir");
            ++tot;
            a[tot].op = 'c';
            scanf("%d%d%d%s",&a[tot].x,&a[tot].y,&a[tot].r,a[tot].ch);
        } else if (op[2] == 'c') {
            //Rectangle
            //puts("Rec");
            ++tot;a[tot].op = 'r';
            scanf("%d%d%d%d%s",&a[tot].x,&a[tot].y,&a[tot].l,&a[tot].r,a[tot].ch);
        } else {
            int x,y,l,r;
            scanf("%d%d%d%d",&x,&y,&l,&r);
            for (int j=r;j>=y;--j,puts(""))
                for (int i=x;i<=l;++i){
                    char o = (char)(46);
                    for (int p = 1; p <= tot; ++p) {
                        if (a[p].op == 'c') {
                            if (1ll*(a[p].x-i)*(a[p].x-i) + 1ll*(a[p].y-j)*(a[p].y-j) <= 1ll*a[p].r*a[p].r)
                                o = a[p].ch[0];
                        } else {
                            if (a[p].x<=i && i<=a[p].l && a[p].y<=j && j<=a[p].r) {
                                o = a[p].ch[0];
                            }
                        }
                    }
                    putchar(o);
                }
        }
    }
    return 0;
}