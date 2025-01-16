//
// Created by Layn on 24-11-13.
//
#include <cstdio>
const int S=1000005;
int n,h[S],nx[S],eg=1,v[S],fa[S],in[S];
inline void egadd(int uu,int vv) {
    nx[++eg]=h[uu];h[uu]=eg;
    v[eg]=vv;++in[uu];
}
int q[S],qq[S];
int main() {
    int T;scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        in[0]=0;
        for (int i=1;i<=n;++i) h[i]=in[i]=0;
        eg=1;
        for (int i=2;i<=n;++i) {
            scanf("%d",fa+i);
            egadd(fa[i],i);
        }
        q[0]=0;
        for (int i=1;i<=n;++i)
            if (!in[i]) q[++q[0]]=i;
        //for (int i=1;i<=q[0];++i) printf("%d ",q[i]);puts("c");
        int su=0,res=1<<30;
        for (int G=0;su<n;++G) {
            //printf("%d\n",su);
            if (res>G+q[0]) res=G+q[0];
            qq[0]=q[0];
            for (int i=1;i<=q[0];++i) {
                qq[i]=q[i];
            }
            su+=q[0];
            q[0]=0;
            for (int i=1;i<=qq[0];++i) {
                if (!--in[fa[q[i]]]) {
                    q[++q[0]]=fa[q[i]];
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}