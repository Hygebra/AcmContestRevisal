#include<bits/stdc++.h>
using namespace std;
const int N=100,M=10000;
int T,n,a[N][N];
pair<int,int>b[N][N];
bool vis[M];
vector<int>ans;
int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
        int cnt=0;
        ans.clear();
        ans.push_back(a[1][1]);
        for(int m=n*n-1,i=1,j=1;m;m--){
            int x,y;
            if(i&1) {
                if(j<n)x=i,y=j+1;
                else x=i+1,y=j;
            }
            else {
                if(j>1)x=i,y=j-1;
                else x=i+1,y=j;
            }
            ans.push_back(a[x][y]);
            cnt+=(a[i][j]>a[x][y]);
            i=x,j=y;
        }
        if(cnt*2>=n*n-1) {
            for(int i=0;i<ans.size();i++)printf("%d ",ans[i]);
        }
        else {
            for(int i=ans.size()-1;i>=0;i--)printf("%d ",ans[i]);
        }
    }
}