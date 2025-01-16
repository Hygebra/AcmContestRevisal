#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
const int S=200005;
int n,m,H;
map<int,int> mp,su;
struct node {
    int x,y,op;
}b[S];
inline bool cmp(const node &a,const node &b) {
    if (a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}
inline int getid(long long x,long long y,int dir) {
    x%=2ll*H;
    if (dir>0) return x-y<0?x-y+2ll*H:x-y;
    return x+y>=2ll*H?x+y-2ll*H:x+y;
}
int main() {
    int T;scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&H,&n);
        mp.clear();su.clear();
        for (int i=1;i<=n;++i) {
            scanf("%d%d",&b[i].x,&b[i].y);
            b[i].op = 1;
        }
        scanf("%d",&m);
        for (int i=1;i<=m;++i) {
        //puts("c");
            scanf("%d%d",&b[i+n].x,&b[i+n].y);
            b[i+n].op=0;
        }
        sort(b+1,b+1+n+m,cmp);
        for (int i=n+m,id0,id1,f0,f1,m0,m1,s0,s1;i;--i) {
            id0 = getid(b[i].x,b[i].y,1);
            id1 = getid(b[i].x,b[i].y,-1);
            // printf("%d %d : %d %d\n",b[i].x,b[i].y,id0,id1);
            if (b[i].op) {
                // wood barrier
                m0 = mp[id0]; m1 = mp[id1];
                s0 = su[id0]; s1 = su[id1];
                f0 = m0 + s0;
                f1 = m1 + s1;
                // printf("f0 ,1 = %d %d\n",f0,f1);
                mp[id1] = max(m1, f0 - s1);
                mp[id0] = max(m0, f1 - s0);
            } else {
                //coin
                ++su[id0];
                ++su[id1];
            }
        }
        printf("%d\n",mp[0]+su[0]);
    }
    return 0;
}