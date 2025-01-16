#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,e,st[N],ST[N];
int ans,tp,tot;
char s[N];
struct Layn {
    int ch[26];
    bool flag;
    int fa;
}t[N];
void insert(int u=0) {
    int len=strlen(s+1);
    for(int i=1;i<=len;i++) {
        int v=s[i]-'a';
        if(!t[u].ch[v])t[u].ch[v]=++tot,t[tot].fa=u;
        u=t[u].ch[v];
    }
    t[u].flag=1;
}
void dfs(int u,int d) {
    ans=max(ans,d);
    st[++tp]=0;
    for(int i=0;i<26;i++) {
        int v=t[u].ch[i];
        if(!t[v].flag)continue;
        bool F=0;
        for(int j=1;j<=tp;j++)if(!t[t[st[j]].ch[i]].flag){F=1;break;}
        if(F)continue;
        for(int j=1;j<=tp;j++)st[j]=t[st[j]].ch[i];
        dfs(v,d+1);
        for(int j=1;j<=tp;j++)st[j]=t[st[j]].fa;
    }tp--;
}
int main() {
    scanf("%d",&n);
    while(n--)scanf("%s",s+1),insert();
    dfs(0,0);
    printf("%d",ans);
}