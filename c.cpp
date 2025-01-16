//
// Created by Layn on 24-12-4.
//
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
const int S=2000005,inf=(1<<30)-1;
struct node {
    int x,y;
    inline bool r_x() const {return y==0 && x<0;}
    // double len() {return sqrt(x*x+y*y);}
}a[S];
int n;
inline long long cross(const node &a,const node &b) {
    return a.x*1ll*b.y-a.y*1ll*b.x;
}
inline bool cmp(const node &a,const node &b) {
    //return a.x<b.x;
    if (a.y==0 && a.x<0) {
        if (b.y==0 && b.x<0) {
            return a.x<b.x;
        }
        return true;
    }
    if (a.y<=0) {
        if (b.y>0) return true;
        return a.x*1ll*b.y>a.y*1ll*b.x;
    }
    if (b.y<=0) return false;
    return a.x*1ll*b.y>a.y*1ll*b.x;
}
inline long long dot(node a, node b) {
    return a.x*1ll*b.x+a.y*1ll*b.y;
}
inline bool same(node a,node b) {
    return cross(a,b)==0 && dot(a,b)>0;
}
void read(int &s) {
    s=0;char c=getchar(),t=0;
    while (c!='-' && (c<'0' || c>'9')) c=getchar();
    if (c=='-') t=-1,c=getchar();
    while (c>='0' && c<='9') s=(s<<1)+(s<<3)+(c^48),c=getchar();
    if (t) s=-s;
}
FILE *out;
int main() {
    //freopen("data.txt","r",stdin);
    srand(time(NULL));
    int T = 1;scanf("%d",&T);
    //int st = clock();
    while (T--) {
        read(n);
        //n = 500000;
    //    out=fopen("data.txt", "w");
    //    fprintf(out, "%d\n",n);
        int xx,yy;
        for (int i=1;i<=n;++i) {
            read(xx);read(yy);
            // xx = 1ll * rand() * rand() % 1000000000;
            // yy = 1ll * rand() * rand() % 1000000000;
            // if (rand() & 1) xx = -xx;
            // if (rand() & 1) yy = -yy;
            // if (xx == 0 && yy == 0) xx++;
    //        fprintf(out,"%d %d\n",xx,yy);
            a[i].x=xx;a[i].y=yy;
        }
     //   fclose(out);
        sort(a+1,a+1+n,cmp);//puts("c");
        for (int i=1;i<=n;++i)
            a[i+n]=a[i];
        int id=1;
        int ans = n;
        for (int i=1;i<=n;++i) {
            if (id<i) id = i;
            while (id+1-i+1<=n && cross(a[i],a[id+1])>=0) ++id;
            //printf("%d %d\n",i,id);
            if (same(a[id],a[i])) {
                ans = 0;
            }
            ans = min(ans, n-(id-i+1));
            while (i<n && same(a[i+1],a[i]))
                ++i;
        }
        printf("%d\n",ans);
    }
    // printf("%d\n", clock() - st);
    return 0;
}
// 3
// 2
// 1 0
// 2 0
// 3
// 1 0
// 0 1 -1 -1
// 5
// 2 -1
// 1 2 -1 2 -2 -1
// 0 -2
