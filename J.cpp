#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,in[N];
int main() {
    scanf("%d",&n);
    for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),in[u]++,in[v]++;
    int cnt=0;
    for(int i=1;i<=n;i++)if(in[i]>1)cnt++;
    if(cnt==0 || (cnt&1))printf("Bob");
    else printf("Alice");
}