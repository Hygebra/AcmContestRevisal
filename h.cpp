#include <cstdio>
const int S=1000005;
int n,a[S],k,t[S];
int main() {
    int T;scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&k);
        for (int i=1;i<=n;++i) {
            scanf("%d",a+i);
            t[a[i]]++;
        }
        int id=0,s0=k,s1=k;
        for (int i=0;s1 || s0;++i) {
            while (t[id]) ++id;
            if (id&1) {
                if (s1) {
                    --s1;
                    t[id]=1;
                    a[++n]=id;
                }
            }  else {
                if (s0) {
                    --s0;
                    t[id]=1;
                    a[++n]=id;
                }
            }
            ++id;
        }
        id=0;
        while (t[id]) ++id;
        puts((id&1)?"Bob":"Alice");
        //printf("%d\n",id);
        for (int i=1;i<=n;++i) t[a[i]]=0;
    }
    return 0;
}