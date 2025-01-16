//
// Created by Layn on 24-10-16.
//
#include <cstdio>
#include <bitset>
#include <string.h>
using namespace std;
const int S=45003;
const int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
bitset<S> mp,cur;
int n,m;
char str[S];
inline int getid(int i,int j) {
    return (i+n)*(3*m)+j+m;
}
bool vis[S];
void dfs(int x, int y) {
    cur[getid(x,y)]=1;
    vis[getid(x,y)]=true;
    int xx,yy;
    for (int i=0;i<4;++i) {
        xx=x+dx[i];
        yy=y+dy[i];
        if (xx>=0 && xx<n && yy>=0 && yy<m &&
            !mp[getid(xx,yy)] && !cur[getid(xx,yy)]) {
            dfs(xx,yy);
        }
    }
}
bitset<S> tmp;
void getbit(int i,int j,int toi,int toj) {
    tmp=cur;
    if (toi>=i) {
        tmp<<=(toi-i)*3*m;
    } else tmp>>=(i-toi)*3*m;
    if (toj>=j)
        tmp<<=toj-j;
    else tmp>>=j-toj;
}
int main() {
    int T;scanf("%d",&T);
    while (T--) {
        mp.reset();
        memset(vis,false,sizeof(vis));
        scanf("%d%d",&n,&m);
        for (int i=0;i<n;++i) {
            scanf("%s",str);
            for (int j=0;j<m;++j) {
                mp[getid(i,j)]=(str[j]=='.');
            }
        }
        mp = ~mp;
        int res=0;
        for (int i=0;i<n;++i) {
            for (int j=0;j<m;++j)
                if (!vis[getid(i,j)] && !mp[getid(i,j)]) {
                    cur.reset();
                    dfs(i,j);
                    bool flag = true;
                    for (int ii=0;ii<n && flag;++ii)
                        for (int jj=0;jj<m && flag;++jj)
                            if (!cur[getid(ii,jj)] && !mp[getid(ii,jj)]) {
                                getbit(i,j,ii,jj);
                                /*for (int l=0;l<n*3;++l)
                                    for (int k=0;k<m*3;++k)
                                        if (tmp[l*3*m+k])
                                            printf("tmp:%d %d\n",l,k);
                                */if ((mp&tmp).none()) {
                                    flag = false;
                                //printf("%d %d %d %d: %d\n",i,j,ii,jj,(mp&tmp).count());
                                }
                            }
                    if (flag) {
                        res+=cur.count();
                    }
                }
        }
        printf("%d\n",res);
    }
    return 0;
}