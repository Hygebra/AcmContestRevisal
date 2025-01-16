#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
int n,T,cnt,p[N],k[N];
char a[N],b[N];
bitset<100005>ans,res,E0,E1,tmp,E;
vector<int>t1[N],t2[N],t[N];
void init() {
    cnt=0,ans=E;
    for(int i=0;i<=n+1;i++)t1[i].clear(),t2[i].clear(),t[i].clear();
    for(int i=0;i<=n*2;i++)E1[i]=1,E0[i]=0;
    for(int i=0;i<n;i++)E0[i]=1,E1[i]=0,ans[i]=1;
}
int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        scanf("%s%s",a+1,b+1);
        init();
        for(int i=1;i<=n;i++)p[i]=p[i-1]+a[i]-'0',k[++cnt]=2*p[i]-i;
        k[++cnt]=0;
        sort(k+1,k+cnt+1),cnt=unique(k+1,k+cnt+1)-k-1;
        for(int i=0,x;i<=n;i++) {
            x=lower_bound(k+1,k+cnt+1,2*p[i]-i)-k;
            t[x].push_back(i);
            if(!i)continue;
            if(b[i]=='1')t1[x].push_back(i);
            else t2[x].push_back(i);
        }
        res=E;
        for(int i=1;i<=cnt;i++) {
            for(auto j:t1[i]) {
                tmp=res;
                if(2*p[j]-j>0)tmp|=E0;
                else tmp&=E1;
                tmp>>=j;
                // printf("%d: ",j);
                // for(int I=0;I<=n*2;I++)cout<<tmp[I];puts("");
                ans&=tmp;
            }
            for(auto j:t[i])res[j+n]=1;
        }
        res=E;
        for(int i=cnt;i>=1;i--) {
            for(auto j:t[i])res[j+n]=1;
            for(auto j:t2[i]) {
                tmp=res;
                if(2*p[j]-j<=0)tmp|=E0;
                else tmp&=E1;
                tmp>>=j;
                ans&=tmp;
                // printf("%d: ",j);
                // for(int I=0;I<=n*2;I++)cout<<tmp[I];puts("");
            }
        }
        for(int i=n-1;i>=0;i--)cout<<ans[i];puts("");
    }
}
// 100
// 5
// 01010
// 01010