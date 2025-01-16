//
// Created by Layn on 24-12-15.
//
#include <cstdio>
#include <cstring>
const int S=100005;
char str[S];
int f[S],n;
inline bool isv(int index) {
    return index<=n && str[index]=='V';
}
inline int mi(int a,int b){return a<b?a:b;}
int main() {
    int T;scanf("%d",&T);
    while (T--) {
        scanf("%s",str+1);
        n=strlen(str+1);
        f[n+1]=0;
        for (int i=n;i;--i) {
            f[i]=f[i+1]+1;
            if (isv(i)) {
                for (int j=i+1;j<=n && j<=i+3 && !isv(j);++j)
                    f[i]=mi(f[i],f[j+1]+1);
            } else {
                if (isv(i+1)) {
                    f[i]=mi(f[i],f[i+2]+1);
                }
                for (int j=i+1;j<=n && j<=i+2 && !isv(j);++j)
                    f[i]=mi(f[i],f[j+1]+1);
            }
        }//puts("c");
        //for (int i=1;i<=n;++i) printf("%d ",f[i]);puts("f");
        int i=1,s=f[1];
        while (i<=n) {
            //printf("%d\n",i);
            if (f[i+1]+1<=s) {
                printf("%d",isv(i)?5:1);
                --s;
                ++i;continue;
            }
            if (isv(i)) {
                for (int j=i+1;j<=n && j<=i+3 && !isv(j);++j)
                    if (f[j+1]+1<=s) {
                        printf("%d",j-i+5);
                        --s;
                        i=j+1;
                        break;
                    }
            } else {
                if (isv(i+1) && f[i+2]+1<=s) {
                    printf("4");
                    --s;
                    i+=2;
                    continue;
                }
                for (int j=i+1;j<=n && j<=i+2 && !isv(j);++j)
                    if (f[j+1]+1<=s) {
                        printf("%d",j-i+1);
                        --s;
                        i=j+1;
                        break;
                    }
            }
        }
        puts("");
    }
    return 0;
}