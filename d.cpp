#include <cstdio>
#include <algorithm>
using namespace std;
const int S=1000004,lim=1<<19;
const int to[19][6]={
    {-1,1,  4,  3,  -1, -1},// 0
    {-1,2,  5,  4,  0,  -1},// 1
    {-1,-1, 6,  5,  1,  -1},// 2
    {0, 4,  8,  7,  -1, -1},// 3
    {1, 5,  9,  8,  3,  0},// 4
    {2, 6,  10, 9,  4,  1},// 5
    {-1,-1, 11, 10, 5,  2},// 6
    {3, 8,  12, -1, -1, -1},// 7
    {4, 9,  13, 12, 7,  3},// 8
    {5, 10, 14, 13, 8,  4},//9
    {6, 11, 15, 14, 9,  5},//10
    {-1,-1, -1, 15, 10, 6},//11
    {8, 13, 16, -1, -1, 7},//12
    {9, 14, 17, 16, 12, 8},//13
    {10,15, 18, 17, 13, 9},//14
    {11,-1, -1, 18, 14, 10},//15
    {13,17, -1, -1, -1, 12},//16
    {14,18, -1, -1, 16, 13},//17
    {15,-1, -1, -1, 17, 14}//18
};
int n,f[lim],t[23],st[lim+3],id[lim+3];
char str[23];
inline bool cmp(int a,int b) {
    return st[a]<st[b];
}
int main() {
    for (int i=0;i<19;++i) {
        scanf("%d",t+i);
    }
    for (int i=1;i<lim;++i)
        st[i]=st[i-(i&-i)]+1,id[i]=i;
    sort(id,id+lim,cmp);
    for (int ii=0;ii<lim;++ii) {
        int i = id[ii];
        f[i]=0;
        for (int j=0;j<19;++j)
            if ((i>>j)&1) {
                f[i]=max(f[i],f[i^(1<<j)]);
                for (int d=0;d<6;++d) {
                    int o = to[j][d];
                    if (o!=-1 && ((i>>o)&1)) {
                        int p = to[o][d];
                        if (p!=-1 && !((i>>p)&1)) {
                            f[i]=max(f[i],f[i^(1<<j)^(1<<o)^(1<<p)] + t[o]);
                         /*   if (i==((1<<8)|(1<<9)|(1<<14)) && j==8 && d==1) {
                                printf("pd :%d\n",(i^(1<<j)^(1<<o)^(1<<p)) == (1<<10)+(1<<14));
                                printf("%d %d %d  : %d\n",j,o,p,f[i^(1<<j)^(1<<o)^(1<<p)]);
                            }*/
                        }
                    }
                }
            }
    }
    //printf("%d %d\n",f[(1<<10)+(1<<14)],f[(1<<8)|(1<<9)|(1<<14)]);
    scanf("%d",&n);
    while (n--) {
        int x=0,id=0;
        for (int i=0;i<5;++i) {
            scanf("%s",str);
            for (int j=0;str[j];++j)
                x+=(str[j]=='#')<<id,++id;
        }
        printf("%d\n",f[x]);
    }
    return 0;
}