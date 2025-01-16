#include<bits/stdc++.h>
using namespace std;
const int N=110;
const int inf=(1<<30)-1;
int p,q,ans=INT_MAX,X,Y;
int vis[N][N][2];
struct node {
    int x,y,o;
};
queue<node> pq;
inline bool pd(int x,int y,int o) {
    if (!x && o) return true;
    if(o) {
        if(x+q<y)return false;
    }else if(X-x>0){
        if(X-x+q<Y-y)return false;
    }
    return true;
}
void bfs() {
    pq.push((node){X,Y,0});
    vis[X][Y][0] = 0;
    int xx,yy,oo;
    while (!pq.empty()) {
        auto [x,y,o] = pq.front();
        pq.pop();
        //printf("%d %d %d %d\n",x,y,o,vis[x][y][o]);
        if (!x && o) {
            ans = vis[x][y][o];
            break;
        }
        if(!o) {
            for(int i=0;i<=min(p,x);i++)
                for(int j=0;j<=min(p-i,y);j++) {
                    xx=x-i;yy=y-j;oo=o^1;
                    if (vis[xx][yy][oo]==-1 && pd(xx,yy,oo)) {
                        vis[xx][yy][oo]=vis[x][y][o]+1;
                        pq.push((node){xx,yy,oo});
                    }
                }
        }
        else {
            for(int i=0;i<=min(p,X-x);i++)
                for(int j=0;j<=min(p-i,Y-y);j++) {
                    xx=x+i;yy=y+j;oo=o^1;
                    if (vis[xx][yy][oo]==-1 && pd(xx,yy,oo)) {
                        vis[xx][yy][oo]=vis[x][y][o]+1;
                        pq.push((node){xx,yy,oo});
                    }
                }
        }
    }
}
int main() {
    scanf("%d%d%d%d",&X,&Y,&p,&q);
    //if(X+p+q<Y){printf("-1");return 0;}
    memset(vis,-1,sizeof(vis));
    ans = -1;
    bfs();
    printf("%d",ans);
}