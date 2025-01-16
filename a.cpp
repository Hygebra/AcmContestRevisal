//
// Created by Layn on 24-10-13.
//
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int S=1003;
int n,a[S],top;
struct node {
    int i,s;
}ans[200000];
vector<int> ve[S];
void dfs(int l,int r, int sum) {
    while (l<=r && ve[l].empty()) {
        if (sum)
            ans[++top]=(node){1,l};
        ++l;
    }
    while (l<=r && ve[r].empty()) --r;
    //printf("%d %d %d\n",l,r,sum);
    if (l==r) {
        return;
    }
    if (l>r) return;
    int mid,s=ve[l].size();
    for (mid=l;s*2<sum;++mid,s+=ve[mid].size());
    if (mid==r) s-=ve[r].size(),--mid;
    for (int i=mid+1;i<=r;++i) {
        for (int o:ve[i]) {
            //printf("%d %d\n",i,o);
            ans[++top]=(node){2,o};
        }
    }
    for (int j=l+1;j<=mid;++j)
        ans[++top]=(node){1,j};
    dfs(mid+1,r,sum-s);
    dfs(l,mid,s);
}
int main() {
    freopen("a.txt","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%d",a+i),ve[a[i]].push_back(i);
    dfs(0,n,n);
    printf("%d\n",top);
    for (int i=1;i<=top;++i)
        printf("%d %d\n",ans[i].i,ans[i].s);
    return 0;
}