//
// Created by Layn on 24-12-20.
//
#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int S=5035;
int n,m,sa[S],c[S],x[S],y[S],rk[S],h[S],ST[S][20],i2[S];
long long g[S][S],sg[S][S];
char a[S];
void get_sa() {
    memset(c,0,sizeof(c));
    memset(x,0,sizeof(x));
    memset(y,0,sizeof(y));
    memset(sa,0,sizeof(sa));
    memset(rk,0,sizeof(rk));
    for (int i=1;i<=n;++i) c[x[i]=a[i]]++;
    for (int i=1;i<=m;++i) c[i]+=c[i-1];
    for (int i=n;i>=1;--i) sa[c[x[i]]--]=i;
    for (int o=1;o<=n;o<<=1) {
        int top=0;
        for (int i=n-o+1;i<=n;++i) y[++top]=i;
        for (int i=1;i<=n;++i)
            if (sa[i]>o) y[++top]=sa[i]-o;
        for (int i=1;i<=m;++i) c[i]=0;
        for (int i=1;i<=n;++i) ++c[x[i]];
        for (int i=1;i<=m;++i) c[i]+=c[i-1];
        for (int i=n;i>=1;--i) sa[c[x[y[i]]]--]=y[i];
        for (int i=1;i<=n;++i) y[i]=x[i];
        x[sa[1]]=1;top=1;
        for (int i=1;i<=n;++i)
            x[sa[i]] = (y[sa[i]]!=y[sa[i-1]] || y[sa[i]+o]!=y[sa[i-1]+o])+x[sa[i-1]];
        m=x[sa[n]];
        if (m==n) break;
    }
}
int query_LCS(int L,int R) {
    if (L<1 || L>n || R<1 || R>n) return 0;
    int l = rk[L], r=rk[R];
    if (l>r) swap(l,r);
    return min(ST[l+1][i2[r-l]], ST[r-(1<<i2[r-l])+1][i2[r-l]]);
}
void geth(int n,char a[]) {
    int k=0;
    for (int i=1;i<=n;++i) rk[sa[i]]=i;
    for (int i=1;i<=n;++i) {
        if (rk[i]==1) continue;
        if (k) --k;
        int j=sa[rk[i]-1];
        while (i+k<=n && j+k<=n && a[i+k]==a[j+k]) ++k;
        h[rk[i]]=k;
    }
    for (int i=2;i<=n;++i)
        ST[i][0]=h[i];
    for (int j=1;(1<<j)<=n-1;++j)
        for (int i=2;i+(1<<j)-1<=n;++i)
            ST[i][j]=min(ST[i][j-1],ST[i+(1<<(j-1))][j-1]);
}
int main() {
    i2[1]=0;for (int i=2;i<S;++i) i2[i]=i2[i>>1]+1;
    int T;scanf("%d",&T);
    while (T--) {
        scanf("%s",a+1);
        n=strlen(a+1);
        m=100;//puts("c");
        get_sa();
        geth(n,a);
        // for (int i=1;i<=n;++i) printf("%d ",sa[i]);puts("rk");
        // for (int i=2;i<=n;++i) printf("%d ",h[i]);puts("h");
        for (int i=1;i<=n;++i) {
            g[i][0]=0;
            for (int j=1;j<=i-1;++j) {
                g[i][j]=g[i][j-1] + (query_LCS(i-j,i)>=j);
                sg[i][j]=g[i][j];
            }
            for (int j=1;j<=i-1;++j)
                g[i][j]=g[i][j]+g[i][j-1];
        }
        long long res=0;
        for (int i=2;i<=n;++i) {
            for (int j=i+2;j<=n;++j) {
                int o2= min(min(query_LCS(i,j),n-j+1), j-i-1);
                int o = min(i-1,o2-1);
                //printf(" === %d %d %d\n",i,j,o);
                if (o>0) {
                    res+=g[i][o];
                    res+=sg[i][o]*(o2-o-1);
                     // printf("%d %d %d o2 = %d:%lld\n",i,j,o,o2,g[i][o]);
                }
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}
