#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
const int N=1010;
int T,a,b,cnt;
struct pr{int p,w;}t[N];
map<pair<int,int>,int>f;
int dfs(int x,int y) {
    if(x==1)return 0;
    if(f[mp(x,y)])return f[mp(x,y)];
    int res=x-1;
    for(int i=1;i<=cnt;i++)if(y%t[i].p==0) {
        int z=t[i].p;
        if(x>=z)res=min(res,dfs(x/z,y/z)+1+x%z);
        res=min(res,dfs(x/z+1,y/z)+1+z-x%z);
    }return f[mp(x,y)]=res;
}
int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&a,&b);
        if(a>b)swap(a,b);
        int c=b-a;cnt=0;
        for(int i=2;i<=sqrt(c);i++)if(c%i==0) {
            ++cnt,t[cnt].p=i,t[cnt].w=0;
            while(!(c%i))t[cnt].w++,c/=i;
        }if(c>1)++cnt,t[cnt].p=c,t[cnt].w=1;
        f.clear(),printf("%d\n",dfs(a,b-a));
    }
}